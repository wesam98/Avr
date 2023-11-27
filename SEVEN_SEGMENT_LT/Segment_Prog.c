/*
 * Segment_Prog.c
 *
 *  Created on: Nov 25, 2023
 *      Author: METRA
 */



#include "StdTypes.h"
#include "ErrorStates.h"

#include "DIO_Int.h"
#include "Segment_int.h"
#include "Segment_Private.h"


extern SEG_t Segmet_AstrSegConfig[SEG_NUM];


ES_t Segment_enuIniti(SEG_t *Copy_PAStrSegConfig)
{
	ES_t Local_ErrorState = ES_NOK;
	if(Copy_PAStrSegConfig != NULL)
	{ u8 Local_u8Iterator;
	for(Local_u8Iterator=0;Local_u8Iterator<SEG_NUM;Local_u8Iterator++)
	{
		Local_ErrorState = DIO_enuSetPinDirection(Copy_PAStrSegConfig[Local_u8Iterator].SEG_APORT,Copy_PAStrSegConfig[Local_u8Iterator].SEG_APIN,DIO_u8OUTPUT);
		Local_ErrorState = DIO_enuSetPinDirection(Copy_PAStrSegConfig[Local_u8Iterator].SEG_BPORT,Copy_PAStrSegConfig[Local_u8Iterator].SEG_BPIN,DIO_u8OUTPUT);
		Local_ErrorState = DIO_enuSetPinDirection(Copy_PAStrSegConfig[Local_u8Iterator].SEG_CPORT,Copy_PAStrSegConfig[Local_u8Iterator].SEG_CPIN,DIO_u8OUTPUT);
		Local_ErrorState = DIO_enuSetPinDirection(Copy_PAStrSegConfig[Local_u8Iterator].SEG_DPORT,Copy_PAStrSegConfig[Local_u8Iterator].SEG_DPIN,DIO_u8OUTPUT);
		Local_ErrorState = DIO_enuSetPinDirection(Copy_PAStrSegConfig[Local_u8Iterator].SEG_EPORT,Copy_PAStrSegConfig[Local_u8Iterator].SEG_EPIN,DIO_u8OUTPUT);
		Local_ErrorState = DIO_enuSetPinDirection(Copy_PAStrSegConfig[Local_u8Iterator].SEG_FPORT,Copy_PAStrSegConfig[Local_u8Iterator].SEG_FPIN,DIO_u8OUTPUT);
		Local_ErrorState = DIO_enuSetPinDirection(Copy_PAStrSegConfig[Local_u8Iterator].SEG_GPORT,Copy_PAStrSegConfig[Local_u8Iterator].SEG_GPIN,DIO_u8OUTPUT);

		if(Copy_PAStrSegConfig[Local_u8Iterator].SEG_COMMONPORT != NOT_CONNECTED && Copy_PAStrSegConfig[Local_u8Iterator].SEG_COMMONPIN != NOT_CONNECTED )
		{
			Local_ErrorState = DIO_enuSetPinDirection(Copy_PAStrSegConfig[Local_u8Iterator].SEG_COMMONPORT,Copy_PAStrSegConfig[Local_u8Iterator].SEG_COMMONPIN,DIO_u8OUTPUT);
		}
		if(Copy_PAStrSegConfig[Local_u8Iterator].SEG_DOTPORT != NOT_CONNECTED && Copy_PAStrSegConfig[Local_u8Iterator].SEG_DOTPIN != NOT_CONNECTED )
        {
			Local_ErrorState = DIO_enuSetPinDirection(Copy_PAStrSegConfig[Local_u8Iterator].SEG_DOTPORT,Copy_PAStrSegConfig[Local_u8Iterator].SEG_DOTPIN,DIO_u8OUTPUT);
		}
	}

	}
	else
	{
		Local_ErrorState = ES_NULL_POINTER;
	}
	return Local_ErrorState;
}
ES_t Segment_enuDisplay(u8 Copy_u8SegID,u8 Copy_u8num)
{
	ES_t Local_ErrorState = ES_NOK;
	if(Copy_u8SegID <SEG_NUM && Copy_u8num<10 )
	{
		if(Segmet_AstrSegConfig[Copy_u8SegID].SEG_TYPE == COMMOM_CATHODE)
		{
			Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_APORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_APIN,((SEG_Au8Display[Copy_u8num]>>0)&1));
			Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_BPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_BPIN,((SEG_Au8Display[Copy_u8num]>>1)&1));
			Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_CPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_CPIN,((SEG_Au8Display[Copy_u8num]>>2)&1));
			Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_DPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_DPIN,((SEG_Au8Display[Copy_u8num]>>3)&1));
			Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_EPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_EPIN,((SEG_Au8Display[Copy_u8num]>>4)&1));
			Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_FPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_FPIN,((SEG_Au8Display[Copy_u8num]>>5)&1));
			Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_GPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_GPIN,((SEG_Au8Display[Copy_u8num]>>6)&1));
		}
		else if(Segmet_AstrSegConfig[Copy_u8SegID].SEG_TYPE == COMMOM_ANODE)
		{
			Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_APORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_APIN,!((SEG_Au8Display[Copy_u8num]>>0)&1));
			Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_BPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_BPIN,!((SEG_Au8Display[Copy_u8num]>>1)&1));
			Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_CPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_CPIN,!((SEG_Au8Display[Copy_u8num]>>2)&1));
			Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_DPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_DPIN,!((SEG_Au8Display[Copy_u8num]>>3)&1));
			Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_EPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_EPIN,!((SEG_Au8Display[Copy_u8num]>>4)&1));
			Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_FPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_FPIN,!((SEG_Au8Display[Copy_u8num]>>5)&1));
			Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_GPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_GPIN,!((SEG_Au8Display[Copy_u8num]>>6)&1));
		}
	}
	else
	{
		Local_ErrorState = ES_OUT_OF_RANGE;
	}
	return Local_ErrorState;
}
ES_t Segment_enuEnableCommon(u8 Copy_u8SegID)
{
	ES_t Local_ErrorState = ES_NOK;

	if(Copy_u8SegID < SEG_NUM)
	{ if(Segmet_AstrSegConfig[Copy_u8SegID].SEG_COMMONPORT != NOT_CONNECTED && Segmet_AstrSegConfig[Copy_u8SegID].SEG_COMMONPIN != NOT_CONNECTED  )
	{
		if(Segmet_AstrSegConfig[Copy_u8SegID].SEG_TYPE == COMMOM_CATHODE)
		{
			Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_COMMONPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_COMMONPIN,DIO_u8LOW);
		}
		else if(Segmet_AstrSegConfig[Copy_u8SegID].SEG_TYPE == COMMOM_ANODE)
		{
			Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_COMMONPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_COMMONPIN,DIO_u8HIGH);
		}
	}}
	else
	{
	 Local_ErrorState =ES_OUT_OF_RANGE;
	}
	return Local_ErrorState;
}
ES_t Segment_enuDisableCommon(u8 Copy_u8SegID)
{
	ES_t Local_ErrorState = ES_NOK;
	if(Copy_u8SegID < SEG_NUM)
	  {
		if(Segmet_AstrSegConfig[Copy_u8SegID].SEG_COMMONPORT != NOT_CONNECTED && Segmet_AstrSegConfig[Copy_u8SegID].SEG_COMMONPIN != NOT_CONNECTED  )
			{
			if(Segmet_AstrSegConfig[Copy_u8SegID].SEG_TYPE == COMMOM_CATHODE)
			{
				Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_COMMONPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_COMMONPIN,DIO_u8HIGH);
			}
			else if(Segmet_AstrSegConfig[Copy_u8SegID].SEG_TYPE == COMMOM_ANODE)
			{
				Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_COMMONPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_COMMONPIN,DIO_u8LOW);
			}
		    }
		}
		else
		{
		 Local_ErrorState =ES_OUT_OF_RANGE;
		}
	return Local_ErrorState;
}
ES_t Segment_enuEnableDot(u8 Copy_u8SegID)
{
	ES_t Local_ErrorState = ES_NOK;
	if(Copy_u8SegID < SEG_NUM)
		{
		if(Segmet_AstrSegConfig[Copy_u8SegID].SEG_DOTPORT != NOT_CONNECTED && Segmet_AstrSegConfig[Copy_u8SegID].SEG_DOTPIN != NOT_CONNECTED  )
			{
			if(Segmet_AstrSegConfig[Copy_u8SegID].SEG_TYPE == COMMOM_CATHODE)
			{
				Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_DOTPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_DOTPIN,DIO_u8HIGH);
			}
			else if(Segmet_AstrSegConfig[Copy_u8SegID].SEG_TYPE == COMMOM_ANODE)
			{
				Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_DOTPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_DOTPIN,DIO_u8LOW);
			}
		    }
		}
		else
		{
		 Local_ErrorState =ES_OUT_OF_RANGE;
		}
	return Local_ErrorState;
}
ES_t Segment_enuDisableDot(u8 Copy_u8SegID)
{
	ES_t Local_ErrorState = ES_NOK;
	if(Copy_u8SegID < SEG_NUM)
			{
		if(Segmet_AstrSegConfig[Copy_u8SegID].SEG_DOTPORT != NOT_CONNECTED && Segmet_AstrSegConfig[Copy_u8SegID].SEG_DOTPIN != NOT_CONNECTED  )
			{
				if(Segmet_AstrSegConfig[Copy_u8SegID].SEG_TYPE == COMMOM_CATHODE)
				{
					Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_DOTPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_DOTPIN,DIO_u8LOW);
				}
				else if(Segmet_AstrSegConfig[Copy_u8SegID].SEG_TYPE == COMMOM_ANODE)
				{
					Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_DOTPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_DOTPIN,DIO_u8HIGH);
				}
			}
			}
			else
			{
			 Local_ErrorState =ES_OUT_OF_RANGE;
			}
	return Local_ErrorState;
}
ES_t Segment_enuClear(u8 Copy_u8SegID)
{
	ES_t Local_ErrorState = ES_NOK;
	if(Copy_u8SegID <SEG_NUM )
		{
			if(Segmet_AstrSegConfig[Copy_u8SegID].SEG_TYPE == COMMOM_CATHODE)
			{
				Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_APORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_APIN,DIO_u8LOW);
				Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_BPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_BPIN,DIO_u8LOW);
				Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_CPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_CPIN,DIO_u8LOW);
				Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_DPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_DPIN,DIO_u8LOW);
				Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_EPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_EPIN,DIO_u8LOW);
				Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_FPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_FPIN,DIO_u8LOW);
				Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_GPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_GPIN,DIO_u8LOW);
			}
			else if(Segmet_AstrSegConfig[Copy_u8SegID].SEG_TYPE == COMMOM_ANODE)
			{
				Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_APORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_APIN,DIO_u8LOW);
				Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_BPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_BPIN,DIO_u8LOW);
				Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_CPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_CPIN,DIO_u8LOW);
				Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_DPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_DPIN,DIO_u8LOW);
				Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_EPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_EPIN,DIO_u8LOW);
				Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_FPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_FPIN,DIO_u8LOW);
				Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_GPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_GPIN,DIO_u8LOW);
			}
			if(Segmet_AstrSegConfig[Copy_u8SegID].SEG_DOTPORT !=NOT_CONNECTED && Segmet_AstrSegConfig[Copy_u8SegID].SEG_DOTPIN != NOT_CONNECTED )
			{
				Local_ErrorState = DIO_enuSetPinValue(Segmet_AstrSegConfig[Copy_u8SegID].SEG_DOTPORT,Segmet_AstrSegConfig[Copy_u8SegID].SEG_DOTPIN,DIO_u8LOW);
			}
		}
		else
		{
			Local_ErrorState = ES_OUT_OF_RANGE;
		}
	return Local_ErrorState;
}
