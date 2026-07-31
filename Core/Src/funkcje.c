/*
 * funkcje.c
 *
 *  Created on: Jul 30, 2026
 *      Author: dorota
 */


#include "funkcje.h"

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
