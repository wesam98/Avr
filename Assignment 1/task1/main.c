/*
 * main.c
 *
 * Created: 10/5/2023 4:32:00 PM
 *  Author: WESAM ABDELAZIZ
 */
typedef unsigned char u8;
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#define	PORTA *((u8*)0x3B)
#define	DDRA *((u8*)0x3A)
#define	PINA *((volatile u8*)0x39)


#include <xc.h>

int main(void)
{   for(int i=0;i<6;i++)
	DDRA |=(1<<i);


    while(1)
    { for(int i=0;i<6;i++){
	   PORTA |=(1<<i);
	   _delay_ms(500);
	}
	 for(int i=0;i<6;i++){
	   PORTA &=~(1<<i);
	   _delay_ms(500);
	}


    }
}