/**
 * Praktikum Informatik 1 
 * 
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Reversi
 */

/**
* @mainpage Reversi
*
* Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "reversiKI.h"


/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
        {
            for(int i = 0; i < GROESSE_X; i++)
            {
                spielfeld[j][i] = 0;
            }
        }
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}



/**
* @brief Ausgabe des Spielfelds auf der Konsole
*
* Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
* Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
*
*  @param spielfeld  Spielfeld, das ausgeben wird
*/
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    //Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char) i) << " | " ;

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for(int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:
                    std::cout << "   " ;
                    break;
                case 1:
                    std::cout << " X ";
                    break;
                case 2:
                    std::cout << " O ";
                    break;
                default:
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        };  //for i
        std::cout <<  std::endl;
    }  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }

        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
* @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
*
* @param posX Index fuer die Spalte
* @param posY Index fuer die Zeile
* @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
*/
bool aufSpielfeld(const int posX, const int posY)
{

    // Hier erfolgt jetzt Ihre Implementierung ...
	if(posX<GROESSE_X &&posX>=0 && posY<GROESSE_Y && posY>=0)
	{
		return true;
	}
    return false;
}


/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X],
		const int aktuellerSpieler, const int posX, const int posY) {
	int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
									   //               if aktuellerSpieler == 2 -> gegner = 1

//	if (spielfeld[posY][posX] != 2||1) // ist das Feld leer?
//			{
//		//gleiches fro schleifen konstrukt wie unten nur dass spieler ohne fehlt drei nicht durch also denkfehler rewise
//
//		return false;
//	}
	if (spielfeld[posY][posX] != 0) // ist das Feld leer?
					{
				//gleiches fro schleifen konstrukt wie unten nur dass spieler ohne fehlt drei nicht durch also denkfehler rewise

				return false;
			}

	// Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
	for (int j = -1; j <= 1; j++)
	{
		for (int i = -1; i <= 1; i++)
		{
			if(!aufSpielfeld(posX+i, posY+j)){continue;}
			if (spielfeld[posY + j][posX + i] == gegner)
			{
				//return true;
				int l=2;
				while(aufSpielfeld(posX+(i*l), posY+(j*l)))
				{

					if (spielfeld[posY + (j *l)][posX + (i * l)] == aktuellerSpieler)
										{
											return true;
										}


				if (spielfeld[posY + (j *l)][posX + (i * l)] == 0) {
										break;

									}
				l++;

			}

			// Hier erfolgt jetzt Ihre Implementierung ...
		}
	}
	}

	return false;
}


/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X],
		const int aktuellerSpieler, const int posX, const int posY) {
	int gegner = 3 - aktuellerSpieler;

	if (zugGueltig((spielfeld), aktuellerSpieler, posX, posY)) {
		spielfeld[posY][posX] = aktuellerSpieler;
	}
	//Alle Richtungen bearbeiten
	for (int j = -1; j <= 1; j++) {
		for (int i = -1; i <= 1; i++) {
			if (!aufSpielfeld(posX + i, posY + j)) { //wenn nicht in spielfeld nächste Seite
				continue;
			}

			if (spielfeld[posY + j][posX + i] == gegner) {
				//return true;
				int l = 1; // 0 te feld ist immer aktueller Spieler
				while (aufSpielfeld(posX + (i * l), posY + (j * l))) { //zähl wie viel felder du befüllen musst wenn danach n aktuellerSpieler kommt sonst abbrechen

					if (spielfeld[posY + (j * l)][posX + (i * l)]
							== aktuellerSpieler) {
						for (int k = l; k >= 0; k--) {
							int temp1 = posX + k * i;
							int temp2 = posY + k * j; //erstezt für jedes Feld incl den gegner mit den eingen stein
							spielfeld[temp2][temp1] = aktuellerSpieler;
						}
						break;
					}

					if (spielfeld[posY + (j * l)][posX + (i * l)] == 0) { //wenn leer beende und mach nichts nächst richtiung
						break;
					}

					l++;
				}
			}
		}
	}
}
/**
 * @brief Bestimmt die Anzahl der möglichen Züge für den aktuellen Spieler.
 *
 * Diese Funktion überprüft das gegebene Spielfeld und zählt die Anzahl der gültigen Züge,
 * die der aktuelle Spieler machen kann. Ein Zug ist gültig, wenn die Funktion `zugGueltig`
 * für die gegebene Position (i, j) wahr zurückgibt.
 *
 * @param spielfeld Das aktuelle Spielfeld als 2D-Array, in dem jeder Eintrag den Zustand eines Feldes repräsentiert.
 * @param aktuellerSpieler Die ID des aktuellen Spielers (z.B. 1 oder 2), für den die möglichen Züge berechnet werden.
 * @return Die Anzahl der möglichen Züge, die der aktuelle Spieler machen kann.
 */
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    // Hier erfolgt jetzt Ihre Implementierung ...
	int moeglichkeiten=0;
	//std::cout<<"moeglicheZuege: "<<std::endl;
	for(int i=0;i<GROESSE_X;i++){
		for (int j=0;j<GROESSE_Y;j++){
			if(zugGueltig(spielfeld,aktuellerSpieler,i,j)==true){
				moeglichkeiten++;

//				std::cout<<"Zug an "<<i <<","<<j<<" moeglich"<<std::endl;
				//std::cout<<"["<<mog <<","<<j+1<<"] ";
			}
		}
	}
	//std::cout<<std::endl;
    
    return moeglichkeiten;
}
/**
 * @brief Bestimmt die Anzahl der möglichen Züge für den aktuellen Spieler und gibt diese aus.
 *
 * Diese Funktion überprüft das gegebene Spielfeld und zählt die Anzahl der gültigen Züge,
 * die der aktuelle Spieler machen kann. Ein Zug ist gültig, wenn die Funktion `zugGueltig`
 * für die gegebene Position (i, j) wahr zurückgibt. Zusätzlich werden die möglichen Züge
 * in der Konsole ausgegeben.
 *
 * @param spielfeld Das aktuelle Spielfeld als 2D-Array, in dem jeder Eintrag den Zustand eines Feldes repräsentiert.
 * @param aktuellerSpieler Die ID des aktuellen Spielers (z.B. 1 oder 2), für den die möglichen Züge berechnet werden.
 * @return Die Anzahl der möglichen Züge, die der aktuelle Spieler machen kann.
 */
