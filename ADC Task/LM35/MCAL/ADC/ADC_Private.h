/*
 * ADC_Private.h
 *
 *  Created on: Feb 9, 2024
 *      Author: METRA
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


#include "../../Libirarys/StdTypes.h"
#include "../../MCAL/DIO/DIO_Int.h"

#define ADMUX     *((volatile u8*) 0x27)
#define ADCSRA     *((volatile u8*) 0x26)
#define ADCL     *((volatile u8*) 0x24) // use it to read value of conversion in case of right adjust
#define ADCH     *((volatile u8*) 0x25) //use it to read value of conversion in case of left adjust


#define MASK   0b11100000

#define AREF      0
#define AVCC      1
#define INTERNAl  2

#define RIGHT      10
#define LEFT       12

#define SINGLE_ENDED    1
#define DIFFRENTIAL     2

#define PRES_2         7
#define PRES_4         8
#define PRES_8         9
#define PRES_16        10
#define PRES_32        11
#define PRES_64        12
#define PRES_128       13

#define ADC0       0
#define ADC1       1
#define ADC2       2
#define ADC3       3
#define ADC4       4
#define ADC5       5
#define ADC6       6
#define ADC7       7


#endif /* ADC_PRIVATE_H_ */
