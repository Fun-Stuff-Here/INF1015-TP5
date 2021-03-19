/*
* Définition de la Classe Bibliotheque, TD4-INF1015
*\file		Acteur.hpp
*\author	Elizabeth Michaud 2073093, Nicolas Dépelteau 2083544
*\date		21 mars 2021
* Créé le	26 février 2021
*/
#pragma once
#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp" // Nos fonctions pour le rapport de fuites de mémoire.
#include "debogage_memoire.hpp"   // Ajout des numéros de ligne des "new" dans le rapport de fuites.
#include "gsl/span"
#include "cppitertools/range.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>
#include <memory>
#include <functional>
#include <iterator>
#include <iomanip>

#include "Acteur.hpp"
#include "Item.hpp"
#include "Film.hpp"
#include "Livre.hpp"
#include "FilmLivre.hpp"

typedef uint8_t UInt8;
typedef uint16_t UInt16;

class Bibliotheque 
{
public:
	Bibliotheque(const Bibliotheque&) = delete;
	Bibliotheque()=default;
	~Bibliotheque()=default;
	void ajouterFilms(const std::string& nomFichier);
	void ajouterLivres(const std::string& nomFichier);
	std::shared_ptr<Acteur> trouverActeur(const std::string& nom) const;
	void enlever(std::unique_ptr<Item>& item);
	void ajouter(std::unique_ptr<Item>&& item);
	Film* trouverFilmSi(const std::function<bool(Film*)>& critere) const;
	Livre* trouverLivreSi(const std::function<bool(Livre*)>& critere) const;
	friend std::ostream& operator<< (std::ostream& ostream, const Bibliotheque& bibliotheque);

private:
	
	std::vector<std::unique_ptr<Item>> items_;

private:

	std::shared_ptr<Acteur>lireActeur(std::istream& fichier);
	std::unique_ptr<Film> lireFilm(std::istream& fichier);
	static UInt8 lireUint8(std::istream& fichier);
	static UInt16 lireUint16(std::istream& fichier);
	static std::string lireString(std::istream& fichier);
	
};

std::ostream& operator<< (std::ostream& ostream, const Bibliotheque& bibliotheque);




#endif 


