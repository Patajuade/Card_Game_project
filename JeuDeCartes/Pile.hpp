
#ifndef PILE_HPP
#define PILE_HPP
#include "Paquet.hpp"

class Pile : virtual public Paquet {
	//doit contenir la couleur de la pile
protected:
	CouleurEnum couleur;
public:
	Pile() = default;
	Pile(CouleurEnum couleur, CarteL* premiereCarte);
	CouleurEnum getCouleur();
};

class VuePile :  public VuePaquet {
	Pile* pile;
public:
	VuePile() = delete;
	VuePile(Pile* pile);
	~VuePile();
	void showCouleur();
};

class DemoPile : Demo {
	static void demoPile();
public:
	static void lancer();
};

#endif