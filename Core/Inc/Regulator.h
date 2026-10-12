/*
 * Regulator.h
 *
 *  Created on: 5 lip 2026
 *      Author: dorota
 */

#ifndef SRC_REGULATOR_H_
#define SRC_REGULATOR_H_
#include "stm32c0xx_hal.h"

#define TEMP_MIN 0
#define TEMP_MAX 100

#define WYSTEROWANIE_MIN	0
#define WYSTEROWANIE_MAX	100

void UstawPWM(uint16_t sPWM, uint8_t cKanal);
void WlaczPWM(uint8_t cKanal);
//float CzlonP();
uint8_t CzlonP(float fWejscie, float fWartZadana, float fWzmocnienie);


#endif /* SRC_REGULATOR_H_ */
