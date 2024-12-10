//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
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
Vektor Vektor::sub(const Vektor& input) const{
	return Vektor(x-input.x,y-input.y,z-input.z);
	}

double Vektor::skalarProd(const Vektor& input) const{
	return((x*input.x)+(y*input.y)+(z*input.z));
}
double Vektor::winkel(const Vektor& input) const{
		return(acos(skalarProd(input))/(laenge()*input.laenge()));
}
void Vektor::rotiereUmZ(const double rad)
{
 double dNeuX=(x*cos(rad)-y*sin(rad));
 double dNeuY=(y*cos(rad)+x*sin(rad));
 this->x=dNeuX;
 this->y=dNeuY;
}
//bool Vektor::istOrthogonal(const Vektor& input) const{
//	double skalar=skalarProd(input);
// return((skalar < 0.1) && (skalar > -0.1));
//}
