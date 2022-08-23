#include "Paquet.hpp"
#include <iostream>
#include "Utils.hpp"
using namespace std;

Paquet::~Paquet() //Destructeur
{
	delete premiereCarte;
}
Paquet::Paquet(CarteL* premiereCarte) {
	this->premiereCarte = premiereCarte;
}
Paquet::Paquet() {
	//remplir de 52 cartes linkées allouées de manière dynamique sur le tas (new)
	int i;
	int j;
	CarteL* temp = nullptr; //variable temporaire pour stocker la carte suivante à utiliser
	for (i = 0; i < COULEUR_ENUM_LONGUEUR; i++) //Boucle pour naviguer dans les enums
	{
		for (j = 0; j < VALEUR_ENUM_LONGUEUR; j++)
		{
			Carte* carte = new Carte(CouleurEnum(i), ValeurEnum(j)); // création d'une nouvelle carte avec couleur et valeur issues des valeurs itératives des boucles
			CarteL* carteLSuivante = new CarteL(carte); // création de la carte suivante

			if (temp == nullptr) {
				temp = premiereCarte = carteLSuivante; // init de la première carte
				// on met aussi dans temp pour l'utiliser la l'itération suivante pour afin de lui ajouter sa carte linkée
			}
			else { //à partir du deuxième passage, on ne vient plus qu'ici
				temp = addCarte(temp, carteLSuivante);
				//addCarte prend deux cartes en argument, la première est celle dans laquelle on va link la deuxième
				//addCarte renvoie la carte linkée suivante
				//On la stocke dans temp afin de l'utiliser aux itérations suivantes
			}
		}
	}
	//(this->premiereCarte->GetCarteLinkee()) ça c'est la 2e carte du paquet
	//(this->premiereCarte->GetCarteLinkee())->GetCarteLinkee() ça c'est la 3e carte du paquet
};

//Permet de récupérer la valeur de carte
CarteL* Paquet::getCarte() {
	return this->premiereCarte;
}

int Paquet::getNombreCartes() {
	return this->nombreCartes;
}

// Set permet d'écraser la valeur de carte
void Paquet::setCarte(CarteL* carte) {
	this->premiereCarte = carte;
}

// On ajoute une carte linkée à la carte origine
CarteL* Paquet::addCarte(CarteL* carteOrigine, CarteL* nouvelleCarte) {
	carteOrigine->setCarteLinkee(nouvelleCarte);
	this->nombreCartes++;
	return(nouvelleCarte); //Retourne la carte ajoutée
}

// On ajoute une carte à la fin
CarteL* Paquet::addCarteALaFin(CarteL* nouvelleCarte) {
	CarteL* derniereCarte = getDerniereCarte();
	return addCarte(derniereCarte, nouvelleCarte);
}
CarteL* Paquet::getCarteALIndexRelatif(CarteL* carte, int index) { //relatif car on part d'une carte donnée dans un paquet, et on va x position plus loin
	try {

		if (carte->isLinkee() && (index - 1) > 1) {
			//index est un décompte et permet de savoir où s'arrêter 
			//(ex : on lance un dé, resultat=5, on peut avancer de 5 case.
			//si j'avance d'une case je peux encore avancer de 4 etc jusqu'à 0) 
			return getCarteALIndexRelatif(carte->getCarteLinkee(), --index); // --index?
		}
		return carte;
	}
	catch (const invalid_argument& e) {
		cout << endl << "getCarteALIndexRelatif " << endl;
		cout << endl << e.what();
	}
}

CarteL* Paquet::getCarteALIndex(int index) {
	return getCarteALIndexRelatif(premiereCarte, index);
}

CarteL* Paquet::pickCarteALIndex(int index)
{
	try {
		CarteL* carteRecherchee;
		if (index == 0) { //Pour la 1ere carte
			carteRecherchee = premiereCarte; //la carte recherchée est la 1ere carte du paquet
			premiereCarte = carteRecherchee->getCarteLinkee(); //puisqu'on l'enlève, c'est la 2eme qui devient la 1ere
		}
		else carteRecherchee = pickCarte(index); //pour toutes les autres cartes et la dernière
		carteRecherchee = getCarteSansCarteLinkee(carteRecherchee); //clear la carte linkée de la carte 5 pour pas faire des paquets de carte tentaculaires
		nombreCartes--;	//modifier le nombre de cartes
		return carteRecherchee;
	}
	catch (const invalid_argument& e) {
		cout << endl << "pickCarteALIndex " << endl;
		cout << index << " " << nombreCartes;
		cout << endl << e.what();
	}
}

