/*
 * Regulator.c
 *
 *  Created on: 5 lip 2026
 *      Author: dorota
 */
#include "Regulator.h"



void UstawPWM(uint16_t sPWM, uint8_t cKanal){

	__HAL_TIM_SET_COMPARE(&htim3, cKanal, sPWM);
}




void WlaczPWM(uint8_t cKanal){

	HAL_TIM_PWM_Start(&htim3, cKanal);
}




uint8_t CzlonP(){

	float fBlad;
	float WyjscieFloat;
	float fUchyb;
	float fWstepneWysterowanie = 0.0f;
	float fWartZadana = 30.0f;
	float fZakresTemperatur = TEMP_MAX - TEMP_MIN;



	fBlad = odczytajTemp(&fTemp, 1) - fWartZadana;
	fUchyb = fBlad / (float)fZakresTemperatur;
	WyjscieFloat = fUchyb * (-fWzmocnienie) + fWstepneWysterowanie;

	if(WyjscieFloat > 1) WyjscieFloat = 1.0f;
	if(WyjscieFloat < 0) WyjscieFloat = 0.0f;

	uint8_t Wyjscie = (uint8_t)(WyjscieFloat*255);


	return Wyjscie;
}


