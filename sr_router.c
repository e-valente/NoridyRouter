/**********************************************************************
 * file:  sr_router.c 
 * date:  Mon Feb 18 12:50:42 PST 2002  
 * Contact: casado@stanford.edu 
 *
 * Description:
 * 
 * This file contains all the functions that interact directly
 * with the routing table, as well as the main entry method
 * for routing. 11
 * 90904102
 **********************************************************************/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


#include "sr_if.h"
#include "sr_rt.h"
#include "sr_router.h"
#include "sr_protocol.h"

/*--------------------------------------------------------------------- 
 * Method: sr_init(void)
 * Scope:  Global
 *
 * Initialize the routing subsystem
 * 
 *---------------------------------------------------------------------*/

void sr_init(struct sr_instance* sr) 
{
    /* REQUIRES */
    assert(sr);

    /* Add initialization code here! */

} /* -- sr_init -- */



/*---------------------------------------------------------------------
 * Method: sr_handlepacket(uint8_t* p,char* interface)
 * Scope:  Global
 *
 * This method is called each time the router receives a packet on the
 * interface.  The packet buffer, the packet length and the receiving
 * interface are passed in as parameters. The packet is complete with
 * ethernet headers.
 *
 * Note: Both the packet buffer and the character's memory are handled
 * by sr_vns_comm.c that means do NOT delete either.  Make a copy of the
 * packet instead if you intend to keep it around beyond the scope of
 * the method call.
 *
 *---------------------------------------------------------------------*/

void sr_handlepacket(struct sr_instance* sr, 
        uint8_t * packet/* lent */,
        unsigned int len,
        char* interface/* lent */)
{
    /* REQUIRES */
    assert(sr);
    assert(packet);
    assert(interface);
    //struct sr_ethernet_hdr *myetherpaket;
    //uint8_t tmp[6];
    struct sr_ethernet_hdr *ehdr;
    int pos = 0;
    
    ehdr = (struct sr_ethernet_hdr*)malloc(sizeof(struct sr_ethernet_hdr));
    memcpy(ehdr, packet, sizeof(struct sr_ethernet_hdr));
    

    printf("*** -> Received packet of length %d \n",len);
    printf("****-> from interface %s\n", interface);
  
  uint8_t *array = ehdr->ether_shost;
  
  printf("DST:\n");
  for (; pos < ETHER_ADDR_LEN; pos++) {
    uint8_t cur = array[pos];
    //uint8_t cur = ehdr->ether_dhost[pos];
    if (pos > 0) {
      fprintf(stderr, ":");
    }
    //each byte
    fprintf(stderr, "%02X", ntohs(cur));
  }
  fprintf(stderr, "\n");

}/* end sr_ForwardPacket */


/*--------------------------------------------------------------------- 
 * Method:
 *
 *---------------------------------------------------------------------*/
