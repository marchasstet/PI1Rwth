/*
 * Versuch02Teil3.cpp
 *
 *  Created on: 19.04.2024
 *      Author: marcd
 */

#include <string>
#include <iostream>
#include <memory>
std::string sEncript(std::string *zuVerschluesseldesPW,char (*lookUPtr)[26]);
std::string sDecript (std::string *zuEntschuesseldesPW, char (*lookUpDecriptPtr)[26]);
bool korrektEingabe(std::string *seeWord);
int main() {
	/*
	 * lookup verschlüsselungs array und entschlüsslungs array
	 * */
	char lookUp[2][26] = { { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J','K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W','X', 'Y', 'Z' },
			               { 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'o','r', 'w', 'a', 's', 'q', 'z', 'p', 'e', 'x', 'y', 'c', 'b', 'i','t', 'u', 'v' } };
    char lookDW[2][26] = { { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j','k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
			               { 'M', 'V', 'U', 'A', 'R', 'B', 'C', 'D', 'W', 'E', 'F', 'G', 'H', 'I', 'J', 'Q', 'O', 'K', 'N', 'X', 'Y', 'Z', 'L', 'S', 'T', 'P'} };
/*
 * main die Nur abbricht wenn man möchte das das Programm abbricht
 * nimmt erst einen input der Das zu verschlüsselde wort ist, wirft dann dieses wort einmamal verschlüsselt aus und danach einmal entschlüsselt
 * die übergabe in die Funktionen ist einmal der Pointer auf das Wort und einmal die Refferenz
 * */
while (true){
	char (*lookUPtr)[26]= &lookUp[1];
	char (*looDWPtr)[26]= &lookDW[1];
	std::string sPw = " ";
	std::string *spPW = &sPw;
	std::cout<<"Wenn 0 wird beendet, Eingabe:"<<std::endl;
	std::cin >> *spPW;
	if (*spPW == "0") {
		std::cout<<"Ende"<<std::endl;
      break;
	}
if(korrektEingabe(spPW)==true){
	std::cout << *spPW << std::endl;
	std::cout<<"verschlüsselt:"<<std::endl;
	std::string sPWe = sEncript(spPW,lookUPtr);
	std::cout<< sPWe<< std::endl;
	std::cout<<"entverschlüsselt:"<<std::endl;
	std::string sDpe = sDecript(&sPWe,looDWPtr);
	std::cout<< sDpe<< std::endl;}

}
}
/*
 *@brief Funktion überprüft ob dieses Wort ein gültiges eingabe wort ist.
 *  geht das wort durch und überprüft ob jeder buchstabe ein großbuchstabe ist.
 * @param string *seeWort ist das eingabe wort das Überprüft werden soll ob es gültig is
*/
bool korrektEingabe(std::string *seeWord){
	for (int i = 0; i < seeWord->length(); i++)
			{
				//std::cout << i << std::endl;
				int stingAlszahl = static_cast<int>((*seeWord).at(i));
				int iBuchstabe = (stingAlszahl % 65);

				if (iBuchstabe > 26)
				{
					std::cout << "nur Großbuchstaben sind Erlaubt " << std::endl;
return false;


				}

			}
	return true;
}
/**
 *@brief nimmt das Wort das verschlüsselt werden soll und die Verschlüsselungs tabelle und geht dann das zu
 *@brief verschlüsselde wort duch und ersetz jedes mit dem dem entprechenden schlüssel
 *
 *@param string *zuVerschluesseldesPW pointer zu dem Eingabe wort
 *@param char lookUPtr pointer zu dem Array
 * */
std::string sEncript(std::string *zuVerschluesseldesPW,char (* lookUPtr)[26]) {
	//std::cout << *zuVerschluesseldesPW << std::endl;
	std::string verSchluesseltestPasswort = "";

		for (int i = 0; i < zuVerschluesseldesPW->length(); i++)
		{
			//std::cout << i << std::endl;

			int stingAlszahl = static_cast<int>((*zuVerschluesseldesPW).at(i));
			int iBuchstabe = (stingAlszahl % 65);

			if(iBuchstabe<26)
			{
			verSchluesseltestPasswort=verSchluesseltestPasswort+ (*lookUPtr)[iBuchstabe];
			//std::cout<<verSchluesseltestPasswort<<std::endl;
			}
			//std::cout <<"verschlüsseter buchstabe: "<< (*zuVerschluesseldesPW).at(i)<<" als " << *(*lookUPtr +(iBuchstabe)) << std::endl;
		}
		return verSchluesseltestPasswort;//wahrscheinlich dumm da daten kopie
	}
std::string sDecript(std::string *zuEntschuesseldesPW, char (*lookUpDecriptPtr)[26]){
	std::string entschluessedesPW="";
	for (int i = 0; i < zuEntschuesseldesPW->length(); i++)
			{
				//std::cout << i << std::endl;

				int stingAlszahl = static_cast<int>((*zuEntschuesseldesPW).at(i));
				int iBuchstabe = (stingAlszahl %97);

				if(iBuchstabe<26)
				{
					entschluessedesPW=entschluessedesPW+ (*lookUpDecriptPtr)[iBuchstabe];
				//std::cout<<entschluessedesPW<<std::endl;
				}
				//std::cout <<"verschlüsseter buchstabe: "<< (*zuEntschuesseldesPW).at(i)<<" als " << *(*lookUpDecriptPtr +(iBuchstabe)) << std::endl;
			}
			return entschluessedesPW;//wahrscheinlich dumm da daten kopie
		}

