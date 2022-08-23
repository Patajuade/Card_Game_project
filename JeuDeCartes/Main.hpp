
#ifndef MAIN_HPP
#define MAIN_HPP
#include "Paquet.hpp"

class Main : public Paquet {
	int numJoueur;
	int cagnotte;
public:
	Main()=delete; //comme ça on a pas le droit d'utiliser le constructeur par défaut de Main
	Main(int numJoueur, CarteL* premiereCarte);
	int getNumJoueur();
	int getCagnotte();
	
};

class VueMain : public VuePaquet {
	Main* main;
public:
	VueMain() = delete;
	VueMain(Main* main);
	~VueMain();
	void showNumJoueur();
	void showCagnotte();
};

class DemoMain : Demo {
	static void demoMain();
public:
	static void lancer();
};


#endif