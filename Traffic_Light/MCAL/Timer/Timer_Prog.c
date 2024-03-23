/*
 * Timer_Prog.c
 *
 *  Created on: Feb 22, 2024
 *      Author: METRA
 */

#include "../../Libirarys/ErrorStates.h"
#include "../../Libirarys/StdTypes.h"

#include "../DIO/DIO_Int.h"

#include "Timer_Private.h"
#include "Timer_Config.h"

#include "../../MCAL/EXTI/interrupt.h"

#include "../GIE/GIE_Init.h"

static void(*gptr)(void)=NULL;

static u32 counts = 0;

ES_t Timer_enuInit()
{
	ES_t Local_enuErrorState = ES_NOK;

	/*   set prescaler value  */

#if Timer0_Prescaler == Timer_Stopped
	TCCR0 &= 0xf8;

#elif Timer0_Prescaler == No_Pres
	TCCR0 &= 0xf8;
	TCCR0 |= 1;

#elif Timer0_Prescaler == 8
	TCCR0 &= 0xf8;
	TCCR0 |= 2;


#elif Timer0_Prescaler == 64

	TCCR0 &= 0xf8;
	TCCR0 |= 3;

#elif Timer0_Prescaler == 256

	TCCR0 &= 0xf8;
	TCCR0 |= 4;

#elif Timer0_Prescaler == 1024

	TCCR0 &= 0xf8;
	TCCR0 |= 5;

	/*  External pin mode   */
#elif Timer0_Prescaler == FALLING_EDGE
	TCCR0 &= 0xf8;
	TCCR0 |= 6;

#elif Timer0_Prescaler == RISING_EDGE
	TCCR0 &= 0xf8;
	TCCR0 |= 7;

#else
	Local_enuErrorState = ES_OUT_OF_RANGE;

#endif


	/* set timer mode */

#if Timer0_Mode ==  NORMAL_MODE

	TCCR0 &= ~(1<<3);
	TCCR0 &= ~(1<<6);



#elif Timer0_Mode ==  PWM_MODE

	//set oc0 pin as output
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN3,DIO_u8OUTPUT);

#if PWM_Phase == FAST_INVERTED
	//WGM00 && WGM01
	TCCR0 |= (1<<3);
	TCCR0 |=  (1<<6);
    //oc0 pin
	TCCR0 |= (1<<4);
	TCCR0 |= (1<<5);
#elif PWM_Phase == FAST_NON_INVERTED
	//WGM00 && WGM01
	TCCR0 |= (1<<3);
	TCCR0 |=  (1<<6);
    //oc0 pin
	TCCR0 &= ~(1<<4);
	TCCR0 |=  (1<<5);
#elif PWM_Phase == PHASE_CORRECT_INVER
	//WGM00 && WGM01
	TCCR0 &= ~(1<<3);
	TCCR0 |=  (1<<6);
    //oc0 pin
	TCCR0 |= (1<<4);
	TCCR0 |= (1<<5);
#elif PWM_Phase == PHASE_CORRECT_NON_INVER
	//WGM00 && WGM01
	TCCR0 &= ~(1<<3);
	TCCR0 |=  (1<<6);
    //oc0 pin
	TCCR0 &= ~(1<<4);
	TCCR0 |=  (1<<5);
#else
#error"WRONG PWM PHASE CHOICE"
#endif


#elif Timer0_Mode ==  CTC_MODE
	TCCR0 |=  (1<<3);
	TCCR0 &= ~(1<<6);
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN3,DIO_u8OUTPUT);

#if  OC0_MODE ==  Toggle
	TCCR0 &= ~(1<<5);
	TCCR0 |=  (1<<4);
#elif OC0 == Clear
	TCCR0 &= ~(1<<4);
	TCCR0 |=  (1<<5);
#elif OC0 == Set
	TCCR0 |=  (1<<4);
	TCCR0 |=  (1<<5);
#else
#error "Wrong OC0 Mode"
#endif


#else
#error "Timer0 Mode choice is wrong "

#endif

