/*
* Définition de la Classe FilmLivre, TD4-INF1015
*\file		FilmLivre.hpp
*\author	Elizabeth Michaud 2073093, Nicolas Dépelteau 2083544
*\date		21 mars 2021
* Créé le	26 février 2021
*/
#pragma once
#ifndef FILMLIVRE_H
#define FILMLIVRE_H

#include <iostream>

#include "Film.hpp"
#include "Livre.hpp"

class FilmLivre : public Film, public Livre
{
public:
	FilmLivre(Livre livre, Film film);
	~FilmLivre()=default;

protected:
	void print(std::ostream& ostream) const override;

};



#endif 


