/*
 * LED_Config.c
 *
 *  Created on: Oct 27, 2023
 *      Author: METRA
 */

#include "Error_States.h"
#include "StdTypes.h"

#include"DIO_int.h"
#include "LED_Private.h"
#include "LED_Config.h"

LED_t LED_AstrLedConfig [LED_NUM]={
		{DIO_u8PORTA,DIO_u8PIN1,LED_SOURCE,LED_OFF},
		{DIO_u8PORTA,DIO_u8PIN2,LED_SOURCE,LED_OFF},
		{DIO_u8PORTA,DIO_u8PIN3,LED_SOURCE,LED_OFF}
};
