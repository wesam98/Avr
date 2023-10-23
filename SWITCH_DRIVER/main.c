/*
.0n * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: METRA
 */
#include "Switch_Cinfig.h"
#include "DIO_Int.h"
#include "StdTypes.h"
#include"ErrorStates.h"
u8 Local_SwState1;
extern SW_t SWITCH_AstrSWStatus [SW_NUM];
int main (void)
{   DIO_enuInit();
SWITCH_enuSwInit(SWITCH_AstrSWStatus);
u8 Local_SwState1;
while(1)
{
	SWITCH_enuSwState(&SWITCH_AstrSWStatus[0], &Local_SwState1);
	if(Local_SwState1==1)
	{
		DIO_enuSetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8LOW);
		while(SWITCH_enuSwState(&SWITCH_AstrSWStatus[0],&Local_SwState1));
	}

	else
		DIO_enuSetPinValue(DIO_u8PORTB, DIO_u8PIN0 , DIO_u8HIGH);

}
return 0;
}
