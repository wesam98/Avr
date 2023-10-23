/*
 * Switch_Prog.c
 *
 *  Created on: Oct 21, 2023
 *      Author: METRA
 */

#ifndef SWITCH_PROG_C_
#define SWITCH_PROG_C_

#include "StdTypes.h"
#include "ErrorStates.h"

#include  "Switch_Private.h"
#include  "DIO_Int.h"
#include  "DIO_Private.h"
#include  "Switch_Cinfig.h"


ES_t SWITCH_enuSwInit(SW_t *Copy_PAstrSwitches)
{
	ES_t Local_ErrorState = ES_NOK;
	if(Copy_PAstrSwitches != NULL)
	{
		u8 Local_Iterator;
		for(Local_Iterator = 0;Local_Iterator <SW_NUM;Local_Iterator++)
		{
			 Local_ErrorState = DIO_enuSetPinDirection(Copy_PAstrSwitches[Local_Iterator].SW_PORT_ID,Copy_PAstrSwitches[Local_Iterator].SW_PIN_ID,DIO_u8INPUT);
			 Local_ErrorState = DIO_enuSetPinValue(Copy_PAstrSwitches[Local_Iterator].SW_PORT_ID,Copy_PAstrSwitches[Local_Iterator].SW_PIN_ID,Copy_PAstrSwitches[Local_Iterator].SW_STATUS);
		}

    }
	else
	{
	 	Local_ErrorState=ES_NULL_POINTER;
	}
	return Local_ErrorState;
}
ES_t SWITCH_enuSwState(SW_t *Copy_PAstrSwitches, u8 *Copy_u8SwState)
{    ES_t Local_ErrorState = ES_NOK;

	if(Copy_PAstrSwitches != NULL && Copy_u8SwState != NULL)
	{
		ES_t Local_ErrorState = DIO_enuGetPinValue(Copy_PAstrSwitches->SW_PORT_ID ,Copy_PAstrSwitches->SW_PIN_ID,Copy_u8SwState);
	  if(Copy_PAstrSwitches->SW_STATUS==DIO_u8PULL_UP)
		   *Copy_u8SwState =! *Copy_u8SwState;
	}
	else
	{
		Local_ErrorState=ES_NULL_POINTER;
	}
	return Local_ErrorState;
}

#endif /* SWITCH_PROG_C_ */
