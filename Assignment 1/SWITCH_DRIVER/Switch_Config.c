/*
 * Switch_Config.c
 *
 *  Created on: Oct 21, 2023
 *      Author: METRA
 */
#include "StdTypes.h"
#include "ErrorStates.h"

#include "Switch_Private.h"
#include "DIO_Int.h"
#include "Switch_Cinfig.h"

SW_t SWITCH_AstrSWStatus [SW_NUM]={
		{DIO_u8PORTA,DIO_u8PIN1,DIO_u8FLOAT},
		{DIO_u8PORTB,DIO_u8PIN3,DIO_u8PULL_UP},
		{DIO_u8PORTB,DIO_u8PIN2,DIO_u8PULL_UP}

};



