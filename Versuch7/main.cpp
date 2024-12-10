/** @mainpage
 *
 * Praktikum Informatik 1 MMXXIV <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "Student.h"
#include <vector>
std::ostream& operator << (std::ostream& out, const Student& student)
{
	student.ausgabe(out);

	return out;
}
int main()
{
    std::vector <Student>studentenListe;
    Student student;
   unsigned int matNr1=0;
    char abfrage;
    unsigned int matNr = 0;
                        std::string name = "";
                        std::string geburtstag = "";
                        std::string adresse = "";
//    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
//    std::cin >> abfrage;
//    std::cin.ignore(10, '\n');
//
//    if (abfrage != 'j')
//    {
//        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
//        studentenListe.push_back(student);
//        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
//        studentenListe.push_back(student);
//        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
//        studentenListe.push_back(student);
//        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
//        studentenListe.push_back(student);
//        student = Student(23456, "Walter Rodenstock", "15.10.1963", "W�llnerstr.9");
//        studentenListe.push_back(student);
//    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
				  << "(4): Datenbank rückwärts ausgeben" << std::endl
				  << "(5): Datenbank element löschen" << std::endl
				  << "(6): Datenbank vorne einfüegen" << std::endl
				  << "(7): Datei einlesen" << std::endl
				  << "(8): Datei speichern" << std::endl
				  << "(9): Daten sortieren" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {


                    std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(student);
                }
                break;

            // Datenelement vorne entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                       auto student1 = studentenListe.begin();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                       // student1->ausgabe();
                        std::cout<<*student1;
                        studentenListe.erase(student1);
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':{
                if(!studentenListe.empty())
                {
                	studentenListe.begin();
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                   for(auto &it:studentenListe )
                   {
                              	  // it.ausgabe();
                	   std::cout<<it;

                   }//vekor ausgeben
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;}
                //Datenbank rückewarts ausgeben
            case '4':
            {
			if (!studentenListe.empty())
			{
				std::cout << "Inhalt der Liste in rücklaufender Reihenfolge:"
						<< std::endl;
				//studentenListe.ausgabeRueckwaerts();
				for (auto it = studentenListe.rbegin(); it != studentenListe.rend(); ++it) {
				       // it->ausgabe();
					std::cout<<*it;
				    }
			}
			else
			{
				std::cout << "Die Liste ist leer!\n\n";
			}
			break;
            }
			case '5':
			{
			for (auto &it : studentenListe)
			{
				std::cout<<it;

			}
                std::cout<<" gib die zu Löschende Matrikel Nummer ein: "<<std::endl;
				std::cin>>matNr1;
				//studentenListe.datenElementLoeschen(matNr1);
				Student student3 = Student(matNr1, "", "", "");
				std::vector<Student>::iterator iterator;
				iterator=find(studentenListe.begin(),studentenListe.end(),student3);
				if(!(student3 == *iterator))
				            		{
				            			std::cout<<"Kein eintrag. "<<std::endl;
				            			break;
				            		}
				std::cout<<*iterator;
				std::cout<<"Erfolgreich gelöscht"<<std::endl;
				studentenListe.erase(iterator);

				break;}
			case '6':{


				                    std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
				                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

				                    std::cout << "Geburtsdatum: ";
				                    getline(std::cin, geburtstag);

				                    std::cout << "Adresse: ";
				                    getline(std::cin, adresse);

				                    std::cout << "Matrikelnummer: ";
				                    std::cin >> matNr;
				                    std::cin.ignore(10, '\n');

				                    student = Student(matNr, name, geburtstag, adresse);

				                    studentenListe.insert(studentenListe.begin(),student);
				                    std::cout<<"Student Vorne Eigefügt"<<std::endl;
				                    break;}
			case '7':{//datei einlesen
				std::string dateiname;
				std::cout<<"Bitte gib den namen der Datei an"<<std::endl;
				std::cin>>dateiname;
				std::ifstream auslesen(dateiname);

				if(!auslesen){
					std::cout<<"fehler beim auslesen der Datei"<<std::endl;
					break;
				}
				studentenListe.clear();
				std::cout<<"datei erfolgreich eingelesen"<<std::endl;
					while(!auslesen.eof()){
					unsigned int matNr2 = 0;
					std::string name = "";
					std::string bDay = "";
					std::string adresse = "";
					auslesen>>matNr2;
					auslesen.ignore(1,'\n');
					std::getline(auslesen , name);
					std::getline(auslesen , bDay);
					std::getline(auslesen , adresse);
					if(matNr2==0 || name==""||bDay==""||adresse==""){
						break;
					}

					Student student1 = Student(matNr2,name,bDay,adresse);
					studentenListe.push_back(student1);


				}

				break;
			}
			case '8':{//datein Spiechern
				std::string name="";
				std::cout<<"wie soll die zur spichernde Datei genannt werden?:"<<std::endl;
				std::cin>>name;
				std::ofstream eingabe;
				eingabe.open(name);
				while(!studentenListe.empty()){
					Student studentAus=studentenListe.back();
					eingabe<< studentAus.getMatNr()<<std::endl;
					eingabe<< studentAus.getName()<<std::endl;
					eingabe<< studentAus.getGeburtstag()<<std::endl;
					eingabe<< studentAus.getAdresse()<<std::endl;
					studentenListe.pop_back();

				}
             std::cout<<"spiechern Erfolgreich!"<<std::endl;
             eingabe.close();
				break;
			}
			case '9':{
			if (studentenListe.empty()) {
				std::cout << "liste leer" << std::endl;
				break;
			}
			std::sort(studentenListe.begin(),studentenListe.end());
			for(auto &it:studentenListe )
			                   {
			                              	  // it.ausgabe();
			                	   std::cout<<it;

			                   }
			break;
			}
            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
