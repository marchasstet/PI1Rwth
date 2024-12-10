//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"


Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

double Vektor::laenge() const
{
	return sqrt(x*x + y*y + z*z);
}

double Vektor::skalarProd(const Vektor& input) const
{
	return (x*input.x+y*input.y+z*input.z);
}

double Vektor::winkel(const Vektor& input) const
{

	return (acos(Vektor::skalarProd(input)/(laenge()*input.laenge()))*180/M_PI);
}

Vektor Vektor::sub(const Vektor& input) const
{
	return Vektor(x-input.x,y-input.y,z-input.z);
}

void Vektor::rotiereUmZ(const double rad)
{

}
