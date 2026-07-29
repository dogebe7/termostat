/*
 * OLED.h
 *
 *  Created on: Jul 29, 2026
 *      Author: dorota
 */

#ifndef INC_OLED_H_
#define INC_OLED_H_
#include "stm32c0xx_hal.h"
#define OLED_SZEROKOSC 128
#define OLED_WYSOKOSC 64

void OLED_WyslijKomende(uint8_t bajt);
void OLED_WyslijDane(uint8_t* buffor, uint8_t rozmiar);
void OLED_Init(void);
void OLED_OdswiezEkran(void);
void OLED_NarysujPiksel(uint8_t x, uint8_t y);

#endif /* INC_OLED_H_ */
