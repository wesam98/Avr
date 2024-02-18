/*
 * LM_Prog.c
 *
 *  Created on: Feb 17, 2024
 *      Author: METRA
 */


#include "../../Libirarys/ErrorStates.h"
#include "../../Libirarys/StdTypes.h"

#include "../../MCAL/ADC/ADC_Init.h"
#include "../../MCAL/DIO/DIO_Int.h"

#include "LM_Private.h"
#include "LM_Config.h"



ES_t LM_enuInit(LM_t  *Copy_enuPArrstr)
{
	ES_t Local_enuErrorState = ES_NOK;
	if( Copy_enuPArrstr != NULL)
	{
		ADC_enuInit();
		u8 Local_u8Iter;
		for(Local_u8Iter=0 ; Local_u8Iter<LM_NUM ; Local_u8Iter++)
		{
			DIO_enuSetPinDirection(DIO_u8PORTA,Copy_enuPArrstr[Local_u8Iter].Positive_Channel,DIO_u8INPUT);

			if(Copy_enuPArrstr[Local_u8Iter].Negative_Channel != NOT_CONNECTED )
			{
				DIO_enuSetPinDirection(DIO_u8PORTA,Copy_enuPArrstr[Local_u8Iter].Negative_Channel,DIO_u8INPUT);
			}
		}


	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;



}
ES_t LM_enuGetTemp(s32 *Copy_s32Temp,LM_t *Copy_enuElement)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_enuElement != NULL)
	{
		s16 Local_u16Read;

		ADC_enuSelectChannel( Copy_enuElement->Positive_Channel,Copy_enuElement->Negative_Channel,Copy_enuElement->Gain);

		DIO_enuSetPinDirection(DIO_u8PORTA,Copy_enuElement->Positive_Channel,DIO_u8INPUT);

		if(Copy_enuElement->Negative_Channel != NOT_CONNECTED )
		{
			DIO_enuSetPinDirection(DIO_u8PORTA,Copy_enuElement->Negative_Channel,DIO_u8INPUT);
		}
		ADC_vidEnableADC();
		ADC_enuStartConversion(& Local_u16Read);

		*Copy_s32Temp = Local_u16Read*4.88*.1;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
