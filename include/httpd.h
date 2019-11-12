#ifndef _UIP_HTTPD_H__
#define _UIP_HTTPD_H__

void HttpdStart (void);
void HttpdHandler (void);

/* board specific implementation */
extern int do_http_upgrade(const unsigned char *data, const ulong size);

#define HTTP_PROGRESS_START		0
#define HTTP_PROGRESS_TIMEOUT		1
#define HTTP_PROGRESS_UPLOAD_READY	2
#define HTTP_PROGRESS_UGRADE_READY	3
#define HTTP_PROGRESS_UGRADE_FAILED	4
extern int do_http_progress(const int state);

#endif
