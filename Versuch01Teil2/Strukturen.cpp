/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::cin;
using std::string;

typedef struct{
	string sName="";
	string sNachname="";
	int iGeburtsjahr=1;
	int iAlter=0;

}Person;
void vAusgabe(Person P);
int main()
{
	Person nBenutzer;

	Person nKopieEinzeln;
	Person nKopieGesamt;
	cout<<"vorName: "<<endl;
	cin>>nBenutzer.sName;
	cout<<"nachName: "<<endl;
	cin>>nBenutzer.sNachname;
	cout<<"GebJahr: "<<endl;
	cin>>nBenutzer.iGeburtsjahr;
	cout<<"Alter: "<< endl;
	cin>>nBenutzer.iAlter;
	//einzelden #Kopieren
	nKopieEinzeln.sName=nBenutzer.sName;
	nKopieEinzeln.sNachname=nBenutzer.sNachname;
	nKopieEinzeln.iGeburtsjahr=nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter=nBenutzer.iAlter;
	//zusammen Kopiernen
	nKopieGesamt=nBenutzer;
	//ausgabe von den Kopien
	vAusgabe(nKopieEinzeln);
	vAusgabe(nKopieGesamt);
    return 0;
    
}
void vAusgabe(Person P){
 cout<<"Name: "<< P.sName <<endl;
 cout<<"Nachname: "<<P.sNachname <<endl;
 cout<<"Geburtsjahr: "<< P.iGeburtsjahr <<endl;
 cout<<"Alter: "<<P.iAlter <<endl;
}
