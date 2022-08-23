
#ifndef DONNE_HPP
#define DONNE_HPP
#include <list>
#include <iostream>
#include "Paquet.hpp"
#include "Main.hpp"
#include "Pile.hpp"

class Donne {
	list<Main*>* mains;
	Pile* pique;
	Pile* carreau;
	Pile* coeur;
	Pile* trefle;
	int pot;

public:
	Donne(int nombreJoueur);
	~Donne();
	int getPot();
	//list<Main*>* getMains();
	Main* getMain(int index);
	Pile* getPilePique();
	Pile* getPileCarreau();
	Pile* getPileCoeur();
	Pile* getPileTrefle();
	int getNombreDeJoueurs();
	bool testCartePile(CarteL* carte, Pile* pile);
	void bougerCarteSurPile(CarteL* carte); 
};

class VueDonne {
	Donne* donne;
public:
	VueDonne() = delete;
	VueDonne(Donne* donne);
	~VueDonne();
	void showPiles();
	void showMains();
	void showPot();
};

class DemoDonne : Demo {
	static void demoDonne();
	static void demoNombreJoueursIncorrect();
	static void demoMouvementPile();
public:
	static void lancer();
};

#endif