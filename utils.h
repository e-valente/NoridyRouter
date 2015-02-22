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

uint16_t discoverEtherType(uint8_t *packet);
void printEthernetHeader(uint8_t *packet);