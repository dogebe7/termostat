/*
 * funkcje.h
 *
 *  Created on: Jul 30, 2026
 *      Author: dorota
 */

#ifndef INC_FUNKCJE_H_
#define INC_FUNKCJE_H_

#include "stm32c0xx_hal.h"
#include "stdio.h"
#include "main.h"
#include "LM75.h"
#include "OLED.h"


extern char Napis[];
extern float fTemp;


void WypiszTemp(void);


#endif /* INC_FUNKCJE_H_ */
