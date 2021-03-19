/*
* Implémentation de la Classe Film, TD4-INF1015
*\file		Film.cpp
*\author	Elizabeth Michaud 2073093, Nicolas Dépelteau 2083544
*\date		7 mars 2021
* Créé le	4 mars 2021
*/
#include "FilmLivre.hpp"
#include "Bibliotheque.hpp"

using namespace std;


FilmLivre::FilmLivre(Livre livre, Film film)
	:Item(film.getTitre(), film.getAnnee()), Film(film), Livre(livre)
{}


void FilmLivre::print(std::ostream& ostream) const
{
	ostream << "Film :" << std::endl;
	Film::print(ostream);
	ostream << "Livre :" << std::endl;
	ostream << auteur_ << ", " << nMillionsCopiesVendues_ << ", " << nPages_ << std::endl;
}
