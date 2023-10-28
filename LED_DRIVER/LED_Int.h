/*
 * LED_Int.h
 *
 *  Created on: Oct 27, 2023
 *      Author: METRA
 */

#ifndef LED_INT_H_
#define LED_INT_H_

#include "StdTypes.h"
#include "Error_States.h"
#include "DIO_Int.h"
#include "LED_Private.h"

ES_t LED_enuInit(LED_t* Copy_PAstrLedConfig);
ES_t LED_enuLedON(LED_t* Copy_PstrLedID);
ES_t LED_enuLedOFF(LED_t* Copy_PstrLedID);

#endif /* LED_INT_H_ */
