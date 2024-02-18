/*
 * LM_Int.h
 *
 *  Created on: Feb 17, 2024
 *      Author: METRA
 */

#ifndef HAL_LM35_LM_INT_H_
#define HAL_LM35_LM_INT_H_

#include "../../Libirarys/StdTypes.h"
#include "../../Libirarys/ErrorStates.h"

#include "LM_Config.h"

ES_t LM_enuInit(LM_t *Copy_enuPArrstr);
ES_t LM_enuGetTemp(s32 *Copy_S32Read, LM_t *Copy_u8Element);

#endif /* HAL_LM35_LM_INT_H_ */
