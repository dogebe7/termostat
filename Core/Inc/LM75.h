/*
 * LM75.h
 *
 *  Created on: 5 lip 2026
 *      Author: dorota
 */
#ifndef INC_LM75_H_
#define INC_LM75_H_

#include "main.h"
#include <stdio.h>
#include "stm32c0xx_hal.h"

extern I2C_HandleTypeDef hi2c2;

#define LM75ADRESS_GORNY 0x90
#define LM75ADRESS_DOLNY 0x92
#define ROZMIAR_DANYCH_I2C 10
#define TIMEOUT_I2C 10
#define READ_ID_GORNY 0x7
#define READ_ID_DOLNY 0x6
#define READ_TEMP 0


uint8_t odczytajID(void);
uint8_t odczytajTemp(float *fTemp, CZUJNIK nr);

#endif /* INC_LM75_H_ */
