/*
 * Timer_Private.h
 *
 *  Created on: Feb 22, 2024
 *      Author: METRA
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


#define  TCCR0       *((volatile u8*)0x53)
#define  TCNT0       *((volatile u8*)0x52)
#define  OCR0        *((volatile u8*)0x5C)
#define  TIFR        *((volatile u8*)0x58)
#define  TIMSK       *((volatile u8*)0x59)



/*  Wave form  generation Modes */
#define  NORMAL_MODE            0
#define  PWM_MODE               1
#define  CTC_MODE               2

/* OCT Choices  */
#define Toggle                  10
#define Clear                   12
#define Set                     13
#define DISCONNECTED            11
/* PWM Phase Choices */
#define  FAST_INVERTED                   16
#define  FAST_NON_INVERTED               17
#define  PHASE_CORRECT_INVER             18
#define  PHASE_CORRECT_NON_INVER         19


/* prescaler choices */
#define    Timer_Stopped      0
#define    No_Pres           1
#define    FALLING_EDGE       2
#define    RISING_EDGE        3

#endif /* TIMER_PRIVATE_H_ */
