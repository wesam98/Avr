/*
 * StdTypes.h
 *
 *  Created on: Oct 13, 2023
 *      Author: METRA
 */

#ifndef STDTYPES_H_
#define STDTYPES_H_

#define NULL (void*)0

typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short u16;
typedef signed short s16;

#define setBit(x,n) (x |= (1 << n))
#define clrBit(x,n) (x &= ~(1 << n))
#define getBit(x,n) ((x >> n) & 1)

#endif /* STDTYPES_H_ */
