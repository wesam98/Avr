/*
 * EXTI_Init.h
 *
 *  Created on: Feb 5, 2024
 *      Author: METRA
 */

#ifndef HAL_EXTI_EXTI_INIT_H_
#define HAL_EXTI_EXTI_INIT_H_

#include "EXTI_Config.h"

ES_t EXTI_enuInit( EXTI_t *Copy_PArrStr );
ES_t EXTI_enuSeneLevel(u8 Copy_u8EXINTId,u8 Copy_u8SenseLevel);
ES_t EXTI_enuEnable(u8 Copy_u8Id);
ES_t EXTI_enuDisable(u8 Copy_u8Id);
ES_t EXTI_CallBack(void(*ptfunApp)(void), u8 Copy_u8Id);



#endif /* HAL_EXTI_EXTI_INIT_H_ */
