//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Student.h"

/**
 * @brief Konstruktor, der einen neuen Studenten mit allen Werten erstellt
 *
 * @param matNr Matrikelnummer
 * @param name Name
 * @param geburtstag Geburtstag
 * @param adresse Adresse
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }

/**
 * @brief Standardkonstruktor, der einen leeren Studenten erstellt
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }

/**
 * @brief Gibt die Matrikelnummer des Studenten zurueck
 *
 * @return Matrikelnummer
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief Gibt den Namen des Studenten zurueck
 *
 * @return Name
 */
std::string Student::getName() const
{
    return name;
}

/**
 * @brief Gibt den Geburtstag des Studenten zurueck
 *
 * @return Geburtstag
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief Gibt die Adresse des Studenten zurueck
 *
 * @return Adresse
 */
std::string Student::getAdresse() const
{
    return adresse;
}

/**
 * @brief Gibt alle Daten des Studenten in einer Zeile aus
 */
void Student::ausgabe(std::ostream& out) const
{
    out << name << ", MatNr. " << matNr << ", geb. am "
              << geburtstag << ", wohnhaft in " << adresse
              << std::endl;
}
/**
 * @brief Vergleicht zwei Studenten auf Gleichheit anhand ihrer Matrikelnummer.
 *
 * Diese Funktion überprüft, ob die Matrikelnummer dieses Studenten mit der Matrikelnummer
 * eines anderen Studenten übereinstimmt.
 *
 * @param[in] student Der zu vergleichende Student.
 * @return true, wenn die Matrikelnummern gleich sind, sonst false.
 */
bool Student::operator ==(const Student& student)const{
	if(matNr==student.getMatNr()){
		return true;
	}
	return false;
}
/**
 * @brief Überprüft, ob die Matrikelnummer dieses Studenten größer ist als die eines anderen Studenten.
 *
 * Diese Funktion überprüft, ob die Matrikelnummer dieses Studenten größer ist als die Matrikelnummer
 * eines anderen Studenten.
 *
 * @param[in] student Der zu vergleichende Student.
 * @return true, wenn die Matrikelnummer dieses Studenten größer ist, sonst false.
 */
bool Student::operator >(const Student &student) const {
	if (matNr > student.getMatNr()) {
		return true;
	}
	return false;
}
/**
 * @brief Überprüft, ob die Matrikelnummer dieses Studenten kleiner ist als die eines anderen Studenten.
 *
 * Diese Funktion überprüft, ob die Matrikelnummer dieses Studenten kleiner ist als die Matrikelnummer
 * eines anderen Studenten.
 *
 * @param[in] student Der zu vergleichende Student.
 * @return true, wenn die Matrikelnummer dieses Studenten kleiner ist, sonst false.
 */
bool Student::operator <(const Student &student) const {
	if (matNr < student.getMatNr()) {
		return true;
	}
	return false;
}

