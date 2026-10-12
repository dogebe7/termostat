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



void UstawPWM(uint16_t sPWM, uint8_t cKanal){

	__HAL_TIM_SET_COMPARE(&htim3, cKanal, sPWM);
}




void WlaczPWM(uint8_t cKanal){

	HAL_TIM_PWM_Start(&htim3, cKanal);
}



////////////////////////////////////////////////////////////////////////////////
// Regulator proporcjonalny
// Parametry:
//  fWejscie - wartość wejsciowa podlegajaca regulacji
//  fWartZadana - wartość zadana do jakiej dąży regulacja
// Zwraca: wartość wysterowania w zakresie 0..100
////////////////////////////////////////////////////////////////////////////////
uint8_t CzlonP(float fWejscie, float fWartZadana, float fWzmocnienie)
{
	float fWyjscie;
	float fUchyb;

	fUchyb = fWejscie - fWartZadana;
	fWyjscie = fUchyb * fWzmocnienie;

	//ograniczenie wysterowanie do zdefiniowanego zakresu
	if (fWyjscie < WYSTEROWANIE_MIN)
		fWyjscie = WYSTEROWANIE_MIN;
	if (fWyjscie > WYSTEROWANIE_MAX)
		fWyjscie = WYSTEROWANIE_MAX;
	return (uint8_t)fWyjscie;
}


