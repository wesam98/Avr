/*
 * ADC_Init.h
 *
 *  Created on: Feb 9, 2024
 *      Author: METRA
 */

#ifndef ADC_INIT_H_
#define ADC_INIT_H_

#include "../../Libirarys/ErrorStates.h"
#include "../../Libirarys/StdTypes.h"

ES_t ADC_enuInit();
ES_t ADC_enuSelectChannel(u8 Copy_u8PositivePin,u8 Copy_u8CNegativePin,u8 Copy_u8GAIN);
void ADC_vidEnableADC();
ES_t ADC_enuStartConversion(u16* Copy_u16ADCRead);



#endif /* ADC_INIT_H_ */
