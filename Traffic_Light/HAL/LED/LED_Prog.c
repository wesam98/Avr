/*
 * LED_Prog.c
 *
 *  Created on: Oct 27, 2023
 *      Author: METRA
 */

#include "../../Libirarys/StdTypes.h"
#include "../../Libirarys/ErrorStates.h"

#include "../../MCAL/DIO/DIO_Int.h"

#include "LED_Config.h"
#include "LED_Private.h"

ES_t LED_enuInit(LED_t* Copy_PAstrLedConfig)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_PAstrLedConfig != NULL)
	{
		u8 Local_u8Iterator=0;
		for(Local_u8Iterator=0 ; Local_u8Iterator<LED_NUM ; Local_u8Iterator++)
		{
			Local_enuErrorState = DIO_enuSetPinDirection(Copy_PAstrLedConfig[Local_u8Iterator].LED_u8PORTID , Copy_PAstrLedConfig[Local_u8Iterator].LED_u8PINID,DIO_u8OUTPUT);

			if(Copy_PAstrLedConfig[Local_u8Iterator].LED_u8CONNECTION == LED_SOURCE)
			{
				if(Copy_PAstrLedConfig[Local_u8Iterator].LED_u8InitialState == LED_ON)
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_PAstrLedConfig[Local_u8Iterator].LED_u8PORTID , Copy_PAstrLedConfig[Local_u8Iterator].LED_u8PINID,DIO_u8HIGH);
				}
				else if(Copy_PAstrLedConfig[Local_u8Iterator].LED_u8InitialState == LED_OFF)
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_PAstrLedConfig[Local_u8Iterator].LED_u8PORTID , Copy_PAstrLedConfig[Local_u8Iterator].LED_u8PINID,DIO_u8LOW);
				}
				else
				{
					return ES_OUT_OF_RANGE;
				}
			}
			else if(Copy_PAstrLedConfig[Local_u8Iterator].LED_u8CONNECTION == LED_SINK)
			{
				if(Copy_PAstrLedConfig[Local_u8Iterator].LED_u8InitialState == LED_ON)
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_PAstrLedConfig[Local_u8Iterator].LED_u8PORTID , Copy_PAstrLedConfig[Local_u8Iterator].LED_u8PINID,DIO_u8LOW);
				}
				else if(Copy_PAstrLedConfig[Local_u8Iterator].LED_u8InitialState == LED_OFF)
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_PAstrLedConfig[Local_u8Iterator].LED_u8PORTID , Copy_PAstrLedConfig[Local_u8Iterator].LED_u8PINID,DIO_u8HIGH);
				}
				else
				{
					return ES_OUT_OF_RANGE;
				}
			}
			else
			{
				return ES_OUT_OF_RANGE;
			}
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}

ES_t LED_enuLedON(LED_t* Copy_PstrLedID)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_PstrLedID != NULL)
	{
		if(Copy_PstrLedID->LED_u8CONNECTION == LED_SOURCE)
		{
			Local_enuErrorState = DIO_enuSetPinValue(Copy_PstrLedID->LED_u8PORTID,Copy_PstrLedID->LED_u8PINID,DIO_u8HIGH);
		}
		else if(Copy_PstrLedID->LED_u8CONNECTION == LED_SINK)
		{
			Local_enuErrorState = DIO_enuSetPinValue(Copy_PstrLedID->LED_u8PORTID,Copy_PstrLedID->LED_u8PINID,DIO_u8LOW);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}


ES_t LED_enuLedOFF(LED_t* Copy_PstrLedID)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_PstrLedID != NULL)
	{
		if(Copy_PstrLedID->LED_u8CONNECTION == LED_SOURCE)
		{
			Local_enuErrorState = DIO_enuSetPinValue(Copy_PstrLedID->LED_u8PORTID,Copy_PstrLedID->LED_u8PINID,DIO_u8LOW);
		}
		else if(Copy_PstrLedID->LED_u8CONNECTION == LED_SINK)
		{
			Local_enuErrorState = DIO_enuSetPinValue(Copy_PstrLedID->LED_u8PORTID,Copy_PstrLedID->LED_u8PINID,DIO_u8HIGH);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}

