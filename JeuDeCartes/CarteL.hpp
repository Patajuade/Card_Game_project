
#ifndef CARTEL_HPP
#define CARTEL_HPP
#include "Carte.hpp" //Pour pouvoir acceder à la classe Carte dans CarteL
#include "Demo.hpp"
#include <iostream>
using namespace std;


class CarteL:virtual public Carte {

protected:
	CarteL *adresseCarteLinkee; //adresse carte suivante
	
public:
	CarteL(); //constructeur par défaut
	~CarteL(); //destructeur
	CarteL(CarteL *adresseCarteLinkee); //constructeur par recopie
	CarteL(Carte carte); // constructeur par valeurs
	CarteL *getCarteLinkee();
	void setCarteLinkee(CarteL* adresseCarteLinkee);
	bool isLinkee();
	void effacerCarteLinkee();
};

class VueCarteL {
	CarteL* carte;

public:
	VueCarteL();
	~VueCarteL();
	VueCarteL(CarteL* carte);
	void showCarteLinkee();
	void showAdresseCarteLinkee();
	void showCarte();
	static string convertValeurEnum(ValeurEnum valeur); 
	static string convertCouleurEnum(CouleurEnum couleur); 
};

class DemoCarteL:Demo {
	static void demoCarteLConstructeurParDefaut();
	static void demoCarteLConstructeurParValeur();
	static void demoCarteLConstructeurParRecopie();
	static void demoVueCarteL();

public:
	static void lancer();
};

#endif