/*
 * main.c
 *
 *  Created on: Oct 6, 2023
 *      Author: Wesam Abdelaziz
 */

typedef unsigned char u8;
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define	PORTA *((u8*)0x3B)
#define	DDRA *((u8*)0x3A)
#define	PINA *((volatile u8*)0x39)

#define	PORTB *((u8*)0x38)
#define	DDRB *((u8*)0x37)
#define	PINB *((volatile u8*)0x36)

#define	DDRD *((u8*)0x31)
int main(void)
{ 	DDRA=0x01;
	PORTA=0;

	while(1)
	{
		PORTA |= (1<<0);
		_delay_ms(1000);
		PORTA &= ~(1<<0);
		_delay_ms(1000);

	}
}