CarteL* Paquet::getCarteSansCarteLinkee(CarteL* carte)
{
	carte->effacerCarteLinkee();
	return carte;
}

CarteL* Paquet::pickCarte(int index)
{
	try {
		//Si on veut retirer la carte "5", il faut aller sur la carte "4" et retirer sa carte linkée (qui est la carte "5")
		CarteL* carteRecherchee, * carteSuivante, * cartePrecedente;
		cartePrecedente = getCarteALIndex(index - 1); //carte précédent celle qu'on recherche
		carteRecherchee = cartePrecedente->getCarteLinkee();
		//Mettre la carte "6" en tant que carte linkée de la carte "4"
		if (index == nombreCartes-1) { //Pour la dernière carte (pas de carte suivante)
			cartePrecedente->effacerCarteLinkee(); //on enlève la carte linkee
		}
		else { //Pour toutes les autres cartes
			carteSuivante = carteRecherchee->getCarteLinkee();
			cartePrecedente->setCarteLinkee(carteSuivante);
		}
		return carteRecherchee;
	}
	catch (const invalid_argument& e) {
		cout << endl << "pickCarte " << endl;
		cout << index << " " << nombreCartes;
		cout << endl << e.what();
	}
}

void Paquet::addCarteALIndex(CarteL* carte, int index) { 
	try {
		if (index == 0) { //Pour la 1ere carte
			CarteL* carteLinkee = premiereCarte;
			premiereCarte = carte;
			addCarte(premiereCarte, carteLinkee);
			//premiereCarte->setCarteLinkee(carteLinkee);
		}
		else if (index == nombreCartes - 1) {
			CarteL* derniereCarte = getCarteALIndex(index);
			addCarte(derniereCarte, carte);
			//derniereCarte->setCarteLinkee(carte);
		}
		else {
			CarteL* cartePrecedente = getCarteALIndex(index - 1);
			CarteL* carteSuivante = cartePrecedente->getCarteLinkee();
			//cartePrecedente->setCarteLinkee(carte);
			addCarte(cartePrecedente, carte);
			carte->setCarteLinkee(carteSuivante);
		}
		//nombreCartes++;
	}
	catch (const invalid_argument& e) {
		cout << endl << "addCarteALIndex " << endl;
		cout << index << " " << nombreCartes;
		cout << endl << e.what();
	}
}

void Paquet::bougerCarte(int index1, int index2) {
	CarteL* carte = pickCarteALIndex(index1);
	//addCarteALIndex(carte1, index2);
	addCarteALaFin(carte);
}

void Paquet::melangerPaquet(int finesse) {
	int i = 0;

	for (i = 0; i < finesse; i++) {
		int index1 = Utils::getRandomInt(nombreCartes - 1);
		int index2 = Utils::getRandomInt(nombreCartes - 1);
		bougerCarte(index1, index2);
	}
}

CarteL* Paquet::getDerniereCarte()
{
	return getDerniereCarte(premiereCarte);
}

CarteL* Paquet::getDerniereCarte(CarteL* carte) {
	try {
		if (carte->isLinkee()) { //si la carte que je renvoie a une carte linkee...
			return getDerniereCarte(carte->getCarteLinkee()); // ...alors elle se rappelle elle-même
		}
		return carte; //return la dernière carte du pacquet (celle pour laquelle il n'y a pas de carte linkée)
	}
	catch (const invalid_argument& e) {
		cout << endl << "getDerniereCarte " << endl;
		cout << endl << e.what();
	}
}

CarteL* VuePaquet::showToutesLesCartes(CarteL* carte) {
	try {
		VueCarteL* vue = new VueCarteL(carte); //vue pour la 1ere carte contenue dans le paquet
		cout << "\t\t";
		vue->showCarte();
		cout << endl;
		if (carte->isLinkee()) { //si la carte du paquet que je renvoie a une carte linkée
			return showToutesLesCartes(carte->getCarteLinkee());
		}
		return nullptr;
	}
	catch (const invalid_argument& e) {
		cout << endl << "showToutesLesCartes " << endl;
		cout << endl << e.what();
	}
}

