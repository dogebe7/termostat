/*
 * przyciski.c
 *
 *  Created on: Jul 31, 2026
 *      Author: dorota
 */


#include "przyciski.h"

void SprawdzPrzycisk(uint8_t numer){

	GPIO_PinState bitstatus;

	switch(numer){
	case 1:
		bitstatus = HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin);
		break;
	case 2:
		bitstatus = HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin);
		break;
	case 3:
		bitstatus = HAL_GPIO_ReadPin(KEY3_GPIO_Port, KEY3_Pin);
		break;
	default:
		return;
	}


	if(bitstatus == GPIO_PIN_SET){
		OLED_WypelnijEkran(Bialy);
	}
	else if (bitstatus == GPIO_PIN_RESET){
		OLED_WypelnijEkran(Czarny);

	}

}

void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin){


	if(GPIO_Pin == KEY1_Pin){
		fWzmocnienie += 0.1;
		if(fWzmocnienie > 10) fWzmocnienie = 5.0f;
	}
	else if (GPIO_Pin == KEY2_Pin){
		fWzmocnienie -= 0.1;
		if(fWzmocnienie < 0) fWzmocnienie = 0.0f;
	}


}







