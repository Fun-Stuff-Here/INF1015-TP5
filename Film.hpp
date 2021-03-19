/*
* Définition de la Classe Film, TD4-INF1015
*\file		Film.hpp
*\author	Elizabeth Michaud 2073093, Nicolas Dépelteau 2083544
*\date		21 mars 2021
* Créé le	26 février 2021
*/
#pragma once

#ifndef FILM_H
#define FILM_H

#include <string>
#include <vector>
#include <istream>
#include <memory>

#include "Item.hpp"
#include "Acteur.hpp"


class Film : virtual public Item {
public:
	Film() = default;
	~Film();
	Film(const std::string& titre, int annee, std::string& realisateur,
		 int recette, std::vector<std::shared_ptr<Acteur>>&& acteurs);

	std::shared_ptr<Acteur> trouverActeur(const std::string& nomRechercher) const;

protected:
	void print(std::ostream& ostream) const override;
	std::string realisateur_ = "";
	int recette_;
	std::vector<std::shared_ptr<Acteur>> acteurs_;
};


#endif 

