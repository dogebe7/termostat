/*
 * OLED.h
 *
 *  Created on: Jul 29, 2026
 *      Author: dorota
 */

#ifndef INC_OLED_H_
#define INC_OLED_H_
#include "stm32c0xx_hal.h"
#include "OLED_Czcionka.h"
#define OLED_SZEROKOSC 128
#define OLED_WYSOKOSC 64

typedef enum{
	Czarny = 0x00,
	Bialy = 0x01
} OLED_KOLOR;

typedef struct{
	uint16_t ObecnyX;
	uint16_t ObecnyY;
	uint8_t OdwroconyKolor;
	uint8_t Zinicjalizowany;
} OLED_t;

typedef struct{
	uint8_t x;
	uint8_t y;
} OLED_VERTEX;

void OLED_WyslijKomende(uint8_t bajt);
void OLED_WyslijDane(uint8_t* buffor, uint8_t rozmiar);
void OLED_Init(void);
void OLED_OdswiezEkran(void);
void OLED_NarysujPiksel(uint8_t x, uint8_t y, OLED_KOLOR kolor);
void OLED_UstawKursor(uint8_t x, uint8_t y);
void OLED_WypelnijEkran(OLED_KOLOR kolor);
void OLED_NarysujLinie(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, OLED_KOLOR kolor);
void OLED_NarysujProstokat(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, OLED_KOLOR kolor);
char OLED_NapiszZnak(char ch, CzcionkaDef czcionka, OLED_KOLOR kolor);
char OLED_NapiszString(char* napis,CzcionkaDef czcionka, OLED_KOLOR kolor);



#endif /* INC_OLED_H_ */
