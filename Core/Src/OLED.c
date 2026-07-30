/*
 * OLED.c
 *
 *  Created on: Jul 29, 2026
 *      Author: dorota
 */

#include "OLED.h"
#include "main.h"
#include "stm32c0xx_hal.h"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "OLED_Czcionka.h"
extern I2C_HandleTypeDef hi2c2;
extern SPI_HandleTypeDef hspi1;




void OLED_WyslijKomende(uint8_t bajt){

	HAL_GPIO_WritePin(CHIPSELECT_GPIO_Port, CHIPSELECT_Pin, GPIO_PIN_RESET);	//Wybierz OLED
	HAL_GPIO_WritePin(D_C_GPIO_Port, D_C_Pin, GPIO_PIN_RESET); 					//DC = 0: polecenie
	HAL_SPI_Transmit(&hspi1, &bajt, 1, 10);										//transmisja bajtu polecenia
	HAL_GPIO_WritePin(CHIPSELECT_GPIO_Port, CHIPSELECT_Pin, GPIO_PIN_SET); 		//zwolnij OLED
}

void OLED_WyslijDane(uint8_t* buffor, uint8_t rozmiar){

	HAL_GPIO_WritePin(CHIPSELECT_GPIO_Port, CHIPSELECT_Pin, GPIO_PIN_RESET); 	//Wybierz OLED
	HAL_GPIO_WritePin(D_C_GPIO_Port, D_C_Pin, GPIO_PIN_SET); 					//DC = 1: dane do wyświetlenia
	HAL_SPI_Transmit(&hspi1, buffor, rozmiar, 10);								//transmisja danych do wyświetlenia
	HAL_GPIO_WritePin(CHIPSELECT_GPIO_Port, CHIPSELECT_Pin, GPIO_PIN_SET); 		//zwolnij OLED
}



static uint8_t OLED_Buffor[OLED_WYSOKOSC * OLED_SZEROKOSC / 8] = {"Witaj przygodo z wyswietlaczem OLED"};
static OLED_t OLED;



void OLED_Init(void){

	HAL_Delay(100);

	OLED_WyslijKomende(0xAE); //display off

	OLED_WyslijKomende(0x20); //Set Memory Addressing Mode

	OLED_WyslijKomende(0x00); // 00b,Horizontal Addressing Mode; 01b,Vertical Addressing Mode;
    						  // 10b,Page Addressing Mode (RESET); 11b,Invalid

	OLED_WyslijKomende(0xB0); //Set Page Start Address for Page Addressing Mode,0-7

	OLED_WyslijKomende(0xC8); //Set COM Output Scan Direction

	OLED_WyslijKomende(0x00); //---set low column address

	OLED_WyslijKomende(0x10); //---set high column address

	OLED_WyslijKomende(0x40); //--set start line address - CHECK

	OLED_WyslijKomende(0x81); //--set contrast control register - CHECK
	OLED_WyslijKomende(0xFF);

	OLED_WyslijKomende(0xA1); //--set segment re-map 0 to 127 - CHECK

	OLED_WyslijKomende(0xA6); //--set normal color

	OLED_WyslijKomende(0xA8); //--set multiplex ratio(1 to 64) - CHECK

	OLED_WyslijKomende(0x3F); // ustawia wysokosc = 64

	OLED_WyslijKomende(0xA4); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content

	OLED_WyslijKomende(0xD3); //-set display offset - CHECK

	OLED_WyslijKomende(0x00); //-not offset

	OLED_WyslijKomende(0xD5); //--set display clock divide ratio/oscillator frequency

	OLED_WyslijKomende(0xF0); //--set divide ratio

	OLED_WyslijKomende(0xD9); //--set pre-charge period

	OLED_WyslijKomende(0x22); //

	OLED_WyslijKomende(0xDA); //--set com pins hardware configuration - CHECK

	OLED_WyslijKomende(0x12); // wysokość = 64

	OLED_WyslijKomende(0xDB); //--set vcomh

	OLED_WyslijKomende(0x20); //0x20,0.77xVcc

	OLED_WyslijKomende(0x8D); //--set DC-DC enable

	OLED_WyslijKomende(0x14); //


	OLED_WyslijKomende(0xAF); //--turn on SSD1306 panel


	OLED_WypelnijEkran(Czarny);
	OLED_NarysujProstokat(0, 0, 127, 63, Bialy);
	OLED_UstawKursor(3, 3);
	OLED_OdswiezEkran();

	OLED.Zinicjalizowany = 1;

}

