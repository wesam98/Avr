/*
 * main.c
 *
 *  Created on: Feb 18, 2024
 *      Author: METRA
 */

#include "../Libirarys/ErrorStates.h"
#include "../Libirarys/StdTypes.h"

#include  "../MCAL/DIO/DIO_Int.h"
#include  "../MCAL/ADC/ADC_Init.h"

#include "../HAL/LCD/LCD_Int.h"
#include "../HAL/LM35/LM_Int.h"

#include "util/delay.h"

extern LM_t LM_ArrStr[LM_NUM];
int main(void)
{
	DIO_enuInit();
	LCD_enuInit();
	LM_enuInit(LM_ArrStr);
	LCD_GOTO(0,1);
	LCD_enuWriteString("TEMP = ");
	s32 read;
	while(1)
	{
		LM_enuGetTemp(&read,&LM_ArrStr[0]);
		LCD_GOTO(0,8);
		LCD_enuDisplayIntegerNum(read);
		LCD_enuWriteString("C");
		_delay_ms(1000);
		LCD_GOTO(0,8);
		LCD_enuWriteString("   ");


	}


	return 0;
}


