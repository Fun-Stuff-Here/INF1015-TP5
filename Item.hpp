/*
* D�finition de la Classe Item, TD4-INF1015
*\file		Item.hpp
*\author	Elizabeth Michaud 2073093, Nicolas D�pelteau 2083544
*\date		21 mars 2021
* Cr�� le	26 f�vrier 2021
*/
#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>


class Item
{
public:
	Item(const std::string& titre, int annee);
	friend std::ostream& operator<< (std::ostream& ostream, const Item& item);
	virtual ~Item() = default;
	std::string getTitre() const;
	int getAnnee() const;

protected:
	virtual void print(std::ostream& ostream) const;
	std::string titre_;
	int annee_;
};


std::ostream& operator<< (std::ostream& ostream,const Item& item);



#endif 
