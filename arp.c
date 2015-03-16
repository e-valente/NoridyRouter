#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sr_if.h"
#include "sr_rt.h"
#include "sr_router.h"
#include "sr_protocol.h"
#include "utils.h"
#include "arp.h"

void handleARP(struct sr_instance *sr, struct sr_arphdr *arp_hdr)
{
  
  uint16_t hrd = ntohs( arp_hdr->ar_hrd );
  uint16_t pro = ntohs( arp_hdr->ar_pro );
  uint16_t op = ntohs( arp_hdr->ar_op );
  

  fprintf(stderr, "Received ARP Packet (O = %s ) on  from %s / %s\n", 
                   (op==1)?"Request":(op==2)?"Reply":"???",
                   ip_to_string( arp_hdr->ar_sip ),
                   hw_addr_to_string( arp_hdr->ar_sha ) );
  

}
