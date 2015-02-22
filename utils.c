#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sr_if.h"
#include "sr_rt.h"
#include "sr_router.h"
#include "sr_protocol.h"
#include "utils.h"


uint16_t discoverEtherType(uint8_t *packet) {
  uint16_t ether_type;
   
  /*struct sr_ethernet_hdr has the dst[ETHER_ADDR_LEN] and src[ETHER_ADDR_LEN] 
   *and then ether_type
   */
 ether_type = *(uint16_t*) (packet + (2 * ETHER_ADDR_LEN * sizeof(uint8_t)));
 
 return ntohs(ether_type);
  
}

void printEthernetHeader(uint8_t *packet) {
   struct sr_ethernet_hdr *ehdr;
   
   ehdr = (struct sr_ethernet_hdr*)malloc(sizeof(struct sr_ethernet_hdr));
   memcpy(ehdr, packet, sizeof(struct sr_ethernet_hdr));
 
   uint8_t *array = ehdr->ether_dhost;
   
   fprintf(stderr, "Ethernet Header:\n");
   int pos;
   fprintf(stderr, "DST (MAC ADDRESS): ");
   for (pos = 0; pos < ETHER_ADDR_LEN; pos++) {
    uint8_t cur = array[pos];
    if (pos > 0) {
      fprintf(stderr, ":");
    }
    //each byte
    fprintf(stderr, "%02X", cur);
  }
  fprintf(stderr, "\n");
  
   array = ehdr->ether_shost;
   fprintf(stderr, "SRC (MAC ADDRESS): ");
   for (pos = 0; pos < ETHER_ADDR_LEN; pos++) {
    uint8_t cur = array[pos];
    if (pos > 0) {
      fprintf(stderr, ":");
    }
    //each byte
    fprintf(stderr, "%02X", cur);
  }
  fprintf(stderr, "\n");
  
  fprintf(stderr, "EtherType: 0x%04x\n\n", ntohs(ehdr->ether_type));
  
  free(ehdr);
  
}

