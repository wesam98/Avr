/*
 * main.c

 *
 *  Created on: Nov 7, 2023
 *      Author: METRA
 */
#include "StdTypes.h"
#include "ErrorStates.h"

#include "DIO_Int.h"
#include "Segment_int.h"
#include <util/delay.h>

int main(void)
{
	DIO_enuInit();
    Seven_Segment_enuInit();
	while(1)

	{
		for(u8 i=0 ; i<10 ; i++)
		{
			Seven_Segment_enuDisplayNum(i);
			_delay_ms(500);
		}


	}
	return 0;
}
