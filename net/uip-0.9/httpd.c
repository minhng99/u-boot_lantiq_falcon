#include "uip.h"
#include "httpd.h"
#include "fs.h"
#include "fsdata.h"
#include <asm/addrspace.h>

#define HTTP_NONE		0
#define HTTP_FILE		1
#define HTTP_FIRMWARE		2

#define PRINT(x) printf("%s", x)
#define PRINTLN(x) printf("%s\n", x)

extern unsigned long do_http_tmp_address(void);

struct httpd_state *hs;

extern const struct fsdata_file file_index_html;
extern const struct fsdata_file file_404_html;
extern const struct fsdata_file file_flash_html;
extern int httpd_upload_complete;
extern unsigned char *httpd_upload_data;
unsigned char *upload_data;
extern ulong		NetBootFileXferSize;
int upload_running = 0;

#define ISO_G        0x47
#define ISO_E        0x45
#define ISO_T        0x54
#define ISO_P        0x50
#define ISO_O        0x4f
#define ISO_S        0x53
#define ISO_T        0x54
#define ISO_slash    0x2f
#define ISO_c        0x63
#define ISO_g        0x67
#define ISO_i        0x69
#define ISO_space    0x20
#define ISO_nl       0x0a
#define ISO_cr       0x0d
#define ISO_a        0x61
#define ISO_t        0x74
#define ISO_hash     0x23
#define ISO_period   0x2e

static char eol[3] = { 0x0d, 0x0a, 0x00 };
static char eol2[5] = { 0x0d, 0x0a, 0x0d, 0x0a, 0x00 };
static char boundary[128];
static int boundary_len = 0;

/* we use this so that we can do without the ctype library */
#define is_digit(c)	((c) >= '0' && (c) <= '9')
static int atoi(const char *s)
{
	int i=0;

	while (is_digit(*s))
		i = i*10 + *(s++) - '0';
	return i;
}

void
httpd_init(void)
{
	fs_init();
	uip_listen(HTONS(80));
}

