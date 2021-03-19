/*
* Programme qui lit un fichier de film et livres et les manipules, TD4-INF1015
*\file		TP4.cpp
*\author	Elizabeth Michaud 2073093, Nicolas Dépelteau 2083544
*\date		7 mars 2021
* Créé le	26 février 2021
*/

#define _CRT_SECURE_NO_WARNINGS // On permet d'utiliser les fonctions de copies de chaînes qui sont considérées non sécuritaires.
#include "Bibliotheque.hpp"

using namespace std;
using namespace gsl;
using namespace iter;

int main()
{
#ifdef VERIFICATION_ALLOCATION_INCLUS
	bibliotheque_cours::VerifierFuitesAllocations verifierFuitesAllocations;
#endif
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.

	static const string ligneDeSeparation = "\n\033[35m═══════════════════════════════════════\033[0m\n";
	
	Bibliotheque bibliotheque;

	bibliotheque.ajouterFilms("films.bin");
	bibliotheque.ajouterLivres("livres.txt");



	Film* hobbitFilm = bibliotheque.trouverFilmSi([](Film* film) -> bool {return (film->getTitre().find("Le Hobbit") != std::string::npos); });

	Livre* hobbitLivre = bibliotheque.trouverLivreSi([](Livre* livre) -> bool {return (livre->getTitre().find("Hobbit") != std::string::npos); });

	auto theHobbit = make_unique<FilmLivre>(*hobbitLivre,*hobbitFilm);

	bibliotheque.ajouter(move(theHobbit));

	cout << bibliotheque << endl;

	bibliotheque.trouverFilmSi([](Film* film) -> bool {return (film->getTitre()== "Not there"); });

	bibliotheque.trouverLivreSi([](Livre* livre) -> bool {return (livre->getTitre() == "Not there"); });

}	

