/*
* Implémentation de la Classe Film, TD4-INF1015
*\file		Film.cpp
*\author	Elizabeth Michaud 2073093, Nicolas Dépelteau 2083544
*\date		7 mars 2021
* Créé le	26 février 2021
*/
#include "Film.hpp"
#include "Bibliotheque.hpp"

using namespace std;
using namespace gsl;
using namespace iter;



Film::Film(const std::string& titre, int annee, std::string& realisateur,
	int recette, std::vector<std::shared_ptr<Acteur>>&& acteurs)
	:Item(titre, annee),
	realisateur_(realisateur),
	recette_(recette)
{
	acteurs_ = acteurs;
}



shared_ptr<Acteur> Film::trouverActeur(const string& nomRechercher) const
{
	for (auto&& acteur : acteurs_)
	{
		if (acteur->getNom() == nomRechercher)
			return acteur;
	}
	return nullptr;
}


void Film::print(std::ostream& ostream) const
{
	Item::print(ostream);
	ostream << realisateur_ << ", " << recette_ << std::endl;
	for(auto&& acteur : acteurs_)
	{
		ostream << *acteur;
	}
}

Film::~Film()
{
	for(auto&& acteur : acteurs_)
	{
		acteur = nullptr;
	}
}