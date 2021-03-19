/*
* Implémentation de la Classe ListeFilms, TD3-INF1015
*\file		ListeFilms.cpp
*\author	Elizabeth Michaud 2073093, Nicolas Dépelteau 2083544
*\date		7 mars 2021
* Créé le	23 février 2021
*/
#include "ListeFilms.hpp"

typedef uint8_t UInt8;
typedef uint16_t UInt16;

using namespace std;
using namespace gsl;
using namespace iter;








void ListeFilms::afficher() const
{
	static const string ligneDeSeparation = "\n\033[35mфффффффффффффффффффффффффффффффффффффффф\033[0m\n";
	cout << ligneDeSeparation;
	for (auto&& film : *this)
	{
		cout << film;
		cout << ligneDeSeparation;
	}
}

ostream& ListeFilms::afficherActeur(ostream& ostream, const shared_ptr<Acteur>& acteur)
{
	ostream << "  " << acteur->nom << ", " << acteur->anneeNaissance << " " << acteur->sexe << endl;
	return ostream;
}


Film* ListeFilms::operator[] (size_t const index) const
{
	return elements_[index];
}

ostream& operator<< (ostream& ostream, const Film* film)
{
	ostream << " " << film->titre << ", " << film->realisateur << ", " << film->anneeSortie << ", " << film->recette << endl;
	for (auto&& acteur : film->acteurs)
	{
		ostream << "  " << acteur->nom << ", " << acteur->anneeNaissance << " " << acteur->sexe << endl;
	}
	return ostream;
}