void OLED_OdswiezEkran(void){

	for(uint8_t i = 0; i < OLED_WYSOKOSC / 8; i++){
		OLED_WyslijKomende(0xB0 + i); //Set Page Start Address for Page Addressing Mode
		OLED_WyslijKomende(0x00); //Set Lower Column Start Address for Page Addressing Mode
		OLED_WyslijKomende(0x10); //Set Higher Column Start Address for Page Addressing	Mode
		OLED_WyslijDane(&OLED_Buffor[OLED_SZEROKOSC*i], OLED_SZEROKOSC);
	}
}


void OLED_NarysujPiksel(uint8_t x, uint8_t y, OLED_KOLOR kolor){

	if(x >= OLED_SZEROKOSC || x < 0 || y >= OLED_WYSOKOSC || y < 0)
		return;


	if(OLED.OdwroconyKolor){
		kolor = (OLED_KOLOR)!kolor;
	}


	if(kolor == Bialy){
		OLED_Buffor[x + (y / 8) * OLED_SZEROKOSC] |= 1 << (y % 8);
	}
	else{
		OLED_Buffor[x + (y / 8) * OLED_SZEROKOSC] &= ~(1 << (y % 8));
	}
}



void OLED_UstawKursor(uint8_t x, uint8_t y){

	OLED.ObecnyX = x;
	OLED.ObecnyY = y;
}



void OLED_WypelnijEkran(OLED_KOLOR kolor){

	for(uint32_t i = 0; i < sizeof(OLED_Buffor); i++){
		OLED_Buffor[i] = (kolor == Bialy) ? 0xFF : 0x00;
	}
}



void OLED_NarysujLinie(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, OLED_KOLOR kolor){

	int32_t deltaX = abs(x2 - x1);
	int32_t deltaY = abs(y2 - y1);
	int32_t znakX = ((x1 < x2) ? 1 : -1);
	int32_t znakY = ((y1 < y2) ? 1 : -1);
	int32_t blad = deltaX - deltaY;
	int32_t blad2;

	OLED_NarysujPiksel(x2, y2, kolor);
	while((x1 != x2) || (y1 != y2)){
		OLED_NarysujPiksel(x1, y1, kolor);
		blad2 = blad * 2;

		if(blad2 > -deltaY){
			blad -= deltaY;
			x1 += znakX;
		}

		if(blad2 < deltaX){
			blad += deltaX;
			y1 += znakY;
		}
	}
}



void OLED_NarysujProstokat(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, OLED_KOLOR kolor){

	OLED_NarysujLinie(x1,y1,x2,y1,kolor);
	OLED_NarysujLinie(x2,y1,x2,y2,kolor);
	OLED_NarysujLinie(x2,y2,x1,y2,kolor);
	OLED_NarysujLinie(x1,y2,x1,y1,kolor);

  return;
}



char OLED_NapiszZnak(char ch, CzcionkaDef czcionka, OLED_KOLOR kolor){

	uint32_t i, b, j;

	if(ch < 32 || ch > 126)
	        return 0;

	// Check remaining space on current line
	if(OLED_SZEROKOSC < (OLED.ObecnyX + czcionka.Szerokosc) || OLED_WYSOKOSC < (OLED.ObecnyY + czcionka.Wysokosc)){

		return 0; // Not enough space on current line
	}


	for(i = 0; i < czcionka.Wysokosc; i++) {
	        b = czcionka.dane[(ch - 32) * czcionka.Wysokosc + i];
	        for(j = 0; j < czcionka.Szerokosc; j++) {
	            if((b << j) & 0x8000)  {
	                OLED_NarysujPiksel(OLED.ObecnyX + j, OLED.ObecnyY + i, (OLED_KOLOR)kolor);
	            } else {
	            	OLED_NarysujPiksel(OLED.ObecnyX + j, OLED.ObecnyY + i, (OLED_KOLOR)!kolor);
	            }
	        }
	    }
	// The current space is now taken
	OLED.ObecnyX += czcionka.Szerokosc;

	// Return written char for validation
	return ch;
}



char OLED_NapiszString(char* napis,CzcionkaDef czcionka, OLED_KOLOR kolor){
	// Write until null-byte
	    while (*napis) {
	        if (OLED_NapiszZnak(*napis, czcionka, kolor) != *napis){
	            // Char could not be written
	            return *napis;
	        }
	        // Next char
	        napis++;
	    }
	    // Everything ok
	    return *napis;
	}