int moeglicheZug(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    // Hier erfolgt jetzt Ihre Implementierung ...
	int moeglichkeiten=0;
	std::cout<<"moeglicheZuege: "<<std::endl;
	for(int i=0;i<GROESSE_X;i++){
		for (int j=0;j<GROESSE_Y;j++){
			if(zugGueltig(spielfeld,aktuellerSpieler,i,j)==true){
				moeglichkeiten++;
				char mog= i+65;
//				std::cout<<"Zug an "<<i <<","<<j<<" moeglich"<<std::endl;
				std::cout<<"["<<mog <<","<<j+1<<"] ";
			}
		}
	}
	std::cout<<std::endl;

    return moeglichkeiten;
}


bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
        std::cin >> eingabe;
        if(eingabe[0]=='0'&&eingabe[1]=='0'){break;}
        posX = (int) eingabe[0] % 32 -1;
        posY = (int) eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            //accept turn;
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl;

    return true;
}
/**
 * @brief Führt das Spiel aus, basierend auf den Spieler-Typen.
 *
 * Diese Methode initialisiert das Spielfeld, führt die Spielzüge durch und ermittelt den Gewinner.
 * Die Spieler können entweder menschlich oder Computer sein, und die Methode behandelt verschiedene
 * Kombinationen von Spieler-Typen.
 *
 * @param spielerTyp Ein Array, das die Typen der beiden Spieler enthält. Der Wert kann COMPUTER oder MENSCH sein.
 */

