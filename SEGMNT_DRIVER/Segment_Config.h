/*
 * Segment_Config.h
 *
 *  Created on: Nov 7, 2023
 *      Author: METRA
 */
#include "DIO_Private.h"
#include "Segment_private.h"
#ifndef SEGMENT_CONFIG_H_
#define SEGMENT_CONFIG_H_

#define SEG_TYPE COMMON_ANODE

#define SEG_APIN  DIO_u8PIN0
#define SEG_APORT DIO_u8PORTC


#define SEG_BPIN  DIO_u8PIN1
#define SEG_BPORT DIO_u8PORTC


#define SEG_CPIN  DIO_u8PIN2
#define SEG_CPORT DIO_u8PORTC


#define SEG_DPIN  DIO_u8PIN3
#define SEG_DPORT DIO_u8PORTC


#define SEG_EPIN  DIO_u8PIN4
#define SEG_EPORT DIO_u8PORTC


#define SEG_FPIN  DIO_u8PIN5
#define SEG_FPORT DIO_u8PORTC

#define SEG_GPIN  DIO_u8PIN6
#define SEG_GPORT DIO_u8PORTC

#define SEG_COMMPIN    NOT_CONNECTED
#define SEG_COMMPORT   NOT_CONNECTED

#define SEG_DOTPIN     NOT_CONNECTED
#define SEG_DOTPORT    NOT_CONNECTED
#endif /* SEGMENT_CONFIG_H_ */
