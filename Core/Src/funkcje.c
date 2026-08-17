/*
 * funkcje.c
 *
 *  Created on: Jul 30, 2026
 *      Author: dorota
 */


#include "funkcje.h"



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



void WypiszTemp(void){

	  OLED_UstawKursor(3, 3);
	  odczytajTemp(&fTemp, Gorny);
	  sprintf(Napis, "Temp1: %.1f", fTemp);
	  OLED_NapiszString(Napis, Czcionka_6x8, Bialy);

	  OLED_UstawKursor(3, 13);
	  odczytajTemp(&fTemp, Dolny);
	  sprintf(Napis, "Temp2: %.1f", fTemp);
	  OLED_NapiszString(Napis, Czcionka_6x8, Bialy);

	  OLED_UstawKursor(3, 23);
	  sprintf(Napis, "Wzmocnienie: %2.1f", fWzmocnienie);
	  OLED_NapiszString(Napis, Czcionka_6x8, Bialy);

	  OLED_UstawKursor(3, 33);
	  sprintf(Napis, "Moc1:%3.0f%%", ((float)cWartoscPWM)/2.56);
	  OLED_NapiszString(Napis, Czcionka_6x8, Bialy);

	  OLED_UstawKursor(3, 43);
	  sprintf(Napis, "Moc2:%3.0f%%", ((float)cWartoscPWM)/2.56);
	  OLED_NapiszString(Napis, Czcionka_6x8, Bialy);

	  OLED_OdswiezEkran();
}



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
