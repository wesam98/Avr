/*
 * LM_Config.h
 *
 *  Created on: Feb 17, 2024
 *      Author: METRA
 */

#ifndef HAL_LM35_LM_CONFIG_H_
#define HAL_LM35_LM_CONFIG_H_

#include "../../Libirarys/StdTypes.h"

typedef struct
{
	u8 Positive_Channel;
	u8 Negative_Channel;
	u8 Gain;
}LM_t;

#define LM_NUM   1

#endif /* HAL_LM35_LM_CONFIG_H_ */
