/*-----------------------------------------------------------------------------
 * file:  utils.h
 * date:  Sat Feb 21 16:36:53 MST 2015
 * Contact: emanuelvalente@arizona.edu
 *
 * Description:
 *
 * Data structures and methods for handeling interfaces
 *
 *---------------------------------------------------------------------------*/

#ifndef _UTILS_H
#define _UTILS_H
#endif

#define ETHER_HDR_LEN 14

const char* icmp_to_string( uint8_t type );
const char* ip_proto_to_string( unsigned char proto );
const char* ip_to_string( uint32_t ip );
const char* hw_addr_to_string( unsigned char* addr_hw );
uint16_t discoverEtherType(uint8_t *packet);
void printEthernetHeader(uint8_t *packet);