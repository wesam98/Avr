/*
 * Segment_int.h
 *
 *  Created on: Nov 25, 2023
 *      Author: METRA
 */

#ifndef SEGMENT_INT_H_
#define SEGMENT_INT_H_

#include "DIO_Int.h"
#include "Segment_Config.h"

#include "ErrorStates.h"
#include "StdTypes.h"

ES_t Segment_enuIniti(SEG_t *Copy_PAStrSegConfig);
ES_t Segment_enuDisplay(u8 Copy_u8SegID,u8 Copy_u8num);
ES_t Segment_enuEnableCommon(u8 Copy_u8SegID);
ES_t Segment_enuDisableCommon(u8 Copy_u8SegID);
ES_t Segment_enuEnableDot(u8 Copy_u8SegID);
ES_t Segment_enuDisableDot(u8 Copy_u8SegID);
ES_t Segment_enuClear(u8 Copy_u8SegID);


#endif /* SEGMENT_INT_H_ */