VuePaquet::VuePaquet(Paquet* paquet)
{
	this->paquet = paquet;
}

VuePaquet::~VuePaquet() {
	delete paquet;
}

void VuePaquet::showPremiereCarte()
{
	VueCarteL* vue = new VueCarteL(paquet->getCarte()); //vue pour la 1ere carte contenue dans le paquet
	vue->showCarte();
}

void VuePaquet::showGetDerniereCarte()
{
	VueCarteL* vue = new VueCarteL(paquet->getDerniereCarte()); //vue pour la dernière carte contenue dans le paquet
	vue->showCarte();
}

void VuePaquet::showNombreCartes()
{
	cout << paquet->getNombreCartes();
}

void VuePaquet::showPaquet()
{
	showToutesLesCartes(paquet->getCarte());
}

void VuePaquet::showCarteALIndex(int index) {
	(new VueCarteL(paquet->getCarteALIndex(index)))->showCarte(); //voir une carte à un index spécifique
}

void DemoPaquet::demoPaquetAddCarteALaFin() {
	showSeparator();
	cout << "\t *** demoPaquetAddCarteALaFin *** ";
	showSeparator();
	Paquet* paquet = new Paquet();
	VuePaquet* vuePaquet = new VuePaquet(paquet);
	cout << "DemoPaquet : Add Carte a la fin" << endl << endl;
	cout << "\tshow paquet initial : " << endl << endl;
	vuePaquet->showPaquet();
	showSeparator();
	cout << "Derniere carte initiale : ";
	vuePaquet->showGetDerniereCarte();
	cout << endl << "Nombre cartes initial : ";
	vuePaquet->showNombreCartes();
	showSeparator();
	paquet->addCarteALaFin(new CarteL());
	cout << "\tshow paquet apres modification : " << endl;
	vuePaquet->showPaquet();
	showSeparator();
	cout << "Derniere carte apres modification : ";
	vuePaquet->showGetDerniereCarte();
	cout << endl << "Nombre cartes apres modification : ";
	vuePaquet->showNombreCartes();
	cout << endl;
}
void DemoPaquet::demoPaquetPickCarteALIndex() {
	showSeparator();
	cout << "\t *** demoPaquetPickCarteALIndex *** ";
	showSeparator();
	Paquet* paquet = new Paquet();
	VuePaquet* vuePaquet = new VuePaquet(paquet);
	cout << "show carte a l'index" << endl;
	vuePaquet->showCarteALIndex(4);
	cout << endl;
	cout << "pick carte a l'index 4" << endl;
	CarteL* carteEnleveeDuPaquet = paquet->pickCarteALIndex(4);
	VueCarteL* vue = new VueCarteL(carteEnleveeDuPaquet);
	cout << "La carte retiree est : " << endl;
	vue->showCarte();
	cout << "Nouvelle carte a l'index 4 : " << endl;
	vuePaquet->showCarteALIndex(4);
	cout << endl;
	vuePaquet->showPaquet();
	cout << endl;
}
void DemoPaquet::demoPaquetAddCarteALIndex() {
	showSeparator();
	cout << "\t *** demoPaquetAddCarteALIndex *** ";
	showSeparator();
	Paquet* paquet = new Paquet();
	VuePaquet* vuePaquet = new VuePaquet(paquet);
	CarteL* carteEnleveeDuPaquet = paquet->pickCarteALIndex(4);
	VueCarteL* vue = new VueCarteL(carteEnleveeDuPaquet);
	cout << "Ajout de la carte retiree juste avant a l'index 8 : " << endl;
	paquet->addCarteALIndex(carteEnleveeDuPaquet, 8);
	vuePaquet->showPaquet();
	cout << endl;
}
void DemoPaquet::demoPaquetMelangerPaquet() {
	showSeparator();
	cout << "\t *** demoPaquetMelangerPaquet *** ";
	showSeparator();
	Paquet* paquet = new Paquet();
	VuePaquet* vuePaquet = new VuePaquet(paquet);
	cout << "On melange le paquet" << endl;
	paquet->melangerPaquet(10000);
	vuePaquet->showPaquet();
	cout << endl;
}

void DemoPaquet::lancer() {
	demoPaquetAddCarteALaFin();
	demoPaquetPickCarteALIndex();
	demoPaquetAddCarteALIndex();
	demoPaquetMelangerPaquet();
}


