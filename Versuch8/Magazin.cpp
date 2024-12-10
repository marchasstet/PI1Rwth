/*
 * Magazin.cpp
 *
 *  Created on: 03.07.2024
 *      Author: marcd
 */
#include "Medium.h"
#include "Magazin.h"

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte):
Medium::Medium(initTitel),
ausgabeDatum(initDatumAusgabe),
sparte(initSparte)
{}

Magazin::~Magazin() {
	// TODO Auto-generated destructor stub
}
/**
 * @brief Gibt die Details des Magazins aus.
 *
 * Diese Methode gibt die allgemeinen Details eines Mediums durch Aufruf der `Medium::ausgabe` Methode
 * und die spezifischen Details des Magazins, wie das Ausgabedatum und die Sparte, auf der Konsole aus.
 */
void Magazin::ausgabe() const
{
	Medium::ausgabe();
	std::cout<<"Ausgabe: "<<ausgabeDatum<<std::endl
	   <<"Sparte:\t "<<sparte<<std::endl;
}
/**
 * @brief Verleiht das Magazin an eine Person, wenn es verfügbar ist.
 *
 * Diese Methode prüft, ob das Magazin bereits ausgegeben wurde.
 * Wenn ja, wird eine Fehlermeldung ausgegeben und false zurückgegeben.
 * Ansonsten wird das Magazin an die Person ausgeliehen und true zurückgegeben.
 *
 * @param[in] person Die Person, die das Magazin ausleihen möchte.
 * @param[in] ausleihdatum Das Datum, an dem das Magazin ausgeliehen wird.
 * @return true, wenn das Magazin erfolgreich ausgeliehen wurde, andernfalls false.
 */
bool Magazin::ausleihen(Person person, Datum ausleihdatum) {
	int differenz = ausleihdatum - ausgabeDatum;
	if (differenz > 0) {
		std::cout<<"Die aktuelle Ausgabe kann nicht ausgeliehen werden."<<std::endl;
		    	return false;
	} else {
 std::cout<<"Aktuelle Ausgabe"<<std::endl;
		return Medium::ausleihen(person, ausleihdatum);
	}
}
