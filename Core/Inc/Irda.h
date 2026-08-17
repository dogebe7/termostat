/*
 * Irda.h
 *
 *  Created on: Aug 5, 2026
 *      Author: dorota
 */

#ifndef INC_IRDA_H_
#define INC_IRDA_H_


#include "stm32c0xx_hal.h"

#define ROZMIAR_DANYCH_IRDA 9
#define IRDA_TIMEOUT 5

extern IRDA_HandleTypeDef hirda1;


void WlaczIrda(void);


#endif /* INC_IRDA_H_ */
