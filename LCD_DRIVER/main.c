/*
 * main.c
 *
 *  Created on: Nov 29, 2023
 *      Author: METRA
 */

#include "DIO_Int.h"

#include "LCD_Int.h"
#include "util/delay.h"

int main(void)
{
	DIO_enuInit();
	LCD_enuInit();

	while(1);
	{
		LCD_enuDisplayIntegerNum(3);
		_delay_ms(300);
	}

	return 0;
}