void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    //Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;
    //zeigeSpielfeld(spielfeld);
    int runde=0;
    while(true){

		if (spielerTyp[0] == COMPUTER && spielerTyp[1]== COMPUTER)
		{

			if (computerZug(spielfeld, aktuellerSpieler) == false)
			{
				if (computerZug(spielfeld, 3 - aktuellerSpieler) == false)
				{
					break;
				}
				aktuellerSpieler = 3 - aktuellerSpieler;//theorethis gegnerturn

			}
			aktuellerSpieler = 3 - aktuellerSpieler;//wieder gleicher turn
			computerZug(spielfeld, aktuellerSpieler);
			zeigeSpielfeld(spielfeld);


		}

    	    	else if(((spielerTyp[1]==COMPUTER) && (spielerTyp[0]==MENSCH))){
    	    		zeigeSpielfeld(spielfeld);
    	    		if(menschlicherZug(spielfeld,aktuellerSpieler)==false){break;}
    	    		aktuellerSpieler=3-aktuellerSpieler;
    	    		    	    		zeigeSpielfeld(spielfeld);
    	    		if(computerZug(spielfeld,aktuellerSpieler)==false){break;}



    	    	}
    	    	else if (((spielerTyp[0] == COMPUTER) && (spielerTyp[1] == MENSCH))) {
			if (computerZug(spielfeld, aktuellerSpieler) == false) {
				break;
			}
			aktuellerSpieler = 3 - aktuellerSpieler;
			zeigeSpielfeld(spielfeld);
			if (menschlicherZug(spielfeld, aktuellerSpieler) == false) {
				break;
			}
		}
    	    	else{
    	zeigeSpielfeld(spielfeld);
    	if(moeglicheZuege(spielfeld,aktuellerSpieler)>0){
    	std::cout<<"Zug Spieler: "<<aktuellerSpieler<<": "<<std::endl;
    	moeglicheZug(spielfeld,aktuellerSpieler);
    	int iPosX=0;
    	int iPosY=0;
    	int cancel=0;
    	while(true){
//    	char x;
//if(x=='0'){break;}
//
//    	std::cin>>x;
//    	std::cin>>iPosY;
//    iPosX=((int)x%32) -1;
    		std::string eingabe;
    		        std::cout << std::endl << "Du bist " << ". Dein Zug (z.B. A1, a1): " ;
    		        std::cin >> eingabe;
    		        if(eingabe[0]=='0'&&eingabe[1]=='0'){break;}
    		        iPosX = (int) eingabe[0] % 32 -1;
    		        iPosY = (int) eingabe[1] - 49;
//	 if((int)x>96&& x<123){iPosX=((int)x)-97;} //für die ascii int int umwandlung klein bzw gross buchstabe
//	 else if((int)x>64&&x<90){iPosX=((int)x)-65;}

    	if(zugGueltig(spielfeld,aktuellerSpieler,iPosX,iPosY)){


    		     		break;
    	}
    	else{
    		std::cout<<"bitte Gib einen Gueltigen Wert ein!"<<std::endl;
    	}
    	}
    	if(iPosX==0&&iPosY==0){break;}
    	zugAusfuehren(spielfeld,aktuellerSpieler,iPosX,iPosY);
    	}

    	}
    	if(moeglicheZuege(spielfeld, aktuellerSpieler) == 0 && moeglicheZuege(spielfeld, (3-aktuellerSpieler)==0)){
    	    		break;
    	    	}
    	    	else if(moeglicheZuege(spielfeld, aktuellerSpieler) == 0){
    	    			aktuellerSpieler=3-aktuellerSpieler;
    	    			continue;
    	    		}
    	    	else{
    	    		aktuellerSpieler=3-aktuellerSpieler;
    	    	}

    }

    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    //
    // Hier erfolgt jetzt Ihre Implementierung ...
   switch (gewinner(spielfeld))
    {
    case 0:
    	std::cout<<"Unentschieden!"<<std::endl;
    break;
    case 1:
    	std::cout<<"Player 1 gewinnt!"<<std::endl;
    	break;
    case 2:
    	std:: cout<<"Player 2 gewinnt!"<< std::endl;
    	break;
    default:
        	std::cout<<"Konnte nicht ausgewertet weerden!"<<std::endl;
    }
}
int main()
{
    if (TEST == 1)
    {
        bool gesamtErgebnis = ganzenTestAusfuehren();
        if (gesamtErgebnis == true)
        {
            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
        }
        else
        {
            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
            exit(1);
        }
        std::cout << std::endl << std::endl;
    }
    
    // Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
    // implementiert haben (waeren sonst doppelt)
    while(true){
    	int spielerTyp1[2]={ MENSCH,MENSCH};
		int spielerTyp2[2]={ COMPUTER,MENSCH};
		int spielerTyp3[2] = { COMPUTER, COMPUTER };
		int  spielerTyp4[2] = { MENSCH,COMPUTER};
    	std::cout<<"Bitte Spielmodi wählen"<<std::endl;
    	std::cout<<"0: Beende Programm"<< std::endl;
    	std::cout<<"1: Mensch VS Mensch"<< std::endl;
    	std::cout<<"2: Mesnch VS Maschiene"<< std::endl;
    	std::cout<<"3: Maschiene VS Maschiene"<< std::endl;
    	int input=0;
    	std::cin>>input;
    	if(input==0){
    		std::cout<<"beende Programm"<<std::endl;
    		break;}
    	switch (input){
    	case 1:

    		    spielen(spielerTyp1);
    		break;
		case 2: {
			std::cout << "soll Spieler 1 der Computer sein oder spieler 2?"
					<< std::endl;
			int eingang;
			std::cin >> eingang;
			if (eingang == 1) {
				spielen(spielerTyp2);
			}

			else if (eingang == 2) {
				spielen(spielerTyp4);
			} else {
				std::cout << "error" << std::endl;
			}
			break;
		}
break;

    	case 3:

    		spielen(spielerTyp3);
    		break;
    	default:
    		std::cout<<"nicht Gueltige Eingabe bitte neu eingeben!"<< std::endl;
    		break;
    	}

    }
//    int spielfeld[GROESSE_Y][GROESSE_X];
//
//    initialisiereSpielfeld(spielfeld);
//
//    zeigeSpielfeld(spielfeld);

    // int spielerTyp[2] = { COMPUTER, COMPUTER };  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
    // spielen(spielerTyp);
    //
    // Hier erfolgt jetzt Ihre Implementierung ...
    
    return 0;
}
