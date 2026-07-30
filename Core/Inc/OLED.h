/*
 * OLED.h
 *
 *  Created on: Jul 29, 2026
 *      Author: dorota
 */

#ifndef INC_OLED_H_
#define INC_OLED_H_
#include "stm32c0xx_hal.h"
#include <ssd1306_fonts.h>

#define OLED_SZEROKOSC 128
#define OLED_WYSOKOSC 64

typedef struct {
    uint16_t CurrentX;
    uint16_t CurrentY;
    uint8_t Inverted;
    uint8_t Initialized;
} SSD1306_t;

void OLED_WyslijKomende(uint8_t bajt);
void OLED_WyslijDane(uint8_t* buffor, uint8_t rozmiar);
void OLED_Init(void);
void OLED_OdswiezEkran(void);
void OLED_NarysujPiksel(uint8_t x, uint8_t y);
char OLED_NarysujZnak(char cZnak, FontDef Font);

#endif /* INC_OLED_H_ */
