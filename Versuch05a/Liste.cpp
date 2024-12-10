//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr,nullptr);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
    	neuesElement->setPrev(back);//eingefuegt
        back->setNext(neuesElement);
        back = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enth�lt nur ein Listenelement
    {
        delete front;                                        // Listenelement l�schen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr);//eingefuegt
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}
/**
 * @brief Gibt die Elemente der Liste in umgekehrter Reihenfolge aus.
 *
 * Diese Funktion traversiert die Liste von hinten nach vorne und gibt die Daten jedes
 * Listenelements aus, indem die `ausgabe`-Methode aufgerufen wird.
 */
void Liste::ausgabeRueckwaerts() const
{
	ListenElement* cursor = back;
	 while (cursor != nullptr){
	cursor->getData().ausgabe();
	cursor = cursor->getPrev();
	 }
}
/**
 * @brief Löscht ein Element der Liste basierend auf der Matrikelnummer.
 *
 * Diese Methode durchsucht die Liste nach einem Element mit der gegebenen Matrikelnummer (`matNr`).
 * Wenn das Element gefunden wird, wird es aus der Liste entfernt. Wenn die Liste leer ist oder
 * das Element nicht gefunden wird, wird eine entsprechende Nachricht ausgegeben.
 *
 * @param matNr Die Matrikelnummer des zu löschenden Elements.
 * @return true, wenn das Element erfolgreich gelöscht wurde, false andernfalls.
 */
bool Liste::datenElementLoeschen(const unsigned int matNr)
{
	ListenElement* cursor=front;

	if(empty()){
			std::cout<<"liste ist leer"<<std::endl;
			return false;
		}

 while(cursor->getData().getMatNr()!=matNr)
 {
	 if(cursor->getNext() == nullptr)
	 			{
		 std::cout<<"matrikelNR nicht enthalten"<<std::endl;
		 return false;
	 			}
	 cursor = cursor->getNext();
 }

	if(front == back)
		{
			front = NULL;
			back = NULL;
		}
	else if(cursor==front){
		//std::cout<<"hier komm ich noch hin!"<<std::endl;
		front=cursor->getNext();
		cursor->getNext()->setPrev(cursor->getPrev());
		//std::cout<<"hier komm ich noch hin!"<<std::endl;
	}

	else if(cursor==back){
		cursor->getPrev()->setNext(cursor->getNext());
				back = cursor->getPrev();
		}
	else{
 ListenElement* cursor2=cursor->getPrev();
 ListenElement* cursor3=cursor->getNext();
 cursor2->setNext(cursor3);
 cursor3->setPrev(cursor2);
	}
	std::cout<<"Student "<<(cursor->getData().getName())<<" mit MatNr: "<<matNr<<" geloescht"<<std::endl;
 delete cursor;


 ausgabeVorwaerts();
 return true;
}
/**
 * @brief Fügt ein neues Element am Anfang der Liste ein.
 *
 * Diese Methode erstellt ein neues Listenelement mit den übergebenen Daten des Studenten (`pData`)
 * und fügt es an den Anfang der Liste ein. Wenn die Liste leer ist, wird das neue Element sowohl
 * als Anfangs- als auch als Endelement der Liste gesetzt. Andernfalls wird es am Anfang der Liste
 * eingefügt und die Verbindungen entsprechend aktualisiert.
 *
 * @param pData Die Daten des Studenten, die im neuen Listenelement gespeichert werden sollen.
 */
void Liste::datenElementVorneEinfuegen(Student pData){
	 ListenElement* neuesElement = new ListenElement(pData, nullptr,nullptr);

	    if (front == nullptr)                                       // Liste leer?
	    {
	        front = neuesElement;
	        back = neuesElement;
	    }
	    else
	    {
	    	neuesElement->setNext(front);//eingefuegt
	        front->setPrev(neuesElement);
	        front = neuesElement;
	    }
}
