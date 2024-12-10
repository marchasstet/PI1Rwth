//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVI
// Versuch 04: Einf�hrung in die Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//
// Autor:  xxxxxx xxxxxx
// Matr.:  000000
// Datum:  21.04.2016
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Vektor.h"
#include <cmath>

#define EARTH_RADIUS_KM 6371
#define PLATFORM_HEIGHT_M 555.7
#define HUMAN_SIZE_M 1.7

#define ANGLE_INC 0.0000001
#define PI 3.14159265

int main()
{
	// Erdradius
	Vektor* earth = new Vektor(0, EARTH_RADIUS_KM, 0);

	// Sichth�he Mensch
	Vektor* human = earth->add(new Vektor(0, (PLATFORM_HEIGHT_M + HUMAN_SIZE_M)/1000, 0));

	// Sichtvektor soll Erde tangieren
	Vektor* sight = earth->subtract(human);
int counter=0;
	double rad = 0;
	do
	{
		counter++;
		// Erh�he Winkel langsam
		rad += ANGLE_INC;
		earth->rotate(ANGLE_INC);
		sight = earth->subtract(human);

	} while(!sight->isOrthogonal(earth)); // Pr�fe Orthogonalit�t

	// Berechnen der Distanz als Zahlenwert
	double sight_dist = sight->getLength();
	double deg = rad * 180 / PI;

	std::cout << "Höhe der Plattform: " << PLATFORM_HEIGHT_M  << "m" << std::endl;
	std::cout << "Sichtweite: " << sight_dist << "km" << std::endl;
	std::cout << "Winkel: " << deg << "°" << std::endl;
	std::cout << "Schritte: " << counter  << std::endl;
	return 0;
}

// E.O.F.
