/*
 * DIO_init.h
 *
 *  Created on: Oct 13, 2023
 *      Author: METRA
 */

#ifndef DIO_INIT_H_
#define DIO_INIT_H_


#define DIO_u8PORTA 		0
#define DIO_u8PORTB 		1
#define DIO_u8PORTC   		2
#define DIO_u8PORTD	   		3


ES DIO_enuInit(void);

ES DIO_enuSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8Value);
ES DIO_enuSetPortValue(u8 Copy_u8PortID, u8 Copy_u8Value);
ES DIO_enuTogPort(u8 Copy_u8PortID);
ES DIO_enuGetPort(u8 Copy_u8PortID, u8* Copy_pu8Value);


ES DIO_enuSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID, u8 Copy_u8Value);
ES DIO_enuSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID, u8 Copy_u8Value);
ES DIO_enuGetpin(u8 Copy_u8PortID,u8 Copy_u8PinID, u8* Copy_pu8Value);
ES DIO_enuTogPin(u8 Copy_u8PortID, u8 Copy_u8PinID);




#endif /* DIO_INIT_H_ */
