/*
 * Regulator.h
 *
 *  Created on: 5 lip 2026
 *      Author: dorota
 */

#ifndef SRC_REGULATOR_H_
#define SRC_REGULATOR_H_
#include "stm32c0xx_hal.h"

void UstawPWM(uint16_t sPWM, uint8_t cKanal);
void WlaczPWM(uint8_t cKanal);
float CzlonP();



#endif /* SRC_REGULATOR_H_ */
