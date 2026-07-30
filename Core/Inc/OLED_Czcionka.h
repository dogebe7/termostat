/*
 * OLED_Czcionka.h
 *
 *  Created on: Jul 30, 2026
 *      Author: dorota
 */

#ifndef INC_OLED_CZCIONKA_H_
#define INC_OLED_CZCIONKA_H_

#include <stdint.h>


typedef struct {
	const uint8_t Szerokosc;    /*!< Font width in pixels */
	uint8_t Wysokosc;   /*!< Font height in pixels */
	const uint16_t *dane; /*!< Pointer to data font data array */
} CzcionkaDef;


extern CzcionkaDef Czcionka_6x8;
extern CzcionkaDef Czcionka_7x10;
extern CzcionkaDef Czcionka_11x18;
extern CzcionkaDef Czcionka_16x26;



#endif /* INC_OLED_CZCIONKA_H_ */
