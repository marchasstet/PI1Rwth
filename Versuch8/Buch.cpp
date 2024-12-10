/*
 * Buch.cpp
 *
 *  Created on: 03.07.2024
 *      Author: marcd
 */
#include "Medium.h"
#include "Buch.h"

Buch::Buch(std::string initTitel, std::string initAutor):
Medium::Medium(initTitel),
author(initAutor)
{
}

Buch::~Buch() {
}
/**
 * @brief Gibt die Details des Buchs aus.
 *
 * Diese Methode gibt die allgemeinen Details eines Mediums durch Aufruf der `Medium::ausgabe` Methode
 * und die spezifischen Details des Buchs, wie den Autor, auf der Konsole aus.
 */
void Buch::ausgabe() const
{
	Medium::ausgabe();
	std::cout<<"Autor: "<<author<<std::endl;
}
