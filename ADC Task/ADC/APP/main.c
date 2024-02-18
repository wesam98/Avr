/*
 * main.c
 *
 *  Created on: Feb 9, 2024
 *      Author: METRA
 */
#include "../Libirarys/StdTypes.h"
#include "../Libirarys/ErrorStates.h"

#include "../MCAL/DIO/DIO_Int.h"
#include "../MCAL/ADC/ADC_Init.h"

#include "../HAL/LCD/LCD_Int.h"

#include "util/delay.h"
int main()
{
	DIO_enuInit();
	ADC_enuInit();
	LCD_enuInit();
    ADC_enuSelectChannel(2,-1,0);
    DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8INPUT);
	u16 READ = 0;
	while(1)
	{
		ADC_vidEnableADC();
		ADC_enuStartConversion(&READ);
		LCD_enuDisplayIntegerNum(READ);
		_delay_ms(1000);
		LCD_ClearDisp();



	}
	return 0;
}
