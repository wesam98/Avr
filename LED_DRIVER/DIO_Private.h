/*
 * DIO_Private.h
 *
 *  Created on: Oct 27, 2023
 *      Author: METRA
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define BIT_MASK 1

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7

#define INPUT   0
#define OUTPUT  1
#define HIGH    1
#define LOW     0
#define FLOAT   0
#define PULL_UP 1

#define CONC_HELP(b0,b1,b2,b3,b4,b5,b6,b7)  0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b0,b1,b2,b3,b4,b5,b6,b7)       CONC_HELP(b0,b1,b2,b3,b4,b5,b6,b7)

#define	PORTA *((u8*)0x3B)
#define	DDRA *((u8*)0x3A)
#define	PINA *((volatile u8*)0x39)

#define	PORTB *((u8*)0x38)
#define	DDRB *((u8*)0x37)
#define	PINB *((volatile u8*)0x36)

#define	PORTD *((u8*)0x32)
#define	DDRD *((u8*)0x31)
#define	PIND  *((volatile u8*)0x30)

#define	PORTC *((u8*)0x35)
#define	DDRC *((u8*)0x34)
#define	PINC  *((volatile u8*)0x33)


#endif /* DIO_PRIVATE_H_ */
