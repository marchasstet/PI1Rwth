/*
 * Magazin.h
 *
 *  Created on: 03.07.2024
 *      Author: marcd
 */
#include "Medium.h"
#ifndef MAGAZIN_H_
#define MAGAZIN_H_

class Magazin: public Medium {
public:
	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
	virtual ~Magazin();
	void ausgabe() const ;
	bool ausleihen(Person person, Datum ausleihdatum);
protected:
Datum ausgabeDatum;

std::string sparte;
};

#endif /* MAGAZIN_H_ */