void
httpd_appcall(void)
{
	struct fs_file fsfile;
	u8_t i;
	switch(uip_conn->lport) {
	case HTONS(80):
		hs = (struct httpd_state *)(uip_conn->appstate);
		if(uip_connected())
		{
			hs->state = HTTP_NONE;
			hs->count = 0;
			return;
		} else if(uip_poll())
		{
			if(hs->count++ >= 1000) {
				uip_abort();
			}
			return;
		} else if(uip_newdata() && hs->state == HTTP_NONE)
		{
			if(uip_appdata[0] == ISO_G &&
				uip_appdata[1] == ISO_E &&
				uip_appdata[2] == ISO_T &&
				uip_appdata[3] == ISO_space)
			{
				hs->state = HTTP_FILE;
			}
			if(uip_appdata[0] == ISO_P &&
				uip_appdata[1] == ISO_O &&
				uip_appdata[2] == ISO_S &&
				uip_appdata[3] == ISO_T &&
				uip_appdata[4] == ISO_space)
			{
				hs->state = HTTP_FIRMWARE;
			}
			if(hs->state == HTTP_NONE)
			{
				uip_abort();
				return;
			}
			if(hs->state == HTTP_FILE)
			{
				for(i = 4; i < 40; ++i)
				{
					if(uip_appdata[i] == ISO_space ||
						uip_appdata[i] == ISO_cr ||
						uip_appdata[i] == ISO_nl)
					{
						uip_appdata[i] = 0;
						break;
					}
				}

				PRINT("request for file ");
				PRINTLN(&uip_appdata[4]);
				if(uip_appdata[4] == ISO_slash &&
					uip_appdata[5] == 0)
				{
					fs_open(file_index_html.name, &fsfile);
				} else {
					if(!fs_open((const char *)&uip_appdata[4], &fsfile))
					{
						PRINTLN("couldn't open file");
						fs_open(file_404_html.name, &fsfile);
					}
				}
				hs->script = 0;
				hs->state = HTTP_FILE;
				hs->dataptr = fsfile.data;
				hs->count = fsfile.len;
			}
			if(hs->state == HTTP_FIRMWARE)
			{
				unsigned char *start = (unsigned char*)uip_appdata;
				char *clen = strstr((char *)start, "Content-Length:");
				int len = 0;
				unsigned char *next, *end;
				unsigned char *boundary_start;
				int i;
				uip_appdata[uip_len] = '\0';
				if(clen)
				{
					clen += sizeof("Content-Length:");
					next = (unsigned char *)strstr(clen, eol);
					if(next)
					{
						len = atoi(clen);
						next++;
						printf("expecting %d bytes\n", len);
						upload_data = httpd_upload_data = (unsigned char *)do_http_tmp_address();
						printf("received data will be stored at %p\n", upload_data);
						if(!upload_data)
						{
							printf("failed to allocate memory\n");
							uip_close();
							return;
						}
					} else {
						uip_close();
						return;
					}
				}
				if(len < 4 * 1024)
				{
					uip_close();
					return;
				}
				boundary_start = (unsigned char *)strstr((char *)next, "---");
				if(!boundary_start)
				{
					uip_close();
					return;
				}
				end = (unsigned char *)strstr((char *)boundary_start, eol);
				if(!end)
				{
					uip_close();
					return;
				}
				boundary_len = end - boundary_start;
				memcpy(boundary, boundary_start, boundary_len);
				boundary[boundary_len] = 0;
				next = (unsigned char *)strstr((char *)boundary_start, "name=\"firmware\";");
				if(!next)
				{
					uip_close();
					return;
				}
				next = (unsigned char *)strstr((char *)next, eol2);
				if(!next)
				{
					printf("could not find start of data\n");
					uip_close();
					return;
				}
				next += 4;
				hs->script = 0;
				hs->state = HTTP_FIRMWARE;
				hs->upload = uip_len - (next - start);
				hs->upload_total = len - (int)(next - boundary_start);
				hs->upload_total -= (strlen(boundary) + 6);
				//printf("storing %d bytes at %p\n", (int)hs->upload, upload_data);
				for(i = 0; i < hs->upload; i++)
					upload_data[i] = next[i];
				upload_data += (int)hs->upload;
				debug("%d / %d\n", (int)hs->upload, hs->upload_total);
				uip_slen = 0;
				return;
			}
		}

		if(hs->state == HTTP_FIRMWARE)
		{
			if(uip_newdata())
			{
				int i;
				hs->count = 0;
				uip_appdata[uip_len] = '\0';
				hs->upload += uip_len;
				//printf("storing %d bytes at %p\n", uip_len, upload_data);
				debug("%d / %d\n", (int)hs->upload, hs->upload_total);
				for(i = 0; i < uip_len; i++)
					upload_data[i] = uip_appdata[i];
				upload_data += uip_len;
				uip_slen = 0;
				if(hs->upload >= hs->upload_total)
				{
					upload_running = 1;
					NetBootFileXferSize = hs->upload_total;
					fs_open(file_flash_html.name, &fsfile);
					hs->script = 0;
					hs->state = HTTP_FILE;
					hs->dataptr = fsfile.data;
					hs->count = fsfile.len;
				}
			}
		}
		if(hs->state == HTTP_FILE)
		{
			if(uip_acked())
			{
				if(hs->count >= uip_conn->len)
				{
					hs->count -= uip_conn->len;
					hs->dataptr += uip_conn->len;
				} else {
					hs->count = 0;
				}
				if(hs->count == 0)
				{
					if(upload_running)
					{
					//	int i;
						httpd_upload_complete = 1;
					//	for(i = 0; i < hs->upload_total; i++)
					//		printf("%c", httpd_upload_data[i]);
					}
					uip_close();
				}
			}
			uip_send((unsigned char *)hs->dataptr, hs->count);
		}
		break;

	default:
		uip_abort();
		break;
	}
}
