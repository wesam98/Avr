/*
 * ADC_Prog.c
 *
 *  Created on: Feb 9, 2024
 *      Author: METRA
 */

#include "../../Libirarys/StdTypes.h"
#include "../../Libirarys/ErrorStates.h"

#include "ADC_Private.h"
#include "ADC_Config.h"

ES_t ADC_enuInit()
{
	ES_t Local_enuErrorState =ES_OK;

	/*select voltage reference for ADC*/

#if VOLT_REF == AREF
	ADMUX &= ~(1<<6);
	ADMUX &= ~(1<<7);

#elif VOLT_REF == AVCC
	ADMUX |= (1<<6);
	ADMUX &= ~(1<<7);

#elif VOLT_REF == INTERNAl
	ADMUX |= (1<<6);
	ADMUX |= (1<<7);
#else
#error"volt reference choice is wrong"
#endif



	/* select result adjust*/
#if ADC_ADJUST == RIGHT
	ADMUX &= ~(1<<5);

#elif ADC_ADJUST == LEFT
	ADMUX |= (1<<5);
#else
#error"Adj Choice is wrong"
#endif


	/*determine division factor of ADC prescaler */
#if ADC_PRES == PRES_2
	ADCSRA |= (1<<0);
	ADCSRA &= ~(1<<1);
	ADCSRA &= ~(1<<2);

#elif ADC_PRES == PRES_4
	ADCSRA &= ~(1<<0);
	ADCSRA |= (1<<1);
	ADCSRA &= ~(1<<2);

#elif ADC_PRES == PRES_8
	ADCSRA |= (1<<0);
	ADCSRA |= (1<<1);
	ADCSRA &= ~(1<<2);

#elif ADC_PRES == PRES_16
	ADCSRA &= ~(1<<0);
	ADCSRA &= ~(1<<1);
	ADCSRA |= (1<<2);

#elif ADC_PRES == PRES_32
	ADCSRA |= (1<<0);
	ADCSRA &= ~(1<<1);
	ADCSRA |= (1<<2);

#elif ADC_PRES == PRES_64
	ADCSRA &= ~(1<<0);
	ADCSRA |= (1<<1);
	ADCSRA |= (1<<2);

#elif ADC_PRES == PRES_128
	ADCSRA |= (1<<0);
	ADCSRA |= (1<<1);
	ADCSRA |= (1<<2);
#else
#error"pres choice is wrong"
#endif

	return Local_enuErrorState;
}


