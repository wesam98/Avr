/*
 * main.c
 *
 *  Created on: Oct 6, 2023
 *      Author: METRA
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
{ 	DDRA=0xFF;
	PORTA=0;
	while(1)
	{
		for(int i=0;i<8;i++){
			PORTA |= (1<<i);
			_delay_ms(500);
	}
		for(int i=7;i>=0;i--){
					PORTA &= ~(1<<i);
					_delay_ms(500);
			}
}
}
