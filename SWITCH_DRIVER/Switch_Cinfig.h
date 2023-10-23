/*
 * Switch_Cinfig.h
 *
 *  Created on: Oct 21, 2023
 *      Author: METRA
 */
#include "StdTypes.h"
#ifndef SWITCH_CINFIG_H_
#define SWITCH_CINFIG_H_

#define SW_NUM    1

typedef struct
{
  u8 SW_PORT_ID;
  u8 SW_PIN_ID;
  u8 SW_STATUS;

}SW_t;


#endif /* SWITCH_CINFIG_H_ */
