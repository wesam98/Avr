/*
 * GIE_Prog.c
 *
 *  Created on: Feb 5, 2024
 *      Author: METRA
 */


#include "../../Libirarys/ErrorStates.h"
#include "../../Libirarys/StdTypes.h"

#include "GIE_privte.h"
ES_t GIE_enuEnable()
{
	ES_t Local_enuErrorState = ES_NOK;
     SREG_REG |= (1<<7);
	return Local_enuErrorState;

}
ES_t GIE_enuDisable()
{
	ES_t Local_enuErrorState = ES_NOK;

     SREG_REG &= ~(1<<7);

	return Local_enuErrorState;

}
