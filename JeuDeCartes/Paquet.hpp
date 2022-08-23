
#ifndef PAQUET_HPP
#define PAQUET_HPP
#include "CarteL.hpp" //Pour pouvoir acceder � la classe CarteL dans Paquet
#include "Demo.hpp"

class Paquet { //La classe paquet contient l'adresse du d�but du paquet

protected:
	CarteL* premiereCarte; //La classe paquet contient l'adresse du d�but du paquet
	int nombreCartes;
	CarteL* addCarte(CarteL* carteOrigine, CarteL* nouvelleCarte);// Ajout d'une carte link�e � la carte origine
	CarteL* getDerniereCarte(CarteL* carte);
	CarteL* getCarteALIndexRelatif(CarteL* carte, int index);
	CarteL* getCarteSansCarteLinkee(CarteL* carte);
	CarteL* pickCarte(int index);
	void bougerCarte(int index1, int index2);
	Paquet(CarteL* premiereCarte);
public:
	Paquet(); //constructeur par d�faut
	~Paquet(); // destructeur 
	CarteL* getCarte(); 	// Permet de r�cup�rer la valeur de carte
	int getNombreCartes();
	void setCarte(CarteL *carte); // Permet d'�craser la valeur de carte
	CarteL* addCarteALaFin(CarteL* nouvelleCarte);
	void addCarteALIndex(CarteL* carte, int index);
	void melangerPaquet(int finesse);
	CarteL* getCarteALIndex(int index);
	CarteL* pickCarteALIndex(int index); //�a la retire du paquet en m�me temps que �a la renvoie
	CarteL* getDerniereCarte();
};

class VuePaquet {
	Paquet* paquet;
protected:
	CarteL* showToutesLesCartes(CarteL* paquet);
public:
	VuePaquet()=delete;
	VuePaquet(Paquet* paquet);
	~VuePaquet();
	void showPremiereCarte();
	void showGetDerniereCarte();
	void showNombreCartes();
	void showPaquet();
	void showCarteALIndex(int index);
};

class DemoPaquet:Demo {
	static void demoPaquetAddCarteALaFin();
	static void demoPaquetPickCarteALIndex();
	static void demoPaquetAddCarteALIndex();
	static void demoPaquetMelangerPaquet();
public:
	static void lancer();
};

#endif