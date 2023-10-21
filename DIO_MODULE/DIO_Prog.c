/*
 * DIO_Prog.c
 *
 *  Created on: Oct 19, 2023
 *      Author: METRA
 */


#include "StdTypes.h"
#include "ErrorState.h"

#include "DIO_Private.h"
#include "DIO_config.h"

ES_t DIO_enuInit(void)
{
	ES_t Local_enuErrorState=ES_NOK;

	DDRA = CONC(PA_PIN7_DIR,PA_PIN6_DIR,PA_PIN5_DIR,PA_PIN4_DIR,PA_PIN3_DIR,PA_PIN2_DIR,PA_PIN1_DIR,PA_PIN0_DIR);
	DDRB = CONC(PB_PIN7_DIR,PB_PIN6_DIR,PB_PIN5_DIR,PB_PIN4_DIR,PB_PIN3_DIR,PB_PIN2_DIR,PB_PIN1_DIR,PB_PIN0_DIR);
	DDRB = CONC(PC_PIN7_DIR,PC_PIN6_DIR,PC_PIN5_DIR,PC_PIN4_DIR,PC_PIN3_DIR,PC_PIN2_DIR,PC_PIN1_DIR,PC_PIN0_DIR);
	DDRB = CONC(PD_PIN7_DIR,PD_PIN6_DIR,PD_PIN5_DIR,PD_PIN4_DIR,PD_PIN3_DIR,PD_PIN2_DIR,PD_PIN1_DIR,PD_PIN0_DIR);

	PORTA = CONC(PA_PIN7_VAL,PA_PIN6_VAL,PA_PIN5_VAL,PA_PIN4_VAL,PA_PIN3_VAL,PA_PIN2_VAL,PA_PIN1_VAL,PA_PIN0_VAL);
	PORTB = CONC(PB_PIN7_VAL,PB_PIN6_VAL,PB_PIN5_VAL,PB_PIN4_VAL,PB_PIN3_VAL,PB_PIN2_VAL,PB_PIN1_VAL,PB_PIN0_VAL);
	PORTA = CONC(PC_PIN7_VAL,PC_PIN6_VAL,PC_PIN5_VAL,PC_PIN4_VAL,PC_PIN3_VAL,PC_PIN2_VAL,PC_PIN1_VAL,PC_PIN0_VAL);
	PORTA = CONC(PD_PIN7_VAL,PD_PIN6_VAL,PD_PIN5_VAL,PD_PIN4_VAL,PD_PIN3_VAL,PD_PIN2_VAL,PD_PIN1_VAL,PD_PIN0_VAL);


	return Local_enuErrorState=ES_OK;
}

