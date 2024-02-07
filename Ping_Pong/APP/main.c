/*
 * main.c
 *
 *  Created on: Feb 6, 2024
 *      Author: METRA
 */
#include "../Libirarys/ErrorStates.h"
#include "../Libirarys/StdTypes.h"

#include "../MCAL/DIO_Int.h"

#include "../HAL/LCD/LCD_Int.h"

#include "../HAL/EXTI/EXTI_Init.h"
#include "../HAL/GIE/GIE_Init.h"

#include "App.h"

#include "util/delay.h"

extern EXTI_t EXTI_ArrStr[3];

int main(void)
{
	DIO_enuInit();
	LCD_enuInit();
/*               input pins of interrupt          */
	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8INPUT);

	EXTI_enuInit(EXTI_ArrStr);
	GIE_enuEnable();

	EXTI_CallBack(&ISR_INT0,0);
	EXTI_CallBack(&ISR_INT1,1);

	LCD_GOTO(1,1);
	LCD_enuWriteString("Welcome To");
	LCD_GOTO(2,2);
	LCD_enuWriteString("PING PONG GAME");
	_delay_ms(500);
	LCD_ClearDisp();
	Ping_PongInit();
	//LCD_GOTO(2,1);

	while(1)
	{

		Ping_PongStart();

	}
	return 0 ;
}

