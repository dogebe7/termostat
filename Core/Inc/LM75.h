/*
 * LM75.h
 *
 *  Created on: 5 lip 2026
 *      Author: dorota
 */

#ifndef INC_LM75_H_
#define INC_LM75_H_
#define LM75ADRESS_GORNY 0x90
#define LM75ADRESS_DOLNY 0x92
#define ROZMIAR_DANYCH_I2C 10
#define TIMEOUT_I2C 10
#define READ_ID_GORNY 0x7
#define READ_ID_DOLNY 0x6
#define READ_TEMP 0


uint8_t odczytajID(void);
uint8_t CzytajTemperturęCzujnika(uint8_t cAdres, float *fTemp);
//uint8_t odczytajTempCzujnikGorny(float *fTemp);
uint8_t odczytajTempCzujnikDolny(float *fTemp);

#endif /* INC_LM75_H_ */
