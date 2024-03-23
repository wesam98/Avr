/*
 * APP.c
 *
 *  Created on: Mar 20, 2024
 *      Author: METRA
 */
#include "../MCAL/DIO/DIO_Int.h"

#include "../MCAL/EXTI/EXTI_Init.h"
#include "../MCAL/EXTI/EXTI_Config.h"
#include "../MCAL/GIE/GIE_Init.h"
#include "../MCAL/Timer/Timer_Int.h"

#include "../HAL/LED/LED_Config.h"
#include "../HAL/LED/LED_Int.h"

#include "../MCAL/EXTI/interrupt.h"

#include "../Libirarys/StdTypes.h"

#include "APP.h"

extern LED_t LED_AstrLedConfig [LED_NUM];

extern EXTI_t EXTI_ArrStr[3];


u8 count=0 ,Tog =0,INT_Flag=0;

void Init_System()
{
	DIO_enuInit();
	LED_enuInit(LED_AstrLedConfig);
	Timer_enuInit();

	EXTI_enuInit(EXTI_ArrStr);
	EXTI_enuEnable(0);
	GIE_enuEnable();



}
void Tog2Yellows()
{
	for(u8 i=0 ;i<10;i++)
	{
		DIO_enuTogPin(DIO_u8PORTC,DIO_u8PIN1);
		DIO_enuTogPin(DIO_u8PORTC,DIO_u8PIN4);
		Timer_enuSetSynchDelay(500);

	}
	LED_enuLedOFF(&LED_AstrLedConfig[1]);
	LED_enuLedOFF(&LED_AstrLedConfig[4]);

}

void Tog1Yellow()
{
	Tog = 1;
	for(u8 i=0 ;i<10;i++)
	{
		DIO_enuTogPin(DIO_u8PORTC,DIO_u8PIN1);
		Timer_enuSetSynchDelay(500);
	}
	LED_enuLedOFF(&LED_AstrLedConfig[1]);


}
void Car_Traffic()
{

	for( count = 0 ; count <3 ; count ++)
	{
		if(count == 1)
		{
			Tog1Yellow();
			Tog = 0;
		}
		else
		{
			LED_enuLedON(&LED_AstrLedConfig[count]);
			Timer_enuSetSynchDelay(3000);
			LED_enuLedOFF(&LED_AstrLedConfig[count]);

		}
	}

	for( count = 1 ; count >= 1 ; count --)
	{
		if(count == 1)
		{
			Tog1Yellow();
			Tog = 0;
		}
		else
		{
			LED_enuLedON(&LED_AstrLedConfig[count]);
			Timer_enuSetSynchDelay(3000);
			LED_enuLedOFF(&LED_AstrLedConfig[count]);

		}
	}


}
void EndOFState()
{
	//turn of car's Red LED
	LED_enuLedOFF(&LED_AstrLedConfig[2]);

	//pedestrain 's Green is on for 5 sec
	LED_enuLedON(&LED_AstrLedConfig[3]);

	//blink 2 yellows
	Tog2Yellows();

	//After the five seconds the pedestrian Green LED will be off
	LED_enuLedOFF(&LED_AstrLedConfig[3]);

	//both the pedestrian Red LED and the cars' Green LED will be on.
	LED_enuLedON(&LED_AstrLedConfig[5]);
	LED_enuLedON(&LED_AstrLedConfig[0]);

	Timer_enuSetSynchDelay(3500);

	LED_enuLedOFF(&LED_AstrLedConfig[5]);

	count = 0;


}

void Pedestrian()
{
	if(count == 2)
	{
		LED_enuLedON(&LED_AstrLedConfig[3]);
		LED_enuLedON(&LED_AstrLedConfig[2]);

		Timer_enuSetSynchDelay(3500);

		LED_enuLedOFF(&LED_AstrLedConfig[2]);
		LED_enuLedOFF(&LED_AstrLedConfig[3]);

		EndOFState();
	}


	else if(count == 0 || Tog == 1)
	{

		LED_enuLedOFF(&LED_AstrLedConfig[0]);

		// Pedestrian's red Led on
		LED_enuLedON(&LED_AstrLedConfig[5]);

		//blink 2 yellows
		Tog2Yellows();

		LED_enuLedOFF(&LED_AstrLedConfig[5]);


		// the cars' Red LED and pedestrian's green LED are on
		LED_enuLedON(&LED_AstrLedConfig[2]);
		LED_enuLedON(&LED_AstrLedConfig[3]);
		Timer_enuSetSynchDelay(3500);

		Tog = 0;
		EndOFState();

	}

}
void ISR_INT0()
{
	//INT_Flag = 1;
	Pedestrian();
}
