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
#include "Regulator.h"


extern char Napis[];
extern float fTemp;
extern float fWzmocnienie;
extern uint8_t cWartoscPWM;

void WypiszTemp(void);


#endif /* INC_FUNKCJE_H_ */
