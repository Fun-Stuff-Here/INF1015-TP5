/*
* Impl�mentation de la Classe Item, TD4-INF1015
*\file		Item.cpp
*\author	Elizabeth Michaud 2073093, Nicolas D�pelteau 2083544
*\date		7 mars 2021
* Cr�� le	26 f�vrier 2021
*/
#include "Item.hpp"
#include "Bibliotheque.hpp"

Item::Item(const std::string& titre, int annee) : titre_(titre), annee_(annee) {}



void Item::print(std::ostream& ostream) const {
	ostream << titre_ << ", " << annee_ << ", ";
}

std::string Item::getTitre() const {
	return titre_;
}

int Item::getAnnee() const {
	return annee_;
}

std::ostream& operator<< (std::ostream& ostream, const Item& item) {
	item.print(ostream);
	return ostream;
}





