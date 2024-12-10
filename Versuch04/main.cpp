//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einführung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

using std::cout;
using std::endl;

int main()
{
    Vektor vector1(1, 0, 0);
    Vektor vector2(0, 1, 0);

    vector1.ausgabe();
    vector2.ausgabe();

    cout << "Länge der Vektoren V_1(1,0,0) und V_2(0,1,0):" << endl;
    cout << vector1.laenge() << endl;
    cout << vector2.laenge() << endl << endl;

    Vektor vecsca1(1,0,2);
	Vektor vecsca2(-2,0,1);

	cout << "Skalarprodukt von V_1(1,0,2) und V_2(-2,0,1):" << endl;
	cout << vecsca1.skalarProd(vecsca2) << endl;

	Vektor vecwin1(0,1,0);
	Vektor vecwin2(1,0,0);

	cout << "Winkel zwischen V_1(0,1,0) und V_2(1,0,0):" << endl;
	cout << vecwin1.winkel(vecwin2) << endl;

	cout << "Subtraktion von V_1(1,0,0) mit V_2(0,1,0):" << endl;
	Vektor newvector = vector1.sub(vector2);
	//cout << newvector << endl;
	cout << "test" << endl;

    return 0;

}
