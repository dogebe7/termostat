/*
 * LM75C.c
 *
 *  Created on: 5 lip 2026
 *      Author: dorota
 */


#include "LM75.h"

uint8_t daneI2C[ROZMIAR_DANYCH_I2C];


uint8_t odczytajID(void){

	uint8_t cBlad;

	daneI2C[0] = READ_ID_GORNY;
	cBlad = HAL_I2C_Master_Transmit(&hi2c2, LM75ADRESS_GORNY, daneI2C, 1, TIMEOUT_I2C);
	cBlad = HAL_I2C_Master_Receive(&hi2c2, LM75ADRESS_GORNY, daneI2C, 1, TIMEOUT_I2C);


	return cBlad;
}


uint8_t odczytajTemp(float *fTemp, CZUJNIK nr){

	uint8_t cBlad;
	uint16_t sTemp;
	uint8_t adres = (nr == 0) ? LM75ADRESS_GORNY : LM75ADRESS_DOLNY;

	daneI2C[0] = READ_TEMP;
	cBlad = HAL_I2C_Master_Transmit(&hi2c2, adres, daneI2C, 1, TIMEOUT_I2C);
	cBlad = HAL_I2C_Master_Receive(&hi2c2, adres, daneI2C, 2, TIMEOUT_I2C);

	sTemp = ((uint16_t)daneI2C[0] << 1) + (daneI2C[1] >> 7);

	*fTemp = (float)sTemp / 2;

	return cBlad;
}



