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
void vA1t1();
void vA1t2();
void vA1t3();
int main()
{

    // Hier folgt Ihr eigener Code


   vA1t1();

   return 0;
}
void vA1t1(){
	int iErste = 0;
	    int iZweite = 0;

	    // Hier folgt Ihr eigener Code

       std::cout<<"test";
       std:: cin >> iErste;
	    std:: cin >> iZweite;
	     int iSumme = iErste+iZweite; 
	     int iQuotient = iErste/iZweite;
	     std::cout<<"Ergebins der Summe ist "<<iSumme<<std::endl;
	     std::cout<<"Ergebins der Division ist "<<iQuotient<<std::endl;

}
void vA1t2(){
	int iErste = 0; 
	    int iZweite = 0;

	    // Hier folgt Ihr eigener Code

std::cout<<"Int 1"<< std::endl;
	    std:: cin >> iErste;
	    std::cout<<"Int 2"<< std::endl;
	    std:: cin >> iZweite;
	     double dSumme = iErste+iZweite;
	     double dQuotient = iErste/iZweite;
	     std::cout<<"Ergebins der Summe ist "<<dSumme<<std::endl;
	     std::cout<<"Ergebins der Division ist "<<dQuotient<<std::endl;

}
void vA1t3(){
	int iErste = 0;
	    int iZweite = 0;

	    // Hier folgt Ihr eigener Code

	    std::cout<<"Int 2"<< std::endl;
	    std:: cin >> iErste;
	    std::cout<<"Int 2"<< std::endl;
	    std:: cin >> iZweite;
	     double dSummeCast = (double)iErste+(double)iZweite;
	     double dQuotientCast =(double) iErste/(double)iZweite;
	     std::cout<<"Ergebins der Summe ist "<<dSummeCast<<std::endl;
	     std::cout<<"Ergebins der Division ist "<<dQuotientCast<<std::endl;

}
