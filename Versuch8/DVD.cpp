/*
 * DVD.cpp
 *
 *  Created on: 03.07.2024
 *      Author: marcd
 */

#include "DVD.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre):Medium::Medium(initTitel),fsk(initAltersfreigabe),genre(initGenre) {
	// TODO Auto-generated constructor stub

}

DVD::~DVD() {
	// TODO Auto-generated destructor stub
}
/**
 * @brief Gibt die Details der DVD aus.
 *
 * Diese Methode gibt die allgemeinen Details eines Mediums durch Aufruf der `Medium::ausgabe` Methode
 * und die spezifischen Details der DVD, wie die FSK und das Genre, auf der Konsole aus.
 */
void DVD::ausgabe() const
{
	Medium::ausgabe();
	std::cout<<"FSK:\t ab "<<fsk<<" Jahren."<<std::endl
	   <<"Genre:\t "<<genre<<std::endl;
}
/**
 * @brief Verleiht die DVD an eine Person, wenn die Altersbeschränkung erfüllt ist.
 *
 * Diese Methode verleiht die DVD an eine Person, sofern die Person das Mindestalter (FSK) erfüllt.
 * Die Altersbeschränkung wird basierend auf dem Geburtsdatum der Person und dem aktuellen Ausleihdatum überprüft.
 *
 * @param[in] person Die Person, die die DVD ausleihen möchte.
 * @param[in] ausleihdatum Das Datum, an dem die DVD ausgeliehen wird.
 * @return true, wenn die DVD erfolgreich ausgeliehen wurde, andernfalls false.
 */
bool DVD::ausleihen( Person person, Datum ausleihdatum) {
	if(person.getGeburtsdatum()-ausleihdatum > fsk *12){return Medium::ausleihen(person,ausleihdatum);}
	std::cout<<"Person erfüllt das Alter nicht"<<std::endl;
	return false;
}
