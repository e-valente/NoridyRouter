#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sr_if.h"
#include "sr_rt.h"
#include "sr_router.h"
#include "sr_protocol.h"
#include "utils.h"
#include "arp.h"

void handleARP(struct sr_instance *sr, struct sr_arphdr *arp_hdr, char* interface)
{
  
  uint16_t hrd = ntohs( arp_hdr->ar_hrd );
  uint16_t pro = ntohs( arp_hdr->ar_pro );
  uint16_t op = ntohs( arp_hdr->ar_op );
  
  /*response*/
  struct sr_arphdr *arp_response;
  arp_response = (struct sr_arphdr*)malloc(sizeof(struct sr_arphdr));
  
  /*In a response target addr is the old source*/
  memcpy(arp_response->ar_tha, arp_hdr->ar_sha, ETHER_ADDR_LEN);
  arp_response->ar_tip = arp_hdr->ar_sip;
  /*sender hdr*/
  memcpy(arp_response->ar_sha, sr->if_list->addr, ETHER_ADDR_LEN);
  arp_response->ar_op = htons(ARP_REPLY);
  arp_response->ar_sip = sr->if_list->ip;
  
  
  /*our frame*/
  uint8_t* buffer = malloc( ETHER_HDR_LEN + sizeof(struct sr_arphdr));
  memcpy( buffer, arp_response->ar_tha, ETHER_HDR_LEN );
  memcpy( buffer+ETHER_ADDR_LEN, arp_response->ar_sha, ETHER_HDR_LEN);
  uint16_t type = htons(ETHERTYPE_ARP);
  memcpy(buffer+ETHER_ADDR_LEN+ETHER_ADDR_LEN, &type, 2);
  memcpy(buffer+ETHER_HDR_LEN, (uint8_t*)arp_response, sizeof(struct sr_arphdr));
  
  /*send*/
  sr_send_packet(sr, buffer, ETHER_HDR_LEN + sizeof(struct sr_arphdr), sr->if_list->name);
    
  
  
  

  fprintf(stderr, "Received ARP Packet (O = %s ) on %s from %s / %s\nWants %s hw %s\n", 
                   (op==1)?"Request":(op==2)?"Reply":"???",
		    interface,
                   ip_to_string( arp_hdr->ar_sip ),
                   hw_addr_to_string( arp_hdr->ar_sha ),
		   ip_to_string(arp_hdr->ar_tip),
		   hw_addr_to_string(arp_hdr->ar_tha)
 	);
  
  fprintf(stderr, "My interface %s my addr %s\n", sr->if_list->name, hw_addr_to_string(sr->if_list->addr));
  
  free(arp_response);
  free(buffer);
  

}
