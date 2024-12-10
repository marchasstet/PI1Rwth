//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

long int fibonacci( int n)
{
   long int previousFib = 0;//1
   long int currentFib = 1;
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
    for (int i = 0; i < n; i++)
    {
    	long int newFib=previousFib;
    	previousFib=currentFib;
    	currentFib=newFib+currentFib;


    }
    return previousFib ;//currentFib
}

int main ()
{
    std::cout << " Fibonacci - Zahlen von 0 bis 12:" << std::endl ;
    for (int i = 0; i <= 47 ; i ++)
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl ;
    }
    return 0;
}
