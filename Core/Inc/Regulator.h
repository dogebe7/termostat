/*
 * Regulator.h
 *
 *  Created on: 5 lip 2026
 *      Author: dorota
 */

#ifndef SRC_REGULATOR_H_
#define SRC_REGULATOR_H_

#include "stm32c0xx_hal.h"
#include "LM75.h"
#include "main.h"


extern TIM_HandleTypeDef htim3;
extern float fTemp;
extern float fWzmocnienie;

#define TEMP_MIN 0
#define TEMP_MAX 100

void UstawPWM(uint16_t sPWM, uint8_t cKanal);
void WlaczPWM(uint8_t cKanal);
uint8_t CzlonP();



#endif /* SRC_REGULATOR_H_ */
