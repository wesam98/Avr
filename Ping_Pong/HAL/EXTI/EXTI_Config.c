/*
 * EXTI_Config.c
 *
 *  Created on: Feb 5, 2024
 *      Author: METRA
 */

#include "../../Libirarys/ErrorStates.h"
#include "../../Libirarys/StdTypes.h"

#include "EXTI_Config.h"
#include "EXTI_Privte.h"

EXTI_t EXTI_ArrStr[3]={
		{Enabled,ANY_LOGICAL_CHANGE},
		{Enabled,ANY_LOGICAL_CHANGE},
		{Disabled}

};
