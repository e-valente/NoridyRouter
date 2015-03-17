/*-----------------------------------------------------------------------------
 * file:  utils.h
 * date:  Sun Mar 15 22:43:31 MST 2015
 * Contact: emanuelvalente@arizona.edu
 *
 * Description:
 *
 * Data structures and methods for handeling ARP protocol
 *
 *---------------------------------------------------------------------------*/

#ifndef _ARP_H
#define _ARP_H
#endif

#include "sr_router.h"

void handleARP(struct sr_instance *sr, struct sr_arphdr *arp_hdr, char* interface);