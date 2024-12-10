/*
 * DVD.h
 *
 *  Created on: 03.07.2024
 *      Author: marcd
 */
#include "Medium.h"
#ifndef DVD_H_
#define DVD_H_

class DVD : public Medium{
public:
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
	virtual ~DVD();
	void ausgabe() const;
	bool ausleihen( Person person, Datum ausleihdatum);
protected:
	int fsk;
	std::string genre;

};

#endif /* DVD_H_ */
