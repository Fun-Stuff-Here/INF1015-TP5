/*
* Programme qui lit un fichier de film et livres et les manipules, TD4-INF1015
*\file		TP5.cpp
*\author	Elizabeth Michaud 2073093, Nicolas Dépelteau 2083544
*\date		7 mars 2021
* Créé le	26 février 2021
*/

#define _CRT_SECURE_NO_WARNINGS // On permet d'utiliser les fonctions de copies de chaînes qui sont considérées non sécuritaires.
#include "Bibliotheque.hpp"
#include "cppitertools/imap.hpp"
#include <forward_list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;
using namespace gsl;
using namespace iter;

void afficherSection(std::string section)
{
	std::cout << "\n\033[35m═══════════════════════════════════════\033[0m\n" << std::endl;
	std::cout << section << std::endl;
	std::cout << "\n\033[35m═══════════════════════════════════════\033[0m\n" << std::endl;
}



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

	bibliotheque.trouverFilmSi([](Film* film) -> bool {return (film->getTitre()== "Not there"); });

	bibliotheque.trouverLivreSi([](Livre* livre) -> bool {return (livre->getTitre() == "Not there"); });

	std::cout << endl << endl;
	afficherSection("TD5");

	using ItemPtr = shared_ptr<Item>;

	std::vector<ItemPtr>& bibliothequeVecteur = bibliotheque.getItems();

	afficherSection("0");
	afficherListeItems<std::vector<ItemPtr>>(bibliothequeVecteur);

	afficherSection("1.1");

	std::forward_list<ItemPtr> bibliothequeForwardListe;

	auto it = bibliothequeForwardListe.before_begin();
	for (auto&& item:bibliothequeVecteur) //n fois 
	{
		bibliothequeForwardListe.insert_after(it,item); // O(1)
		++it;// O(1)
	}
	//O(n)

	afficherListeItems<std::forward_list<ItemPtr>>(bibliothequeForwardListe);

	afficherSection("1.2");

	std::forward_list<ItemPtr> biblithequeReversedForwardListe;

	for (auto&& item:bibliothequeForwardListe)//n fois
	{
		biblithequeReversedForwardListe.push_front(item);// O(1)
	}
	//O(n)

	afficherListeItems<std::forward_list<ItemPtr>>(biblithequeReversedForwardListe);


	afficherSection("1.3");

	std::forward_list<ItemPtr> bibliothequeForwardListeCopie;
	auto it2 = bibliothequeForwardListeCopie.before_begin();

	for (auto&& item:bibliothequeForwardListe)// n fois
	{
		bibliothequeForwardListeCopie.insert_after(it2, item); // O(1)
		++it2;// O(1)
	}// O(n)

	afficherListeItems<std::forward_list<ItemPtr>>(bibliothequeForwardListeCopie);


	afficherSection("1.4");
	std::size_t nItems = bibliothequeVecteur.size(); //O(1)
	std::vector<ItemPtr> bibliothequeVectorCopie(nItems);
	
	for (auto&& item : bibliothequeForwardListe)//n fois
	{
		bibliothequeVectorCopie[--nItems] = item;// O(1)
	}
	//O(n)


	afficherListeItems<std::vector<ItemPtr>>(bibliothequeVectorCopie);

	afficherSection("1.5");
	Film* film = dynamic_cast<Film*>(bibliothequeVecteur[0].get());
	auto acteurs = film->getActeurs();
	for (auto&& acteur: acteurs)
	{
		std::cout << *acteur << std::endl;
	}


	afficherSection("2.1");


	std::map<std::string, ItemPtr> bibliothequeMap;
	for (auto&& item :bibliothequeVecteur)
	{
		bibliothequeMap[item->getTitre()] = item;
	}

	for (auto&& [titre, item] : bibliothequeMap)
	{
		std::cout << item->getTitre() << std::endl;
	}

	afficherSection("2.2");

	std::unordered_map<std::string, ItemPtr> bibliothequeUnorderedMap;
	for (auto&& [titre, item] : bibliothequeMap)
	{
		bibliothequeUnorderedMap[titre] = item;
	}

	std::cout << *bibliothequeUnorderedMap["The Hobbit"] << std::endl; //O(1) average, O(n) worst case


	afficherSection("3.1");

	std::vector<ItemPtr> films;

	std::copy_if( bibliothequeForwardListe.begin(), bibliothequeForwardListe.end(),
		std::back_inserter(films),
		[](ItemPtr item) {return dynamic_cast<Film*>(item.get());} //warning a fix
	);

	afficherListeItems<std::vector<ItemPtr>>(films);


	afficherSection("3.2");

	int sumRecette = std::accumulate(films.begin(), films.end(),
		0,
		[](int sum,ItemPtr item)-> int{ return sum+dynamic_cast<Film*>(item.get())->getRecette(); });

	std::cout << sumRecette << std::endl;

}	

