/*
* Définition de la Classe Livre, TD4-INF1015
*\file		Livre.hpp
*\author	Elizabeth Michaud 2073093, Nicolas Dépelteau 2083544
*\date		21 mars 2021
* Créé le	26 février 2021
*/
#pragma once
#ifndef LIVRE_H
#define LIVRE_H

#include <string>

#include "Item.hpp"

class Livre : virtual public Item
{
public:
	Livre() = default;
	Livre(const std::string& auteur, int nMillionsCopiesVendues,
		  int nPages, std::string& titre, int annee);
	~Livre() = default;

protected:
	void print(std::ostream& ostream) const override;
	std::string auteur_ = "";
	int nMillionsCopiesVendues_ = 0;
	int nPages_ = 0;

};



#endif
