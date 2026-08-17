/*
 * Irda.c
 *
 *  Created on: Aug 5, 2026
 *      Author: dorota
 */


#include "Irda.h"


uint8_t daneIrda[ROZMIAR_DANYCH_IRDA];

void WlaczIrda(void){

	//__HAL_IRDA_ENABLE(&hirda1);

	HAL_StatusTypeDef Blad;

	Blad = HAL_IRDA_Receive_IT(&hirda1, daneIrda, 1);//IRDA_Receive_IT

	if(Blad == HAL_OK){
		HAL_Delay(10);
	}
	Blad = HAL_TIMEOUT;

}

