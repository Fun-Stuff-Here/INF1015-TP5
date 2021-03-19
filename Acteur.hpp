/*
* D�finition de la Classe Acteur, TD4-INF1015
*\file		Acteur.hpp
*\author	Elizabeth Michaud 2073093, Nicolas D�pelteau 2083544
*\date		21 mars 2021
* Cr�� le	26 f�vrier 2021
*/
#pragma once
#ifndef ACTEUR_H
#define ACTEUR_H

#include <string>
#include <istream>
#include <memory>
#include <iostream>

class Acteur{
public:
	Acteur() = default;
	Acteur(const std::string& nom, const int anneeNaissance, const char sexe);
	~Acteur() = default;
	std::string getNom();
	friend std::ostream& operator<< (std::ostream& ostream, const Acteur& item);

private:
	std::string nom_ = "";
	int anneeNaissance_ =0;
	char sexe_ =' ';

};

std::ostream& operator<< (std::ostream& ostream, const Acteur& item);




#endif 


