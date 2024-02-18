/*
 * ADC_Config.h
 *
 *  Created on: Feb 9, 2024
 *      Author: METRA
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_



/*Choose prescaler factor*/
#define ADC_PRES     PRES_8

/* Choose volt reference
 *  AREF or INTERNAl or AVCC  */
#define VOLT_REF     AVCC

/*choose style of result adjustment
 *  either RIGHT or LEFT */
#define ADC_ADJUST  RIGHT



#endif /* ADC_CONFIG_H_ */
