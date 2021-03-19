/*
* Implémentation de la Classe Livre, TD4-INF1015
*\file		Livre.cpp
*\author	Elizabeth Michaud 2073093, Nicolas Dépelteau 2083544
*\date		7 mars 2021
* Créé le	26 février 2021
*/
#include "Livre.hpp"
#include "Bibliotheque.hpp"

Livre::Livre(const std::string& auteur, int nMillionsCopiesVendues, int nPages, std::string& titre, int annee) :
	Item(titre, annee),
	auteur_(auteur),
	nMillionsCopiesVendues_(nMillionsCopiesVendues),
	nPages_(nPages)
{}

void Livre::print(std::ostream& ostream) const
{
	Item::print(ostream);
	ostream << auteur_ << ", " << nMillionsCopiesVendues_ << ", " << nPages_ <<std::endl;
}