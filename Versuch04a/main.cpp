//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////
#include <math.h>
#include "Vektor.h"
/**
 * @brief Radius of the Earth in kilometers.
 */
#define ERDRADIUS 6371
/**
 * @brief Height of the platform in meters.
 */
#define PLATTFORMAHOEHE 555.7
/**
 * @brief Average human height in meters.
 */
#define MENSCH_GROESSE 1.7
/**
 * @brief Value of Pi.
 */
#define PI 3.14159265

bool istOrthogonal(const Vektor& input,const Vektor& input2);
void aufgabe1();
void aufgabe1fixed();
int main()
{
    Vektor vector1(1, 0, 0);
    Vektor vector2(0, 1, 0);

    vector1.ausgabe();
    vector2.ausgabe();
    aufgabe1fixed();
    //aufgabe1();
    return 0;

}
/**
 * @brief Überprüft, ob zwei Vektoren orthogonal sind.
 *
 * Diese Funktion bestimmt, ob zwei Vektoren orthogonal sind, indem das Skalarprodukt berechnet wird
 * und überprüft wird, ob der Betrag des Ergebnisses kleiner als ein bestimmter Schwellenwert ist.
 *
 * @param input Der erste Vektor.
 * @param input2 Der zweite Vektor.
 * @return true, wenn die Vektoren orthogonal sind, false andernfalls.
 */
bool istOrthogonal(const Vektor& input,const Vektor& input2) {
	long double skalar=input.skalarProd(input2);
 return(fabs(skalar) < 0.1);
	//return(skalar<0.1&&skalar>-0.1);
}
void aufgabe1(){
	Vektor vErde(0, 6371, 0);
	Vektor vMensch(0, ((555.7 + 1.7) / 1000.0) + 6371000,0);
	Vektor vSicht = vErde.sub(vMensch);

	double rad = 0;
	int schritte=0;
	 double winkel = 0.0000001;
	double hoehe= vMensch.laenge() -6371000;
//for(;!istOrthogonal(vSicht, vErde);rad += winkel,
//		schritte++,
//		vErde.rotiereUmZ(winkel),
//		vSicht = vErde.sub(vMensch)){
//	std::cout<<rad<<"\t"<<vSicht.laenge()<<std::endl;
//
//}
int schrittw=0;
while(vMensch.sub(vErde).skalarProd(vErde)>10000){
 schrittw++;
 vErde.rotiereUmZ(winkel);
}
//	do {
//		rad += WINKEL;
//		schritte++;
//		vErde.rotiereUmZ(winkel);
//		vSicht = vErde.sub(vMensch);
//	} while (!istOrthogonal(vSicht, vErde));

	double sehEntfernung = vMensch.sub(vErde).laenge()-6371000;
	 winkel = rad * M_PI/180;
	std::cout << "Höhe der Plattform: " << PLATTFORMAHOEHE << " in m"
			<< std::endl;
	std::cout<<std::setprecision(6) << "Sichtweite: " << sehEntfernung << " in km" << std::endl;
	std::cout<<std::setprecision(5) << "Winkel: " << winkel << "°" << std::endl;
	std::cout << "Schritte: " << schritte << "" << std::endl;

}
/**
 * @brief Berechnet die sichtbare Entfernung zum Horizont aus einer gegebenen Höhe über der Erdoberfläche.
 *
 * Diese Funktion berechnet die sichtbare Entfernung zum Horizont für einen Beobachter in einer
 * bestimmten Höhe über der Erdoberfläche unter Berücksichtigung der Erdkrümmung. Die Berechnung
 * erfolgt durch iteratives Rotieren eines Vektors, bis er orthogonal zu einem anderen Vektor ist,
 * was eine tangentiale Sichtlinie anzeigt.
 */
void aufgabe1fixed(){
	//double winkel = 0.0000000001;
	double winkel = 0.0000001;
	//double winkel = 0.00001;
	// Erdradius
	Vektor vErde(0, 6371, 0);

		// Sichth�he Mensch
		Vektor vMensch(0, ((555.7 + 1.7) / 1000.0) + 6371,0);

		// Sichtvektor soll Erde tangieren
		Vektor vSicht = vErde.sub(vMensch);
		int counter=0;
			double rad = 0.0;
			do
			{
				counter++;
				// Erhöhe Winkel langsam
				rad += winkel;
				vErde.rotiereUmZ(winkel);
				vSicht = vErde.sub(vMensch);

			} while(!istOrthogonal(vSicht,vErde));
			double sehEntfernung = vMensch.sub(vErde).laenge();

				 winkel = (rad * 180/M_PI);


				std::cout << "Höhe der Plattform: " << PLATTFORMAHOEHE << " in m"
						<< std::endl;
				std::cout<<std::setprecision(10) << "Sichtweite: " << sehEntfernung << " in km" << std::endl;
				std::cout<<std::setprecision(10) << "Winkel: " << winkel << "°" << std::endl;
				std::cout << "Schritte: " << counter << "" << std::endl;
}
