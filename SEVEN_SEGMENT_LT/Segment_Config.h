/*
 * Segment_Config.h
 *
 *  Created on: Nov 25, 2023
 *      Author: METRA
 */

#ifndef SEGMENT_CONFIG_H_
#define SEGMENT_CONFIG_H_
#include "DIO_Private.h"
#include "StdTypes.h"
#define SEG_NUM 2

typedef struct {
	u8 SEG_APIN ;
	u8 SEG_APORT;

	u8 SEG_BPIN;
	u8 SEG_BPORT;

	u8 SEG_CPIN;
	u8 SEG_CPORT;

	u8 SEG_DPIN ;
	u8 SEG_DPORT ;

	u8 SEG_EPIN ;
	u8 SEG_EPORT;

	u8 SEG_FPIN ;
	u8 SEG_FPORT ;

	u8 SEG_GPIN ;
	u8 SEG_GPORT ;

	u8 SEG_COMMONPIN ;
	u8 SEG_COMMONPORT;

	u8 SEG_DOTPIN ;
	u8 SEG_DOTPORT ;

    u8 SEG_TYPE  ;
}SEG_t;

#endif /* SEGMENT_CONFIG_H_ */
