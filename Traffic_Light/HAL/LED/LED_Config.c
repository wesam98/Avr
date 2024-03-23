/*
 * LED_Config.c
 *
 *  Created on: Oct 27, 2023
 *      Author: METRA
 */

#include "../../Libirarys/ErrorStates.h"
#include "../../Libirarys/StdTypes.h"

#include"../../MCAL/DIO/DIO_int.h"
#include "LED_Private.h"
#include "LED_Config.h"

// CAR ---> GREEN ,YELLOW ,RED
// pedestrian --> GREEN ,YELLOW ,RED
LED_t LED_AstrLedConfig [LED_NUM]={
		{DIO_u8PORTC,DIO_u8PIN0,LED_SOURCE,LED_OFF},
		{DIO_u8PORTC,DIO_u8PIN1,LED_SOURCE,LED_OFF},
		{DIO_u8PORTC,DIO_u8PIN2,LED_SOURCE,LED_OFF},
		{DIO_u8PORTC,DIO_u8PIN3,LED_SOURCE,LED_OFF},
		{DIO_u8PORTC,DIO_u8PIN4,LED_SOURCE,LED_OFF},
		{DIO_u8PORTC,DIO_u8PIN5,LED_SOURCE,LED_OFF},
};
