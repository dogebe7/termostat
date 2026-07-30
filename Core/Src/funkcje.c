/*
 * funkcje.c
 *
 *  Created on: Jul 30, 2026
 *      Author: dorota
 */


#include "funkcje.h"

void WypiszTemp(void){

	  odczytajTemp(&fTemp, Gorny);
	  sprintf(Napis, "Temp gorna: %.1f", fTemp);
	  OLED_NapiszString(Napis, Czcionka_6x8, Bialy);
	  OLED_UstawKursor(3, 20);

	  odczytajTemp(&fTemp, Dolny);
	  sprintf(Napis, "Temp dolna: %.1f", fTemp);
	  OLED_NapiszString(Napis, Czcionka_6x8, Bialy);
	  OLED_UstawKursor(3, 3);

	  OLED_OdswiezEkran();
}
