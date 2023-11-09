/*
 * Segment_int.h
 *
 *  Created on: Nov 7, 2023
 *      Author: METRA
 */

#ifndef SEGMENT_INT_H_
#define SEGMENT_INT_H_

ES_t Seven_Segment_enuInit(void);
ES_t Seven_Segment_enuDisplayNum(u8 Copy_u8Num);
ES_t Seven_Segment_enuEnbleCommon(void);
ES_t Seven_Segment_enuDisableCommon(void);
ES_t Seven_Segment_enuEnbleDot(void);
ES_t Seven_Segment_enuDisableDot(void);
ES_t Seven_Segment_enuClearDisplay(void);

#endif /* SEGMENT_INT_H_ */