ES_t ADC_enuSelectChannel(u8 Copy_u8PositivePin,u8 Copy_u8CNegativePin,u8 Copy_u8GAIN)
{
	ES_t Local_enuErrorState = ES_NOK;

	ADMUX &= MASK;
	/* if negative pin <0 "invalid pinId" ,user considered Diff mode,
	 * and ifn't user considered Single_Ended mode */
if ( Copy_u8CNegativePin >= 0 )

		ADMUX |= Copy_u8PositivePin;


else if (Copy_u8CNegativePin <0 )
{
		switch(Copy_u8CNegativePin)
		{
		case 0:
			switch(Copy_u8PositivePin)
			{
			case ADC0:
				if(Copy_u8GAIN == 10)
				{
					ADMUX |= (1<<3);
				}
				else if(Copy_u8GAIN == 200)
				{
					ADMUX |= (1<<1);
					ADMUX |= (1<<3);
				}
				else
				{
					Local_enuErrorState = ES_OUT_OF_RANGE;
				}
				break;
			case 1:
				if(Copy_u8GAIN == 10)
				{
					ADMUX |= (1<<0);
					ADMUX |= (1<<3);
				}
				else if(Copy_u8GAIN == 200)
				{
					ADMUX |= (1<<0);
					ADMUX |= (1<<1);
					ADMUX |= (1<<3);
				}
				else
				{
					Local_enuErrorState = ES_OUT_OF_RANGE;
				}
				break;
			default:
				Local_enuErrorState = ES_OUT_OF_RANGE;;
			}
			break;
			case 1:
				switch(Copy_u8PositivePin)
				{
				case ADC0:
					if(Copy_u8GAIN == 1)
					{
						ADMUX |= (1<<4);
					}
					else
					{
						Local_enuErrorState = ES_OUT_OF_RANGE;;
					}
					break;
				case 1:
					if(Copy_u8GAIN == 1)
					{
						ADMUX |= (1<<0);
						ADMUX |= (1<<4);
					}
					else
					{
						Local_enuErrorState = ES_OUT_OF_RANGE;;
					}
					break;
				case 2:
					if(Copy_u8GAIN == 1)
					{
						ADMUX |= (1<<1);
						ADMUX |= (1<<4);
					}
					else
					{
						Local_enuErrorState = ES_OUT_OF_RANGE;;
					}
					break;
				case ADC3:
					if(Copy_u8GAIN == 1)
					{
						ADMUX |= (1<<0);
						ADMUX |= (1<<1);
						ADMUX |= (1<<4);
					}
					else
					{
						Local_enuErrorState = ES_OUT_OF_RANGE;;
					}
					break;
				case ADC4:
					if(Copy_u8GAIN == 1)
					{
						ADMUX |= (1<<2);
						ADMUX |= (1<<4);
					}
					else
					{
						Local_enuErrorState = ES_OUT_OF_RANGE;;
					}
					break;
				case ADC5:
					if(Copy_u8GAIN == 1)
					{
						ADMUX |= (1<<0);
						ADMUX |= (1<<2);
						ADMUX |= (1<<4);
					}
					else
					{
						Local_enuErrorState = ES_OUT_OF_RANGE;;
					}
					break;
				case ADC6:
					if(Copy_u8GAIN == 1)
					{
						ADMUX |= (1<<1);
						ADMUX |= (1<<2);
						ADMUX |= (1<<4);
					}
					else
					{
						Local_enuErrorState = ES_OUT_OF_RANGE;;
					}
					break;

				case ADC7:
					if(Copy_u8GAIN == 1)
					{
						ADMUX |= (1<<0);
						ADMUX |= (1<<1);
						ADMUX |= (1<<2);
						ADMUX |= (1<<4);
					}
					else
					{
						Local_enuErrorState = ES_OUT_OF_RANGE;;
					}
					break;
				default:
					Local_enuErrorState = ES_OUT_OF_RANGE;;
				}
				break;
				case ADC2:
					switch(Copy_u8PositivePin)
					{
					case ADC0:
						if(Copy_u8GAIN == 1)
						{
							ADMUX |= (1<<3);
							ADMUX |= (1<<4);
						}
						else
						{
							Local_enuErrorState = ES_OUT_OF_RANGE;;
						}
						break;
					case ADC1:
						if(Copy_u8GAIN == 1)
						{
							ADMUX |= (1<<0);
							ADMUX |= (1<<3);
							ADMUX |= (1<<4);
						}
						else
						{
							Local_enuErrorState = ES_OUT_OF_RANGE;;
						}
						break;
					case ADC2:
						if(Copy_u8GAIN == 1)
						{
							ADMUX |= (1<<1);
							ADMUX |= (1<<3);
							ADMUX |= (1<<4);
						}
						else if(Copy_u8GAIN == 10)
						{
							ADMUX |= (1<<2);
							ADMUX |= (1<<3);
						}
						else if(Copy_u8GAIN == 200)
						{
							ADMUX |= (1<<1);
							ADMUX |= (1<<2);
							ADMUX |= (1<<3);
						}
						else
						{
							Local_enuErrorState = ES_OUT_OF_RANGE;;
						}
						break;
					case ADC3:
						if(Copy_u8GAIN == 1)
						{
							ADMUX |= (1<<0);
							ADMUX |= (1<<1);
							ADMUX |= (1<<3);
							ADMUX |= (1<<4);
						}
						else if(Copy_u8GAIN == 10)
						{
							ADMUX |= (1<<0);
							ADMUX |= (1<<2);
							ADMUX |= (1<<3);
						}
						else if(Copy_u8GAIN == 200)
						{
							ADMUX |= (1<<0);
							ADMUX |= (1<<1);
							ADMUX |= (1<<2);
							ADMUX |= (1<<3);
						}
						else
						{
							Local_enuErrorState = ES_OUT_OF_RANGE;;
						}
						break;
					case ADC4:
						if(Copy_u8GAIN == 1)
						{
							ADMUX |= (1<<2);
							ADMUX |= (1<<3);
							ADMUX |= (1<<4);
						}
						else
						{
							Local_enuErrorState = ES_OUT_OF_RANGE;;
						}
						break;
					case ADC5:
						if(Copy_u8GAIN == 1)
						{
							ADMUX |= (1<<0);
							ADMUX |= (1<<2);
							ADMUX |= (1<<3);
							ADMUX |= (1<<4);
						}
						else
						{
							Local_enuErrorState = ES_OUT_OF_RANGE;;
						}
						break;
					default:
						Local_enuErrorState = ES_OUT_OF_RANGE;;
					}
					break;
		}
}



	return Local_enuErrorState;
}

void ADC_vidEnableADC()
{
	/*        Enable ADC            */
	ADCSRA |= (1<<7);
}

ES_t ADC_enuStartConversion(s16* Copy_u16ADCRead)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u16ADCRead != NULL)
	{

		/*        start  ADC  conversion              */
		ADCSRA |= (1<<6);

		/*      busy waiting until ADIF get set        */
		while(((ADCSRA  >> 4) & 1) == 0);

		/*    clear  ADIF    */
		ADCSRA &= ~(1<<4);

		/* get read of ADCL and ADCH after conversion  */
#if ADC_ADJUST == RIGHT
		*Copy_u16ADCRead = ADCL;
		*Copy_u16ADCRead |= (ADCH << 8);


#elif ADC_ADJUST == LEFT
		*Copy_u16ADCRead  = (ADCL >> 6);
		*Copy_u16ADCRead |= (ADCH << 2);
#else
#error"ADC ADJUST Choice is wrong"
#endif

	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
