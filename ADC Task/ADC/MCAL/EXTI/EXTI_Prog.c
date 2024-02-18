/*
 * EXTI_Prog.c
 *
 *  Created on: Feb 5, 2024
 *      Author: METRA
 */


#include "../../Libirarys/ErrorStates.h"
#include "../../Libirarys/StdTypes.h"

#include "interrupt.h"

#include "EXTI_Privte.h"
#include "EXTI_Config.h"

static  void(*EXTI_pfunINT[3])(void)={NULL,NULL,NULL};

ES_t EXTI_enuInit( EXTI_t *Copy_PArrStr )
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_PArrStr != NULL)
	{
		u8 Local_u8Iterator;
		for(Local_u8Iterator=0;Local_u8Iterator<3;Local_u8Iterator++)
		{
			if(Copy_PArrStr[Local_u8Iterator].State == Enabled)
			{
				switch (Local_u8Iterator)
				{
				case 0:
					GICR  |= (1<<6);
					MCUCR &= ~(3<<0);
					switch(Copy_PArrStr[Local_u8Iterator].SenseLevel)
					{
					case LOW_LEVEL:
						break;
					case ANY_LOGICAL_CHANGE:
						MCUCR |= (1<<0);
						break;
					case FALLING_EDGE:
						MCUCR |= (1<<1);
						break;
					case RISING_EDGE:
						MCUCR |= (1<<0);
						MCUCR |= (1<<1);
						break;
					default:
						Local_enuErrorState = ES_OUT_OF_RANGE;
					}
					break;
					case 1:
						GICR  |= (1<<7);
						MCUCR &= ~(12<<0);
						switch(Copy_PArrStr[Local_u8Iterator].SenseLevel)
						{
						case LOW_LEVEL:
							break;
						case ANY_LOGICAL_CHANGE:
							MCUCR |= (1<<2);
							break;
						case FALLING_EDGE:
							MCUCR |= (1<<3);
							break;
						case RISING_EDGE:
							MCUCR |= (1<<2);
							MCUCR |= (1<<3);
							break;
						default:
							Local_enuErrorState = ES_OUT_OF_RANGE;
						}
						break;

						case 2:
							GICR   |= (1<<5);
							MCUCSR &= ~(1<<6);
							switch(Copy_PArrStr[Local_u8Iterator].SenseLevel)
							{
							case FALLING_EDGE:
								break;
							case RISING_EDGE:
								MCUCSR |= (1<<6);
								break;
							default:
								Local_enuErrorState = ES_OUT_OF_RANGE;
							}
							GIFR &= ~(1<<5);
							break;

							default:
								Local_enuErrorState = ES_OUT_OF_RANGE;

				}
			}
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;

}
ES_t EXTI_enuSeneLevel(u8 Copy_u8EXINTId,u8 Copy_u8SenseLevel)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8EXINTId < 3)
	{
		if(Copy_u8EXINTId == 0)
		{
			MCUCR &= ~(3<<0);
			switch(Copy_u8SenseLevel)
			{
			case LOW_LEVEL:
				break;
			case ANY_LOGICAL_CHANGE:
				MCUCR |= (1<<0);
				break;
			case FALLING_EDGE:
				MCUCR |= (1<<1);
				break;
			case RISING_EDGE:
				MCUCR |= (1<<0);
				MCUCR |= (1<<1);
				break;
			default:
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
		}
		else if(Copy_u8EXINTId ==1)
		{
			MCUCR &= ~(12<<0);
			switch(Copy_u8SenseLevel)
			{
			case LOW_LEVEL:
				break;
			case ANY_LOGICAL_CHANGE:
				MCUCR |= (1<<2);
				break;
			case FALLING_EDGE:
				MCUCR |= (1<<3);
				break;
			case RISING_EDGE:
				MCUCR |= (1<<2);
				MCUCR |= (1<<3);
				break;
			default:
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
		}
		else if(Copy_u8EXINTId == 2)
		{

			MCUCSR &= ~(1<<6);
			switch(Copy_u8SenseLevel)
			{
			case FALLING_EDGE:
				break;
			case RISING_EDGE:
				MCUCSR |= (1<<6);
				break;
			default:
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
			GIFR &= ~(1<<5);
		}}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
ES_t EXTI_enuEnable(u8 Copy_u8Id)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8Id <3)
	{
		if(Copy_u8Id == 0)
		{
			GICR  |= (1<<6);
		}
		else if(Copy_u8Id == 1)
		{
			GICR  |= (1<<7);
		}
		else if(Copy_u8Id == 2)
		{
			GICR  |= (1<<5);
		}

	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
ES_t EXTI_enuDisable(u8 Copy_u8Id)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8Id <3)
	{
		if(Copy_u8Id == 0)
		{
			GICR  &= ~(1<<6);
		}
		else if(Copy_u8Id == 1)
		{
			GICR  &= ~(1<<7);
		}
		else if(Copy_u8Id == 2)
		{
			GICR  &= ~(1<<5);
		}

	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t EXTI_CallBack(void(*PfunApp)(void) ,u8 Copy_u8Id)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(PfunApp != NULL)
	{
		if
		(Copy_u8Id < 3)
		{
			EXTI_pfunINT[Copy_u8Id] = PfunApp;
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


ISR(VECT_INT0 )
{
	if(EXTI_pfunINT[0] != NULL)
	{
		EXTI_pfunINT[0]();
	}
}

ISR(VECT_INT1)
{
	if(EXTI_pfunINT[1] != NULL)
	{
		EXTI_pfunINT[1]();
	}
}
