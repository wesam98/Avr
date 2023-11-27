/*
 * Segment_Private.h
 *
 *  Created on: Nov 25, 2023
 *      Author: METRA
 */

#ifndef SEGMENT_PRIVATE_H_
#define SEGMENT_PRIVATE_H_
#include "StdTypes.h"
#define COMMOM_CATHODE 9
#define COMMOM_ANODE   10

#define CONNECTED      0
#define NOT_CONNECTED   1


static u8 SEG_Au8Display[]= {  0x3f, 0x06, 0x5B,
		0x4F, 0x66, 0x6D,
		0x7D, 0x07, 0x7F,
		0x6F};

#endif /* SEGMENT_PRIVATE_H_ */
