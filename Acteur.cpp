/*
* Implémentation de la Classe Acteur, TD4-INF1015
*\file		Acteur.cpp
*\author	Elizabeth Michaud 2073093, Nicolas Dépelteau 2083544
*\date		7 mars 2021
* Créé le	26 février 2021
*/
#pragma once

#include "Acteur.hpp"
#include "Bibliotheque.hpp"

using namespace std;
using namespace gsl;
using namespace iter;


Acteur::Acteur(const std::string& nom, const int anneeNaissance, const char sexe)
: nom_(nom),anneeNaissance_(anneeNaissance),sexe_(sexe) {}




std::string Acteur::getNom() { return nom_; }

std::ostream& operator<< (std::ostream& ostream, const Acteur& acteur)
{
	ostream << "\t" << acteur.nom_ << ", " << acteur.anneeNaissance_ << ", " << acteur.sexe_ << std::endl;
	return ostream;
}