/*
 * main.c
 *
 *  Created on: Oct 5, 2023
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
{   //led is ouput ,low at start
	DDRA |= (1<<0);
	PORTA &= ~(1<<0);
	DDRA |= (1<<1);
	PORTA &= ~(1<<1);
	//buttons are input,
	DDRB=0;
	//buttons are pulled up,
	PORTB|=(1<<0);
	PORTB|=(1<<1);
	PORTB|=(1<<2);


	u8 read=0;


while(1)
{	read =~PINB;
    DDRD=read;
	if(read==249)
		PORTA |= (1<<0);


else
	PORTA &= ~(1<<0);

 if(read==250)
	PORTA |= (1<<1);
else
	PORTA &=~(1<<1);


 if(read==252)
 {
	PORTA|=(1<<0);
	PORTA|=(1<<1);
 }

else{
	PORTA &= ~(1<<0);
	PORTA &= ~(1<<1);
}


}
}
