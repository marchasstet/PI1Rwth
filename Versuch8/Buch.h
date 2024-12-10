/*
 * Buch.h
 *
 *  Created on: 03.07.2024
 *      Author: marcd
 */
#include "Medium.h"
#ifndef BUCH_H_
#define BUCH_H_

class Buch: public Medium {
public:
	Buch(std::string initTitel, std::string initAutor);
	virtual ~Buch();

	void ausgabe() const ;
protected:
	std::string author;
};
#endif /* BUCH_H_ */
