/*
 * Lantiq UDP DTI agent
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#include <common.h>
#include <watchdog.h>
#include <command.h>
#include <net.h>
#include <dti.h>

#include <version.h>

#if defined(CONFIG_CMD_DTI)

#if 1
#	undef debug
#	define debug(fmt, args...) printf(fmt, ##args)
#else
#	undef debug
#	define debug(fmt, args...) do { } while (0)
#endif

/** Maximum DTI FW size in bytes */
/** TODO define real maximum allowed FW size */
#define DTI_FW_SIZE_MAX				(4096 * 1024)

/** Used DTI port */
static int dti_port = 9000;

/** FW image */
static uint8_t dti_fw[DTI_FW_SIZE_MAX];

/** FW size */
static uint32_t dti_fw_size;

/** FW id */
static uint32_t dti_fw_id;

/** FW is valid (loaded with valid data) */
static int dti_fw_valid = 0;

/** Milliseconds to timeout for lost packet */
#define TIMEOUT					1000

/** DTI state */
static enum {
	/** Default state */
	DTI_STATE_DEFAULT,
	/** FW download state */
	DTI_STATE_FW
} dti_state = DTI_STATE_DEFAULT;

/** Generate empty DTI packet with error
 *
 * \param[in] pkt Output packet
 *
 * \return Payload size of output packet (always 0)
 */
static inline unsigned int DtiErrorPacket(DTI_Packet_t *pkt)
{
	pkt->header.error = DTI_eErrUnknown;
	pkt->header.payloadSize = 0;
	return pkt->header.payloadSize;
}

/** Handle "CLI" DTI packet
 *
 * \param[in,out] Input & output packet
 *
 * \return Payload size of output packet
 */
static inline unsigned int DtiCli(DTI_Packet_t *in, DTI_Packet_t *out)
{
	dti_state = DTI_STATE_DEFAULT;

	if (in->header.payloadSize < 4)
		return DtiErrorPacket(out);

	if (in->payload[0] == 'v'
		&& in->payload[1] == 'i'
		&& in->payload[2] == 'g') {
		/* respond with version information */

		strcpy((char *)out->payload,
				"nReturn=0 version=\"DTI " U_BOOT_VERSION "\"");
	} else if (in->payload[0] == 'l'
		&& in->payload[1] == 's'
		&& in->payload[2] == 'g') {
		/* make empty lsg response (required by the SysMon) */

		strcpy((char *)out->payload, "nReturn=0");
	} else {
		debug("Received unsupported CLI request\n");
		return DtiErrorPacket(out);
	}

	out->header.error = DTI_eNoError;
	out->header.payloadSize = strlen((char *)out->payload) + 1;
	return out->header.payloadSize;
}

/** Handle "Firmware download start" DTI packet
 *
 * \param[in,out] Input & output packet
 *
 * \return Payload size of output packet
 */
static inline unsigned int DtiFwStart(DTI_Packet_t *in, DTI_Packet_t *out)
{
	DTI_H2D_ImageLoadStart_t *recv =
		(DTI_H2D_ImageLoadStart_t *)in->payload;
	DTI_D2H_ImageLoadStart_t *send =
		(DTI_D2H_ImageLoadStart_t *)out->payload;

	if (recv->imageSize > DTI_FW_SIZE_MAX) {
		debug("Received load FW request with size %u, but maximum "
			"allowed size is %u\n", recv->imageSize,
			DTI_FW_SIZE_MAX);
		return DtiErrorPacket(out);
	}

	dti_state = DTI_STATE_FW;

	dti_fw_id = recv->imageNum;
	dti_fw_size = recv->imageSize;
	dti_fw_valid = 0;

	/* TODO check maximum allowed chunk size */
	send->maxChunkSize = 0xffff;

	debug("Received FW download request; FW id=%u, FW size=%u FW max "
			"chunk=%u\n", dti_fw_id, dti_fw_size, DTI_FW_SIZE_MAX);

	out->header.error = DTI_eNoError;
	out->header.payloadSize = sizeof(*send);
	return out->header.payloadSize;
}

/** Handle "Firmware download chunk" DTI packet
 *
 * \param[in,out] Input & output packet
 *
 * \return Payload size of output packet
 */
