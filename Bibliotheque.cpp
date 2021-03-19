/*
* Implémentation de la Classe Bibliotheque, TD4-INF1015
*\file		Bibliotheque.cpp
*\author	Elizabeth Michaud 2073093, Nicolas Dépelteau 2083544
*\date		7 mars 2021
* Créé le	26 février 2021
*/
#include "Bibliotheque.hpp"

using namespace std;
using namespace gsl;
using namespace iter;


UInt8 Bibliotheque::lireUint8(istream& fichier)
{
	UInt8 valeur = 0;
	fichier.read((char*)&valeur, sizeof(valeur));
	return valeur;
}

UInt16 Bibliotheque::lireUint16(std::istream& fichier)
{
	UInt16 valeur = 0;
	fichier.read((char*)&valeur, sizeof(valeur));
	return valeur;
}

string Bibliotheque::lireString(std::istream& fichier)
{
	std::string texte;
	texte.resize(lireUint16(fichier));
	fichier.read((char*)&texte[0], std::streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}


void Bibliotheque::ajouterFilms(const std::string& nomFichier)
{

	ifstream fichier(nomFichier, ios::binary);
	fichier.exceptions(ios::failbit);

	int nFilms = lireUint16(fichier);

	//Le warning dit que i n'est pas reference sooooooooo on lui fait faire une comparaison 
	for (int i : iter::range(nFilms))
	{
		i = 0;
		unique_ptr<Film> film = move(lireFilm(fichier));
		items_.push_back(move(film));
	}
}

std::unique_ptr<Film> Bibliotheque::lireFilm(istream& fichier)
{
	string titre = lireString(fichier);
	string realisateur = lireString(fichier);
	int anneeSortie = lireUint16(fichier);
	int recette = lireUint16(fichier);
	int nActeurs = lireUint8(fichier);
	//Allocation de la liste d'acteur
	std::vector<std::shared_ptr<Acteur>> acteurs;

	//Le warning dit que i n'est pas reference sooooooooo on lui fait faire une comparaison 
	for (int i : iter::range(nActeurs))
	{
		i = 0;
		acteurs.push_back(lireActeur(fichier));
	}
	return make_unique<Film>(titre, anneeSortie, realisateur, recette,
		(std::vector<std::shared_ptr<Acteur>>&&)acteurs);

}

std::shared_ptr<Acteur> Bibliotheque::lireActeur(std::istream& fichier)
{
	string nom = lireString(fichier);
	int anneeNaissance = lireUint16(fichier);
	char sexe = lireUint8(fichier);

	shared_ptr<Acteur> acteur = make_shared<Acteur>(nom, anneeNaissance, sexe);

	shared_ptr<Acteur> acteurExistant = trouverActeur(nom);
	//check si existant
	if (acteurExistant)
	{
		acteur = nullptr;
		return acteurExistant;
	}
	else
	{	//Debug line
		cout << acteur->getNom() << endl;
		return  acteur;
	}
}




void Bibliotheque::ajouterLivres(const std::string& nomFichier)
{
	ifstream fichier(nomFichier);


	string titre = "";
	int annee = 0;
	string auteur = "";
	int nMillionsCopiesVendues = 0;
	int nPage = 0;

	while (!ws(fichier).eof())
	{
		fichier >> quoted(titre);
		fichier >> annee;
		fichier >> quoted(auteur);
		fichier >> nMillionsCopiesVendues;
		fichier >> nPage;
		cout << titre << endl;

		items_.emplace_back(make_unique<Livre>(auteur, nMillionsCopiesVendues, nPage, titre, annee));
	}

}


shared_ptr<Acteur> Bibliotheque::trouverActeur(const string& nom) const
{
	shared_ptr<Acteur> acteur = nullptr;

	for (auto&& item : items_)
	{
		if (auto film = dynamic_cast<Film*>(item.get()))
		{
			acteur = film->trouverActeur(nom);
			if (acteur)
				break;
		}
	}
	return acteur;
}


void Bibliotheque::enlever(unique_ptr<Item>& item)
{
	items_.erase(find(items_.begin(), items_.end(), item));
}
void Bibliotheque::ajouter(unique_ptr<Item>&& item)
{
	items_.push_back(move(item));
}


Film* Bibliotheque::trouverFilmSi(const std::function<bool(Film*)>& critere) const
{
	for (auto&& item : items_)
	{
		if (dynamic_cast<Film*>(item.get()))
		{
			if (critere(dynamic_cast<Film*>(item.get())))
				return dynamic_cast<Film*>(item.get());
		}
	}
	return nullptr;
}

Livre* Bibliotheque::trouverLivreSi(const std::function<bool(Livre*)>& critere) const
{
	for (auto&& item : items_)
	{
		if (dynamic_cast<Livre*>(item.get()))
		{
			if (critere(dynamic_cast<Livre*>(item.get())))
				return dynamic_cast<Livre*>(item.get());
		}
	}
	return nullptr;
}



std::ostream& operator<< (std::ostream& ostream, const Bibliotheque& bibliotheque)
{
	for (auto&& item : bibliotheque.items_)
	{
		ostream << "\n\033[35m═══════════════════════════════════════\033[0m\n" << std::endl;
		ostream << *item << std::endl;
	}
	return ostream;
}


