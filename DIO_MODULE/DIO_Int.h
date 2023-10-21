/*
 * DIO_Int.h
 *
 *  Created on: Oct 19, 2023
 *      Author: METRA
 */


#ifndef DIO_INT_H_
#define DIO_INT_H_

#define DIO_u8PORTA    0
#define DIO_u8PORTB    1
#define DIO_u8PORTC    2
#define DIO_u8PORTD    3

#define DIO_u8_PIN0    0
#define DIO_u8_PIN1    1
#define DIO_u8_PIN2    2
#define DIO_u8_PIN3    3
#define DIO_u8_PIN4    4
#define DIO_u8_PIN5    5
#define DIO_u8_PIN6    6
#define DIO_u8_PIN7    7

#define DIO_u8OUTPUT   1
#define DIO_u8INPUT    0

#define DIO_u8HIGH     1
#define DIO_u8LOW      0

#define DIO_u8FLOAT    0
#define DIO_u8PULL_UP  1


ES_t DIO_enuu8_Pnit(void);

ES_t DIO_enuSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8Direction);

ES_t DIO_enuSetPortValue(u8 Copy_u8PortId, u8 Copy_u8Value);

ES_t DIO_enuGetPortValue(u8 Copy_u8PortId, u8* Copy_Pu8Value);

ES_t DIO_enuTogglePortValue(u8 Copy_u8PortId);

ES_t DIO_enuSetBitDirection (u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value);

ES_t DIO_enuSetBitValue (u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value);

ES_t DIO_enuGetBitValue (u8 Copy_u8PortId, u8 Copy_u8PinId, u8* Copy_Pu8Value);

ES_t DIO_enuToggleBitValue (u8 Copy_u8PortId, u8 Copy_u8PinId);

#endif /* DIO_INT_H_ */
