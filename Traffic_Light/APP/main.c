/*
 * main.c
 *
 *  Created on: Feb 22, 2024
 *      Author: METRA
 */

#include "../MCAL/DIO/DIO_Int.h"
#include "../MCAL/EXTI/EXTI_Init.h"
#include "../MCAL/GIE/GIE_Init.h"

#include "../MCAL/EXTI/interrupt.h"

#include "../MCAL/Timer/Timer_Int.h"
#include "../MCAL/Timer/Timer_Private.h"

#include "../HAL/LED/LED_Config.h"
#include "../HAL/LED/LED_Int.h"

#include "APP.h"

extern u8 INT_Flag;
u8 PinState;
int main(void)
{

	Init_System();

	//set INt0 pin as input
	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8INPUT);
	EXTI_CallBack(&ISR_INT0,0);


	while(1)
	{

		Car_Traffic();
		GIE_enuEnable();
		/*if(INT_Flag == 1)
		{

			Pedestrian();
			INT_Flag = 0;
		}
		/*DIO_enuGetPinValue(DIO_u8PORTD,DIO_u8PIN2,&PinState);
			if(PinState )
		{
			Pedestrian();
			PinState =0;
		}*/
	}

	return 0;
}
