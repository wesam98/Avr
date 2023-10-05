/*
 * main.c
 *
 * Created: 10/5/2023 4:32:00 PM
 *  Author: METRA
 */
typedef unsigned char u8;
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#define	PORTA *((u8*)0x3B)
#define	DDRA *((u8*)0x3A)
#define	PINA *((volatile u8*)0x39)



int main(void)
{
	DDRA |=(1<<0);


    while(1){
	   PORTA |=(1<<0);
	   _delay_ms(500);
	   PORTA &=~(1<<0);
	   _delay_ms(500);
	}



}