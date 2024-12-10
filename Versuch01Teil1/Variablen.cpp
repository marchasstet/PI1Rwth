//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using std::endl;
using std::cout;
using std::cin;
using std::string;
void vA1t1();
void vA1t2();
void vA1t3();
void vA1t4();
void vA1t5();
void vA1t6();
void vA1t7();
int main() {
	int x;
	// Hier folgt Ihr eigener Code
	std::cout << "Welche aufgabe?" << std::endl;
	std::cout << "Auwahl:" << std::endl;
	cin >> x;
	switch (x) {
	case 1:
		vA1t1();
		break;
	case 2:
		vA1t2();
		break;
	case 3:
		vA1t3();
		break;
	case 4:
		vA1t4();
		break;
	case 5:
		vA1t5();
		break;
	case 6:
		vA1t6();
		break;
	case 7:
		vA1t7();
		break;
	default:
		cout << "Nicht gültige Eingabe!" << endl;
		cout << "Neue Eingabe" << endl;
	}

	return 0;
}
void vA1t1() {
	int iErste = 0;
	int iZweite = 0;

	// Hier folgt Ihr eigener Code

	std::cout << "Int 1" << std::endl;
	std::cin >> iErste;
	std::cout << "Int 2" << std::endl;
	std::cin >> iZweite;
	int iSumme = iErste + iZweite;
	int iQuotient = iErste / iZweite;
	std::cout << "Ergebins der Summe ist " << iSumme << std::endl;
	std::cout << "Ergebins der Division ist " << iQuotient << std::endl;

}
void vA1t2() {
	int iErste = 0;
	int iZweite = 0;

	// Hier folgt Ihr eigener Code

	std::cout << "Int 1" << std::endl;
	std::cin >> iErste;
	std::cout << "Int 2" << std::endl;
	std::cin >> iZweite;
	double dSumme = iErste + iZweite;
	double dQuotient = iErste / iZweite;
	std::cout << "Ergebins der Summe ist " << dSumme << std::endl;
	std::cout << "Ergebins der Division ist " << dQuotient << std::endl;

}
void vA1t3() {
	int iErste = 0;
	int iZweite = 0;

	// Hier folgt Ihr eigener Code

	std::cout << "Int 2" << std::endl;
	std::cin >> iErste;
	std::cout << "Int 2" << std::endl;
	std::cin >> iZweite;
	double dSummeCast = (double) iErste + (double) iZweite;
	double dQuotientCast = (double) iErste / (double) iZweite;
	std::cout << "Ergebins der Summe ist " << dSummeCast << std::endl;
	std::cout << "Ergebins der Division ist " << dQuotientCast << std::endl;

}
void vA1t4() {
	string vorname = "";
	string nachname = "";
	string sVornameNachname = "";
	string sNachnameVorname = "";
	cout << "Vorname:" << endl;
	cin >> vorname;
	cout << "Nachname:" << endl;
	cin >> nachname;
	sVornameNachname = vorname + " " + nachname;
	sNachnameVorname = nachname + "," + vorname;
	cout << "Vornamen Namen" << endl;
	cout << sVornameNachname << endl;
	cout << "Namen, Vornamen" << endl;
	cout << sNachnameVorname << endl;
}
void vA1t5() {
	{
		//a
		int iFeld[] = { 1, 2 };
		cout << "erstes Element " << iFeld[0] << endl;
		cout << "zweite Element " << iFeld[1] << endl;
		//b
		int spielfeld[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };

		for (int i = 0; i < sizeof(spielfeld) / sizeof(spielfeld[0]); i++) {
			for (int n = 0; n < sizeof(spielfeld[0]) / sizeof(int); n++) {
				cout << spielfeld[i][n] << endl;
			}
		}
		//
		const int iZweite = 1;
		cout << iZweite << endl;
	}
//	cout<< iZweite<<endl;//not in bounds
}
void vA1t6() {
	string vorname = "";
	string nachname = "";
	string sVornameNachname = "";
	string sNachnameVorname = "";
	cout << "Vorname:" << endl;
	cin >> vorname;
	cout << "Nachname:" << endl;
	cin >> nachname;
	sVornameNachname = vorname + " " + nachname;
	sNachnameVorname = nachname + "," + vorname;
	cout << sVornameNachname << endl;
	cout << sNachnameVorname << endl;
	char cFcVname = vorname.at(0);
	char cFcNname = nachname.at(0);
	int iName1 = static_cast<int>(cFcVname);
	int iName2 = static_cast<int>(cFcNname);
	cout << "Ausgabe ASCII von den Namen"<<endl;
	cout << iName1 << endl;
	cout << iName2 << endl;
}
void vA1t7() {
	string vorname = "";
		string nachname = "";
		string sVornameNachname = "";
		string sNachnameVorname = "";
		cout << "Vorname:" << endl;
		cin >> vorname;
		cout << "Nachname:" << endl;
		cin >> nachname;
		sVornameNachname = vorname + " " + nachname;
		sNachnameVorname = nachname + "," + vorname;
		cout << sVornameNachname << endl;
		cout << sNachnameVorname << endl;
		char cFcVname = vorname.at(0);
		char cFcNname = nachname.at(0);
		int iName1 = static_cast<int>(cFcVname);
		int iName2 = static_cast<int>(cFcNname);
		cout << "Ausgabe ASCII von den Namen"<<endl;
		cout << iName1 << endl;
		cout << iName2 << endl;

	//teil 7
 int positionB1=(iName1%64);
 int positionB2=(iName2%64);
 if(positionB1>32&&positionB1<64){
	 positionB1=positionB1-32;
 }
 if(positionB2>32&&positionB2<64){
	 positionB2=positionB2-32;
 }
 cout<<"Stelle im Deutschen Alphabet"<<endl;
cout<<positionB1<<endl;
cout<<positionB2<<endl;
	}


