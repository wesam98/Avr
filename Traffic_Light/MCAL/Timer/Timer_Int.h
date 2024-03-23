/*
 * Timer_Int.h
 *
 *  Created on: Feb 22, 2024
 *      Author: METRA
 */

#ifndef TIMER_INT_H_
#define TIMER_INT_H_

#include "../../Libirarys/ErrorStates.h"
#include "../../Libirarys/StdTypes.h"


#include "Timer_Config.h"


ES_t Timer_enuInit(void);

ES_t Timer_enuSetAsychDelay(u32 Copy_u32DesiredTime_ms ,void(*Copy_Pfn)(void));
ES_t Timer_enuSetPreload(u32 Copy_u32PreloadValue);
ES_t Timer_enuSetSynchDelay(u32 Copy_u32DesiredTime_ms );


#endif /* TIMER_INT_H_ */
