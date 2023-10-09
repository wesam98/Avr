/*
 * main.c
 *
 *  Created on: Oct 8, 2023
 *      Author: METRA
 */
typedef unsigned char u8;
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define	PORTA *((u8*)0x3B)
#define	DDRA *((u8*)0x3A)
#define	PINA *((volatile u8*)0x39)

#define	PORTC *((u8*)0x35)
#define	DDRC *((u8*)0x34)
#define	PINC *((volatile u8*)0x33)

#define	PORTB *((u8*)0x38)
#define	DDRB *((u8*)0x37)
#define	PINB *((volatile u8*)0x36)
u8 digits[]={0x3f,0x06,0x5B,0x4f,0x66,0x6D,0x7D,0x07,0x7f,0x6f};

#define	DDRD *((u8*)0x31)
int main(void)
{  //7segment is output
	DDRC=0xff;
	PORTC=0;

	//buutons are input
	DDRA &=~(1<<0);
	DDRA &=~(1<<1);
	//buttons are pulled up
	PORTA|=(1<<0);
	PORTA|=(1<<1);

	u8 c=0,button1,button2;
	while(1)
	{

		button1=((PINA>>0)&1);
		button2=((PINA>>1)&1);

		if(button1==0)
		{
			c++;
			 while(((PINA>>0)&1)==0);
		}
		else if(button2==0)
		{
				c--;
				while(((PINA>>1)&1)==0);

		}

		if(c<=9 && c>=0){
		PORTC=digits[c];
		}
		else
		{
			c=0;
		}

	}
	return 0;
}
