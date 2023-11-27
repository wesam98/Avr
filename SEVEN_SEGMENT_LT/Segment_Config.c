/*
 * Segment_Config.c
 *
 *  Created on: Nov 26, 2023
 *      Author: METRA
 */

#include "Segment_Config.h"
#include "StdTypes.h"
#include "DIO_Config.h"
#include "Segment_Private.h"


SEG_t Segmet_AstrSegConfig[SEG_NUM]=
{
		{ DIO_PIN0, DIO_PORTA , //pin A
		  DIO_PIN1, DIO_PORTA , //pin B
		  DIO_PIN2, DIO_PORTA , //pin C
		  DIO_PIN3, DIO_PORTA , //pin D
		  DIO_PIN4, DIO_PORTA , //pin E
		  DIO_PIN5, DIO_PORTA , //pin F
		  DIO_PIN6, DIO_PORTA , //pin G
		  DIO_PIN7, DIO_PORTA,//Common pin
		  NOT_CONNECTED,NOT_CONNECTED,//Dot pin
		  COMMOM_CATHODE  //type
		},
		{ DIO_PIN0, DIO_PORTA , //pin A
	      DIO_PIN1, DIO_PORTA , //pin B
		  DIO_PIN2, DIO_PORTA , //pin C
		  DIO_PIN3, DIO_PORTA , //pin D
		  DIO_PIN4, DIO_PORTA , //pin E
		  DIO_PIN5, DIO_PORTA , //pin F
		  DIO_PIN6, DIO_PORTA , //pin G
		  DIO_PIN0, DIO_PORTB,//Common pin
		  NOT_CONNECTED,NOT_CONNECTED,//Dot pin
		  COMMOM_CATHODE  //type
		}

		};


