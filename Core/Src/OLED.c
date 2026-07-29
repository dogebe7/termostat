/*
 * OLED.c
 *
 *  Created on: Jul 29, 2026
 *      Author: dorota
 */

#include "OLED.h"
#include "main.h"
#include "stm32c0xx_hal.h"
#include <stdio.h>
extern I2C_HandleTypeDef hi2c2;
extern SPI_HandleTypeDef hspi1;




void OLED_WyslijKomende(uint8_t bajt){

	HAL_GPIO_WritePin(CHIPSELECT_GPIO_Port, CHIPSELECT_Pin, GPIO_PIN_RESET); //Wybierz OLED
	HAL_GPIO_WritePin(D_C_GPIO_Port, D_C_Pin, GPIO_PIN_RESET); //przesył
	HAL_SPI_Transmit(&hspi1, &bajt, 1, 1000);
	HAL_GPIO_WritePin(CHIPSELECT_GPIO_Port, CHIPSELECT_Pin, GPIO_PIN_SET); //Od-wybierz OLED
}

void OLED_WyslijDane(uint8_t* buffor, uint8_t rozmiar){

	HAL_GPIO_WritePin(CHIPSELECT_GPIO_Port, CHIPSELECT_Pin, GPIO_PIN_RESET); //Wybierz OLED
	HAL_GPIO_WritePin(D_C_GPIO_Port, D_C_Pin, GPIO_PIN_RESET); //przesył
	HAL_SPI_Transmit(&hspi1, buffor, rozmiar, 1000);
	HAL_GPIO_WritePin(CHIPSELECT_GPIO_Port, CHIPSELECT_Pin, GPIO_PIN_SET); //Od-wybierz OLED
}

uint8_t OLED_Buffor[OLED_WYSOKOSC*OLED_SZEROKOSC/8];


void OLED_Init(void){

	HAL_Delay(100);


	OLED_WyslijKomende(0x20); //Set Memory Addressing Mode

	OLED_WyslijKomende(0x00); // 00b,Horizontal Addressing Mode; 01b,Vertical Addressing Mode;
    						  // 10b,Page Addressing Mode (RESET); 11b,Invalid

	OLED_WyslijKomende(0xB0); //Set Page Start Address for Page Addressing Mode,0-7

	OLED_WyslijKomende(0xC8); //Set COM Output Scan Direction

	OLED_WyslijKomende(0x00); //---set low column address

	OLED_WyslijKomende(0x10); //---set high column address

	OLED_WyslijKomende(0x40); //--set start line address - CHECK

	OLED_WyslijKomende(0x81); //--set contrast control register - CHECK

	OLED_WyslijKomende(0xA1); //--set segment re-map 0 to 127 - CHECK

	OLED_WyslijKomende(0xA6); //--set normal color

	OLED_WyslijKomende(0xA8); //--set multiplex ratio(1 to 64) - CHECK

	OLED_WyslijKomende(0x3F); // ustawia wysokosc

	OLED_WyslijKomende(0xA4); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content

	OLED_WyslijKomende(0xD3); //-set display offset - CHECK

	OLED_WyslijKomende(0x00); //-not offset

	OLED_WyslijKomende(0xD5); //--set display clock divide ratio/oscillator frequency

	OLED_WyslijKomende(0xF0); //--set divide ratio

	OLED_WyslijKomende(0xD9); //--set pre-charge period

	OLED_WyslijKomende(0x22); //

	OLED_WyslijKomende(0xDA); //--set com pins hardware configuration - CHECK

	OLED_WyslijKomende(0x12); // cos z wysokoscia

	OLED_WyslijKomende(0xDB); //--set vcomh

	OLED_WyslijKomende(0x20); //0x20,0.77xVcc

	OLED_WyslijKomende(0x8D); //--set DC-DC enable

	OLED_WyslijKomende(0x14); //


	OLED_WyslijKomende(0xAF); //--turn on SSD1306 panel
	OLED_OdswiezEkran();

}

void OLED_OdswiezEkran(void){

	for(uint8_t i = 0; i < OLED_WYSOKOSC / 8; i++){
		OLED_WyslijKomende(0xB0 + i); //Set Page Start Address for Page Addressing Mode
		OLED_WyslijKomende(0x00); //Set Lower Column Start Address for Page Addressing Mode
		OLED_WyslijKomende(0x00); //Set Higher Column Start Address for Page Addressing	Mode
		OLED_WyslijDane(&OLED_Buffor[OLED_SZEROKOSC*i], OLED_SZEROKOSC);
	}
}


void OLED_NarysujPiksel(uint8_t x, uint8_t y){
	if(x >= OLED_SZEROKOSC || x < 0 || y >= OLED_WYSOKOSC || y < 0) return;

	OLED_Buffor[x + (y / 8) * OLED_SZEROKOSC] |= 1 << (y % 8);

}

