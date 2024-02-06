/*
 * main.c
 *
 *  Created on: Feb 6, 2024
 *      Author: METRA
 */
#include "../Libirarys/ErrorStates.h"
#include "../Libirarys/StdTypes.h"

#include "../MCAL/DIO_Int.h"

#include "../HAL/EXTI/EXTI_Init.h"
#include "../HAL/GIE/GIE_Init.h"

extern EXTI_t EXTI_ArrStr[3];
void Tog (void);
int main(void)
{
	DIO_enuInit();
	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8OUTPUT);
	DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8HIGH);

	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8INPUT);

	EXTI_enuInit(EXTI_ArrStr);
	GIE_enuEnable();
	EXTI_CallBack(Tog,0);


	while(1)
	{

	}
	return 0 ;
}
void Tog (void)
{
	DIO_enuTogPin(DIO_u8PORTA,DIO_u8PIN0);
}