static inline unsigned int DtiFwChunk(DTI_Packet_t *in, DTI_Packet_t *out)
{
	DTI_H2D_ImageLoadChunk_t *chunk =
		(DTI_H2D_ImageLoadChunk_t *)in->payload;

	if (dti_state != DTI_STATE_FW)
		return DtiErrorPacket(out);

	if (chunk->offset + chunk->chunkSize > dti_fw_size) {
		debug("Received chunk with invalid offset=%u and/or size=%u\n",
				chunk->offset, chunk->chunkSize);
		return DtiErrorPacket(out);
	}

	memcpy(dti_fw + chunk->offset, chunk->data, chunk->chunkSize);

	if (chunk->offset + chunk->chunkSize == dti_fw_size) {
		dti_state = DTI_STATE_DEFAULT;
		debug("Received FW image #%u\n", dti_fw_id);
		dti_fw_valid = 1;
	}

	debug("chunk offset=%u size=%u\n", chunk->offset, chunk->chunkSize);

	out->header.error = DTI_eNoError;
	out->header.payloadSize = 0;
	return out->header.payloadSize;
}

/** Handle "Device download" DTI packet
 *
 * \param[in,out] Input & output packet
 *
 * \return Payload size of output packet
 */
static inline unsigned int DtiFwStore(DTI_Packet_t *in, DTI_Packet_t *out)
{
	DTI_H2D_DeviceDownload_t *recv =
		(DTI_H2D_DeviceDownload_t *)in->payload;
	DTI_D2H_DeviceDownload_t *send =
		(DTI_D2H_DeviceDownload_t *)out->payload;

	if (!dti_fw_valid)
		return DtiErrorPacket(out);

	if (recv->imageNum != dti_fw_id) {
		send->errorMask = recv->loadMask;

		out->header.error = DTI_eNoError;
		out->header.payloadSize = sizeof(*send);
		return out->header.payloadSize;
	}

	debug("Trying to store FW image #%u...\n", dti_fw_id);

	/** TODO */

	debug("Successfully stored FW image\n");

	send->errorMask = 0;

	out->header.error = DTI_eNoError;
	out->header.payloadSize = sizeof(*send);
	return out->header.payloadSize;
}

/** Main DTI packet handler
 *
 * \param[in,out] Input & output packet
 *
 * \return Payload size of output packet
 */
static inline unsigned int DtiPacketHandle(DTI_Packet_t *in, DTI_Packet_t *out)
{
	uint32_t group;

	if (in->header.magic != DTI_MAGIC) {
		debug("Received DTI packet with bad magic number\n");
		return 0;
	}

	group = in->header.packetType & 0xffff0000;

#if 0
	{
		int i;

		debug("\nIncoming DTI packet:\n");
		debug("\tmagic\t= 0x%x\n", in->header.magic);
		debug("\tgroup\t= 0x%x\n", group);
		debug("\ttype\t= 0x%x\n", in->header.packetType);
		debug("\topts\t= 0x%x\n", in->header.packetOptions);
		debug("\tport\t= 0x%x\n", in->header.port);
		debug("\ttan\t= 0x%x\n", in->header.tan);
		debug("\terror\t= 0x%x\n", in->header.error);
		debug("\tsize\t= 0x%x\n", in->header.payloadSize);

		debug("\tdata\t= ");
		for (i = 0; i < in->header.payloadSize; i++) {
			debug("%02x ", in->payload[i]);
		}

		debug("\n");
	}
#endif

	if (in != out)
		memcpy(out, in, sizeof(DTI_PacketHeader_t));

	if (group == DTI_GROUP_CLI_ACCESS) {
		return DtiCli(in, out);
	} else {
		switch (in->header.packetType) {
			case DTI_PacketType_eImageLoadChunk:
				return DtiFwChunk(in, out);

			case DTI_PacketType_eImageLoadStart:
				return DtiFwStart(in, out);

			case DTI_PacketType_eDeviceDownload:
				return DtiFwStore(in, out);

			default:
				return DtiErrorPacket(out);
		}
	}
}

static void DtiTimeout(void)
{
	puts(".");
	NetSetTimeout(TIMEOUT, DtiTimeout);
}

static void DtiHandler(uchar *pkt, unsigned dest, unsigned src, unsigned len)
{
	static uchar client_ether[6];
	IP_t *ip = (IP_t *)(NetRxPacket + ETHER_HDR_SIZE);

	if (dest != dti_port)
		return;

	len = DtiPacketHandle((DTI_Packet_t *)pkt, (DTI_Packet_t *)(NetTxPacket
			+ NetEthHdrSize() + IP_HDR_SIZE));

	memcpy(client_ether, ((Ethernet_t *)NetRxPacket)->et_src, 6);
	NetSendUDPPacket(client_ether, NetReadIP(&ip->ip_src), src, dti_port,
			sizeof(DTI_PacketHeader_t) + len);
}

void DtiStart(void)
{
	printf("Lantiq UDP DTI agent; our address is %pI4:%u\n",
			&NetOurIP, dti_port);

	NetSetHandler(DtiHandler);
	NetSetTimeout(TIMEOUT, DtiTimeout);
}

#endif
