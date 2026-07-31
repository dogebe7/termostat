/*
 * przyciski.h
 *
 *  Created on: Jul 31, 2026
 *      Author: dorota
 */

#ifndef INC_PRZYCISKI_H_
#define INC_PRZYCISKI_H_

#include "stm32c0xx_hal.h"
#include "main.h"
#include "OLED.h"
#include "OLED_Czcionka.h"
#include "stdio.h"

extern char Napis[];
extern float fWzmocnienie;

void SprawdzPrzycisk(uint8_t numer);


#endif /* INC_PRZYCISKI_H_ */
