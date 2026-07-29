/*
 * Regulator.c
 *
 *  Created on: 5 lip 2026
 *      Author: dorota
 */
#include "Regulator.h"
#include "main.h"
#include "stm32c0xx_hal.h"
#include "LM75.h"
extern TIM_HandleTypeDef htim3;
extern float fTempG;
extern float fTempD;
#define TEMP_MIN 0;
#define TEMP_MAX 100;


void UstawPWM(uint16_t sPWM, uint8_t cKanal){

	__HAL_TIM_SET_COMPARE(&htim3, cKanal, sPWM);
}




void WlaczPWM(uint8_t cKanal){

	HAL_TIM_PWM_Start(&htim3, cKanal);
}




float CzlonP(){

	float fBlad;
	float fWyjscie;
	float fUchyb;
	float fWzmocnienie = 1;
	float fWstepneWysterowanie = 0;
	float fWartZadana = 10;
	float fZakresTemperatur = TEMP_MAX - TEMP_MIN;

	fBlad = odczytajTempCzujnikGorny(&fTempG) - fWartZadana;
	fUchyb = fBlad / fZakresTemperatur;
	fWyjscie = (fUchyb * fWzmocnienie + fWstepneWysterowanie) * 65535;



	return fWyjscie;
}


