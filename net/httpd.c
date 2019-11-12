/*
 *	Copyright 1994, 1995, 2000 Neil Russell.
 *	(See License)
 *	Copyright 2000, 2001 DENX Software Engineering, Wolfgang Denk, wd@denx.de
 */

#include <common.h>
#include <command.h>
#include <net.h>
#include "uip-0.9/uipopt.h"
#include "uip-0.9/uip.h"
#include "uip-0.9/uip_arp.h"


#if defined(CONFIG_CMD_HTTPD)

#define TIMEOUT		5

static int arptimer = 0;

void
HttpdHandler (void)
{
	int i;
	for(i = 0; i < UIP_CONNS; i++) {
		uip_periodic(i);
		if(uip_len > 0) {
			uip_arp_out();
			NetSendHttpd();
		}
	}
	if(++arptimer == 20) {
		uip_arp_timer();
		arptimer = 0;
	}
}

#if 0
static void
HttpdTimeout (void)
{
	puts ("T ");
	NetSetTimeout (TIMEOUT * 1000, HttpdTimeout);
}
#endif

void
HttpdStart (void)
{
	uip_init();
	httpd_init();
}

#endif