#if OCD_MODE == DISCONNECTED
	TCCR0 &= ~(1<<4);
	TCCR0 &= ~(1<<5);

#elif OCD_MODE == CONNECTED
	TCCR0 |=  (1<<4);
	TCCR0 |=  (1<<5);
#else
#error "Timer0 Mode choice is wrong "
#endif



	return Local_enuErrorState;
}


ES_t Timer_enuSetPreload(u32 Copy_u32PreloadValue)
{
	ES_t Local_enuErrorState = ES_NOK;

	TCNT0 = Copy_u32PreloadValue;

	return Local_enuErrorState;

}

ES_t Timer_enuSetSynchDelay(u32 Copy_u32DesiredTime_ms )
{
	ES_t Local_enuErrorState = ES_NOK;

	GIE_enuDisable();

	f32 Local_f32OVF_Time = 0;
	f32 Local_f32OVF_Num = 0;

	/* determine time that timer0 needs to reach overflow  */
	Local_f32OVF_Time = 256 * ((f32)Timer0_Prescaler/TIMER_F_CPU);

	/* deternmine number of overflows that timer needs to reach desired time*/
	Local_f32OVF_Num =  Copy_u32DesiredTime_ms / Local_f32OVF_Time;

	if( (Local_f32OVF_Num-(u32)Local_f32OVF_Num) != 0.0)
	{
		/* determine num of overflows nedded */
		u32 Local_u32OVF_Num = (u32)Local_f32OVF_Num + 1;
		//update this variable Local_f32OVF_Num with fraction of N of OVF
		Local_f32OVF_Num -= (u32)Local_f32OVF_Num;
		/* Load preloaded value */
		u8 preload= 256 - (Local_f32OVF_Num * 256);
		TCNT0 = preload;
		while(Local_u32OVF_Num > 0)
		{
			while(((TIFR>>0)&1) == 0 );
			TIFR |= (1<<0);
			Local_u32OVF_Num--;
		}
	}
	else
	{
		u32 Local_u32OVF_Num = (u32)Local_f32OVF_Num;
		while(Local_u32OVF_Num > 0)
		{
			while(((TIFR>>0)&1) == 0 );
			TIFR |= (1<<0);
			Local_u32OVF_Num--;

		}
	}
	GIE_enuEnable();

	return Local_enuErrorState;
}



ES_t Timer_enuSetAsychDelay(u32 Copy_u32DesiredTime_ms ,void(*Copy_Pfn)(void))
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Pfn != NULL)
	{
		gptr = Copy_Pfn ;

		f32 Local_f32OVF_Time = 0;
		f32 Local_f32OVF_Num = 0;
		u32 Local_u32OVF_Num ;

		/* determine time that timer0 needs to reach overflow  */
		Local_f32OVF_Time = 256 * ((f32)Timer0_Prescaler/TIMER_F_CPU);

		/* deternmine number of overflows that timer needs to reach desired time*/
		Local_f32OVF_Num =  Copy_u32DesiredTime_ms / Local_f32OVF_Time;

		if( (Local_f32OVF_Num-(u32)Local_f32OVF_Num) != 0.0)
		{
			/* determine num of overflows nedded */
			Local_u32OVF_Num = (u32)Local_f32OVF_Num + 1;

			//update this variable Local_f32OVF_Num with fraction of N of OVF
			Local_f32OVF_Num -= (u32)Local_f32OVF_Num;

			/* Load preloaded value */
			u8 preload= 256 - (Local_f32OVF_Num * 256);
			TCNT0 = preload;
			//Enable overFlow Interrupt (TOIE0 bit)
			TIMSK |= (1<<0);

			if(counts ==  Local_u32OVF_Num)
			{
				gptr();
				TCNT0 = preload;
				counts = 0;
			}

		}
		else
		{
			Local_u32OVF_Num =  (u32)Local_f32OVF_Num;
		}
	}

	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ISR(VECT_TIMER_OVF)
{
	if(gptr != NULL)
	{
		counts++;

	}
}
