#ifndef _DTI_H__
#define _DTI_H__

#ifndef __PACKED__
/** Packed definition */
#	define __PACKED__			__attribute__ ((packed))
#endif

/** DTI packet - magic key */
#define DTI_MAGIC				0xdeadbeef

/* Packet Group: 0x0000xxxx - Control Level Access */
#define DTI_GROUP_CONTROL_ACCESS		0x00000000
/** Packet Group: 0x0001xxxx - Low Level HW Access */
#define DTI_GROUP_LOW_LEVEL_HW_ACCESS		0x00010000
/* Packet Group: 0x0002xxxx - Control and Message Interface */
#define DTI_GROUP_CNTRL_MSG_ACCESS		0x00020000
/* Packet Group: 0x0003xxxx - Trace Buffer Access */
#define DTI_GROUP_TRACE_BUFFER_ACCESS		0x00030000
/* Packet Group: 0x0004xxxx - Debug Register Access */
#define DTI_GROUP_DEBUG_REG_ACCESS		0x00040000
/* Packet Group: 0x0005xxxx - Command Line Interface (CLI) */
#define DTI_GROUP_CLI_ACCESS			0x00050000
/* Packet Group: 0x0006xxxx -  */
#define DTI_GROUP_WINEASY_ACCESS		0x00060000

/** Packet Type: 0x0000xxxx - Control Level Access */
typedef enum
{
	/** Error Packet Type */
	DTI_PacketType_eError			= 0x00000001,
	/** Loopback Packet */
	DTI_PacketType_eLoopback		= 0x00000002,
	/** System Information Retrieval */
	DTI_PacketType_eSytemInfo		= 0x00000003,
	/** Prepare Binary Load */
	DTI_PacketType_eImageLoadStart		= 0x00000010,
	/** Send Image Chunk */
	DTI_PacketType_eImageLoadChunk		= 0x00000011
} DTI_PacketType_t;

/** Possible device packet types */
typedef enum {
	/* Packet Type: 0x0001xxxx - Low Level HW Access */
	/** Device Reset */
	DTI_PacketType_eDeviceReset		= 0x00010001,
	/** Device Download */
	DTI_PacketType_eDeviceDownload		= 0x00010002,

	/** Device Open */
	DTI_PacketType_eDeviceOpen		= 0x00010003,
	/** Device Close */
	DTI_PacketType_eDeviceClose		= 0x00010004,

	/** Lock / Unlock Device */
	DTI_PacketType_eRegisterLock		= 0x00010020,
	/** Read Device Register */
	DTI_PacketType_eRegisterGet		= 0x00010021,
	/** Write Device Register */
	DTI_PacketType_eRegisterSet		= 0x00010022,

	/* Packet Type: 0x0002xxxx - Control and Message Interface */
	/** Set Configuration Option */
	DTI_PacketType_eConfigSet		= 0x00020001,
	/** Get Configuration Option */
	DTI_PacketType_eConfigGet		= 0x00020002,
	/** Message Send / Message Receive  */
	DTI_PacketType_eMessageSend		= 0x00020003,
	/** Message Error */
	DTI_PacketType_eMessageError		= 0x00020004,

	/* Packet Type: 0x0003xxxx - Trace Buffer Access */
	/** Configure Trace Buffer */
	DTI_PacketType_eTraceBufferConfigSet	= 0x00030001,
	/** Reset Trace Buffer */
	DTI_PacketType_eTraceBufferReset	= 0x00030002,
	/** Get Trace Buffer Status */
	DTI_PacketType_eTraceBufferStatusGet	= 0x00030003,
	/** Trace Buffer Read */
	DTI_PacketType_eTraceBufferGet		= 0x00030004,
	/** Trace Buffer Notification */
	DTI_PacketType_eTraceBufferAvailable	= 0x00030005,

	/* Packet Type: 0x0004xxxx - Debug Register Access */
	/** Debug Read Access */
	DTI_PacketType_eDebugGet		= 0x00040001,
	/** Debug Write Access */
	DTI_PacketType_eDebugSet		= 0x00040002,

	/* Packet Type: 0x0006xxxx - WinEasy Access */
	/** WinEasy C/I Access */
	DTI_PacketType_eWinEasyCiAccess		= 0x00060001
} DTI_PacketTypeDevice_t;

/** Possible payload data types */
typedef enum
{
	/** payload data is of mixed data*/
	DTI_eMixed				= 0,
	/** payload data is 8 bit type */
	DTI_e8Bit				= 1,
	/** payload data is 16 bit type */
	DTI_e16Bit				= 2,
	/** payload data is 32 bit type */
	DTI_e32Bit				= 3
} DTI_PayloadType_t;