ES_t DIO_enuSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8Direction)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_u8PortId <= DIO_PORTD)
	{
		switch(Copy_u8PortId)
		{
		case(DIO_PORTA):
		{
			DDRA = Copy_u8Direction;
			break;
		}
		case(DIO_PORTB):
				{
					DDRB = Copy_u8Direction;
					break;
				}
		case(DIO_PORTC):
				{
					DDRC = Copy_u8Direction;
					break;
				}
		case(DIO_PORTD):
				{
					DDRD= Copy_u8Direction;
					break;
				}
		}
		Local_enuErrorState=ES_OK;

	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t DIO_enuSetPortValue(u8 Copy_u8PortId, u8 Copy_u8Value)
{
	ES_t Local_enuErrorState=ES_NOK;

	if(Copy_u8PortId <= DIO_PORTD)
		{
			switch(Copy_u8PortId)
			{
			case(DIO_PORTA):
			{
				PORTA = Copy_u8Value;
				break;
			}
			case(DIO_PORTB):
					{
						PORTB = Copy_u8Value;
						break;
					}
			case(DIO_PORTC):
					{
						PORTC = Copy_u8Value;
						break;
					}
			case(DIO_PORTD):
					{
						PORTD= Copy_u8Value;
						break;
					}
			}
			Local_enuErrorState=ES_OK;

		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

	return Local_enuErrorState;
}

ES_t DIO_enuGetPortValue(u8 Copy_u8PortID, u8 * Copy_pu8Value)
{
	ES_t Local_enuErrorState = ES_NOK;


	if (Copy_pu8Value != NULL)
	{
		if (Copy_u8PortID <= DIO_PORTD)
		{
			switch (Copy_u8PortID)
			{
			case DIO_PORTA:
				*Copy_pu8Value = PINA;
				break;
			case DIO_PORTB:
				*Copy_pu8Value = PINB;
				break;
			case DIO_PORTC:
				*Copy_pu8Value = PINC;
				break;
			case DIO_PORTD:
				*Copy_pu8Value = PIND;
				break;
			}
			Local_enuErrorState = ES_OK;
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

ES_t DIO_enuTogglePortValue(u8 Copy_u8PortId)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_u8PortId <= DIO_PORTD)
			{
				switch(Copy_u8PortId)
				{
				case(DIO_PORTA):
				{
					PORTA = ~PORTA ;
					break;
				}
				case(DIO_PORTB):
						{
							PORTB = ~PORTB;
							break;
						}
				case(DIO_PORTC):
						{
							PORTC = ~PORTC;
							break;
						}
				case(DIO_PORTD):
						{
							PORTD= ~PORTD;
							break;
						}
				}
				Local_enuErrorState=ES_OK;

			}
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}



	return Local_enuErrorState;
}

ES_t DIO_enuSetBitDirection (u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_u8PortId<=DIO_PORTD && Copy_u8PinId<= DIO_PIN7 && Copy_u8Value<=1 )
		{

		switch(Copy_u8PortId)
		{
		case(DIO_PORTA):
		{
			DDRA &=~(DIO_BIT_MASK<<Copy_u8PinId) ;
			DDRA |=(Copy_u8Value<<Copy_u8PinId);
			break;
		}
		case(DIO_PORTB):
		{
		     DDRB &=~(DIO_BIT_MASK<<Copy_u8PinId);
		     DDRB |=(Copy_u8Value<<Copy_u8PinId);
		     break;
		}
					break;

		case(DIO_PORTC):
		{
			 DDRC &=~(DIO_BIT_MASK<<Copy_u8PinId);
		     DDRC |=(Copy_u8Value<<Copy_u8PinId);
					break;
		}
		case(DIO_PORTD):
		{
			 DDRD &=~(DIO_BIT_MASK<<Copy_u8PinId);
			 DDRD |=(Copy_u8Value<<Copy_u8PinId);
					break;
	    }
		}
		Local_enuErrorState=ES_OK;
		}
		else
		{
			Local_enuErrorState=ES_OUT_OF_RANGE;
		}

	return Local_enuErrorState;
}

ES_t DIO_enuSetBitValue (u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_u8PortId<=DIO_PORTD && Copy_u8PinId<= DIO_PIN7 && Copy_u8Value<=1 )
	{
		switch(Copy_u8PortId)
				{
				case(DIO_PORTA):
				{
					PORTA &=~(DIO_BIT_MASK<<Copy_u8PinId) ;
					PORTA |=(Copy_u8Value<<Copy_u8PinId);
					break;
				}
				case(DIO_PORTB):
				{
				     PORTB &=~(DIO_BIT_MASK<<Copy_u8PinId);
				     PORTB |=(Copy_u8Value<<Copy_u8PinId);
				     break;
				}
							break;

				case(DIO_PORTC):
				{
					 PORTC &=~(DIO_BIT_MASK<<Copy_u8PinId);
				     PORTC |=(Copy_u8Value<<Copy_u8PinId);
							break;
				}
				case(DIO_PORTD):
				{
					 PORTD &=~(DIO_BIT_MASK<<Copy_u8PinId);
					 PORTD |=(Copy_u8Value<<Copy_u8PinId);
							break;
			    }
				}
				Local_enuErrorState=ES_OK;
				}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t DIO_enuGetBitValue (u8 Copy_u8PortId, u8 Copy_u8PinId, u8* Copy_Pu8Value)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_Pu8Value != NULL)
	{
		if(Copy_u8PortId<=DIO_PORTD && Copy_u8PinId<= DIO_PIN7 )
		{
			switch(Copy_u8PortId)
									{
									case(DIO_PORTA):
									{
										* Copy_Pu8Value=((PINA>>Copy_u8PinId)& DIO_BIT_MASK);

										break;
									}
									case(DIO_PORTB):
									{
										* Copy_Pu8Value=((PINA>>Copy_u8PinId)& DIO_BIT_MASK);
									     break;
									}
												break;

									case(DIO_PORTC):
									{
										* Copy_Pu8Value=((PINA>>Copy_u8PinId)& DIO_BIT_MASK);
												break;
									}
									case(DIO_PORTD):
									{
										* Copy_Pu8Value=((PINA>>Copy_u8PinId)& DIO_BIT_MASK);
												break;
								    }
									}
									Local_enuErrorState=ES_OK;
		}
		else
		{
			 Local_enuErrorState=ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState= ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}

ES_t DIO_enuToggleBitValue (u8 Copy_u8PortId, u8 Copy_u8PinId)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_u8PortId<=DIO_PORTD && Copy_u8PinId<= DIO_PIN7 )
	{
		switch(Copy_u8PortId)
						{
						case(DIO_PORTA):
						{
							PORTA ^=(DIO_BIT_MASK<<Copy_u8PinId) ;
							break;
						}
						case(DIO_PORTB):
						{
						     PORTB ^=(DIO_BIT_MASK<<Copy_u8PinId);
						     break;
						}
									break;

						case(DIO_PORTC):
						{
							 PORTC ^=(DIO_BIT_MASK<<Copy_u8PinId);
									break;
						}
						case(DIO_PORTD):
						{
							 PORTD ^=(DIO_BIT_MASK<<Copy_u8PinId);
									break;
					    }
						}
						Local_enuErrorState=ES_OK;
	}
	else
	{
		Local_enuErrorState=ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}
