/*
 * main.c
 *
 *  Created on: Nov 24, 2023
 *      Author: METRA
 */


#include "StdTypes.h"
#include "ErrorStates.h"

#include "DIO_Int.h"
#include "Segment_int.h"
#include <util/delay.h>
extern SEG_t Segmet_AstrSegConfig[SEG_NUM];
int main(void)
{
	DIO_enuInit();
	Segment_enuIniti(Segmet_AstrSegConfig);
	Segment_enuDisableCommon(0);
	Segment_enuDisableCommon(1);

	while(1)

	{
		Segment_enuDisableCommon(0);
		Segment_enuDisplay(0,6);
		Segment_enuEnableCommon(0);
		_delay_ms(10);
		Segment_enuDisableCommon(0);
		Segment_enuDisplay(1,9);
		Segment_enuEnableCommon(1);
		_delay_ms(10);
		Segment_enuDisableCommon(1);




	}
	return 0;
}