/** Possible packet error codes */
typedef enum
{
	/* no error */
	DTI_eNoError				= 0,
	/** packet type is unknown or not supported */
	DTI_eErrUnknown				= 1,
	/** some non DTI API related network error */
	DTI_eErrNetwork				= 2,
	/** response was not seen within max pending time */
	DTI_eErrTimeout				= 3,
	/** unknown mailbox message */
	DTI_eErrUnknownMsg			= 4,
	/** Packet is in incorrect format */
	DTI_eErrMalformedPacket,
	/** Packet is in incorrect format */
	DTI_eErrInvalidParameters,
	/** Packet type is not known or supported */
	DTI_eErrInvalidPacketType,
	/** Payload size is not supported */
	DTI_eErrInvalidPayloadSize,
	/** invalid / inclomplete configuration */
	DTI_eErrConfiguration,
	/** port / device / interface num out of range */
	DTI_eErrPortOutOfRange,
	/** port / interface open error */
	DTI_eErrPortOpen,
	/** port / device / interface operation error */
	DTI_eErrPortOperation,
	/** Autonomous port / device / interface operation error */
	DTI_eErrPortAutoOperation,
	/** unknown / not configured device interface */
	DTI_eErrDeviceTypeOutOfRange
} DTI_PacketError_t;

/** The DTI paket header structure.  */
typedef struct {
	/** A constant value of 0xdeadbeef used for resynchronization and
	 * debugging */
	uint32_t magic;
	/** The protocol packet type. The upper 16 bits are used to select a
	 * functional group (e.g. host interface, debug interface, host
	 * controller).
	 * The lower 16 bits are the command itself.(Definitions see
	 * DTI_PacketType_t) */
	uint32_t packetType;
	/** The packet options. The upper 24 bits are currently reserved and
	 * should be set to zero.
	 * The lower 8 bits identify the payload type. The payload type is the
	 * bit size of the payload items.
	 * 0 = Mixed, 1 = 8 bit,  2 = 16bit, 3 = 32 bit. (Definitions see
	 * DTI_PayloadType_t) */
	uint32_t packetOptions;
	/** The port / channel number. If a packet is channel independent this
	 * value will be ignored. */
	uint32_t port;
	/** The transaction number.
	 * This must be an auto-incrementing non zero number. The packet to
	 * acknowledge the initiating message will use the same number. The
	 * value 0 is reserved for autonomous / asynchronous messages.
	 * On the device side the Tan is simply copied into the acknowledging
	 * packet. No check for proper incrementing is performed. Even a Tan of
	 * zero will just be mirrored, but no error condition is generated. */
	uint32_t tan;
	/** This field contains the error code. In case the packet
	 * type/direction does not have an error code the field is reserved and
	 * has to be set to zero. An error code of zero means success. */
	uint32_t error;
	/** The payload size in number of bytes. */
	uint32_t payloadSize;
} __PACKED__ DTI_PacketHeader_t;

/** The DTI paket definition */
typedef struct {
	/** paket header */
	DTI_PacketHeader_t header;
	/** payload */
	uint8_t  payload[1];
} __PACKED__ DTI_Packet_t;


/** Image load - transfer an binary form the host (PC) to the target system.
 *
 * The host informs the target about the file size and identifier. */
typedef struct {
	/** Identify the image for later use */
	uint32_t imageNum;
	/** Size of the image to download in number of bytes */
	uint32_t imageSize;
} __PACKED__ DTI_H2D_ImageLoadStart_t;

/** Image load - transfer an binary form the host (PC) to the target system.
 *
 * The target response to a previous \ref  DTI_H2D_ImageLoadStart_t command
 * with the max binary chunk size which can be processed. */
typedef struct {
	/** Maximum size in number of bytes for image chunks to send */
	uint32_t maxChunkSize;
} __PACKED__ DTI_D2H_ImageLoadStart_t;

/** Image load - Data Chunk Download.
 *
 * Packet type: \ref  DTI_PacketType_eImageLoadChunk .
 *
 * With this packet the image is send in chunks to the board. This ensures a
 * response in a certain amount of time even with a slow connection.
 * The host side can suggest a maximum number of bytes which are transferred
 * in one packet, the target should accept this size.
 * But the PC side can even send less than that per packet.
 *
 * \remarks The implementation on the board has to check whether the written
 * data fits to the allocated image size. A error indication should be
 * generated otherwise. */
typedef struct {
	/** The byte offset into the image of this chunk. */
	uint32_t offset;
	/** Size in number of bytes for this chunk. */
	uint32_t chunkSize;
	/** Data chunk */
	uint8_t  data[1];
} __PACKED__ DTI_H2D_ImageLoadChunk_t;

/** Device Download Command - performs a download on the selected devices with
 * the selected and previous provided image.  */
typedef struct {
	/** Identify the image used for this download command */
	uint32_t imageNum;
	/** The download type. Could be eFirmware(=0), eCache(=1) */
	uint32_t mode;

	/** Bitmask to reset devices before the firmware is loaded.
	*  Will be ignored if not supported by target device.
	*  A one selects a device. The first device (0) is located in the LSB. */
	uint32_t resetMask;

	/** Bitmask to select devices for image load. A one selects a device.
	*  The first device (0) is located in the LSB. */
	uint32_t loadMask;
} __PACKED__ DTI_H2D_DeviceDownload_t;

/** Device Download Command - informs the host about a failed download operation
 * per device.  */
typedef struct {
	/** Bitmask with a one for every device which failed in the download
	* procedure.  The first device (=0) is located in the LSB. */
	uint32_t errorMask;
} __PACKED__ DTI_D2H_DeviceDownload_t;

/** Start DTI handing */
void DtiStart (void);

#endif
