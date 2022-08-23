#include "CarteL.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

CarteL::CarteL(){}
CarteL::~CarteL() //Destructeur
{
	delete adresseCarteLinkee;
}

CarteL::CarteL(CarteL* AdresseCarteLinkee) {
	this->adresseCarteLinkee = AdresseCarteLinkee;
};

CarteL::CarteL(Carte carte) : Carte(&carte)
{

}

CarteL *CarteL::getCarteLinkee() {
	if (this->adresseCarteLinkee == nullptr) {
		throw invalid_argument("La carte n'a pas de carte linkée !");
	}
	return this->adresseCarteLinkee;
}

void CarteL::setCarteLinkee(CarteL *AdresseCarteLinkee) {
	this->adresseCarteLinkee = AdresseCarteLinkee;
}

bool CarteL::isLinkee()
{
	return this->adresseCarteLinkee != nullptr;
}

void CarteL::effacerCarteLinkee() {
	this->adresseCarteLinkee = nullptr;
}

string VueCarteL::convertValeurEnum(ValeurEnum valeur)
{
	switch (valeur) {
	case ValeurEnum::As:
		return "As";
	case ValeurEnum::Deux:
		return "Deux";
	case ValeurEnum::Trois:
		return "Trois";
	case ValeurEnum::Quatre:
		return "Quatre";
	case ValeurEnum::Cinq:
		return "Cinq";
	case ValeurEnum::Six:
		return "Six";
	case ValeurEnum::Sept:
		return "Sept";
	case ValeurEnum::Huit:
		return "Huit";
	case ValeurEnum::Neuf:
		return "Neuf";
	case ValeurEnum::Dix:
		return "Dix";
	case ValeurEnum::Valet:
		return "Valet";
	case ValeurEnum::Dame:
		return "Dame";
	case ValeurEnum::Roi:
		return "Roi";
	default:
		return "";
	}
}

string VueCarteL::convertCouleurEnum(CouleurEnum couleur)
{
	switch (couleur) {
	case CouleurEnum::Pique:
		return "Pique";
	case CouleurEnum::Coeur:
		return "Coeur";
	case CouleurEnum::Carreau:
		return "Carreau";
	case CouleurEnum::Trefle:
		return "Trefle";
	default:
		return "";
	}

}

VueCarteL::VueCarteL()
{
	this->carte = new CarteL();
}

VueCarteL::VueCarteL(CarteL* carte)
{
	this->carte = carte;
}

VueCarteL::~VueCarteL() {
	delete carte;
}

void VueCarteL::showCarteLinkee()
{
	try {
		cout << convertValeurEnum(this->carte->getCarteLinkee()->getValeur())
			<< " de " << convertCouleurEnum(this->carte->getCarteLinkee()->getCouleur());
	}
	catch (const invalid_argument& e) {
		cout << endl << "showCarteLinkee " << endl;
		cout << endl << e.what();
	}
}

void VueCarteL::showAdresseCarteLinkee()
{
	try {	
		cout << carte->getCarteLinkee();
	}
	catch (const invalid_argument& e) {
		cout << endl << "showAdresseCarteLinkee " << endl;
		cout << endl << e.what();
	}
}

void VueCarteL::showCarte()
{
	cout << convertValeurEnum(this->carte->getValeur()) 
		<<" de "<< convertCouleurEnum(this->carte->getCouleur());
}

void DemoCarteL::demoCarteLConstructeurParDefaut() {
	showSeparator();
	cout << "\t *** demoCarteLConstructeurParDefaut *** ";
	showSeparator();
	Carte carteDefaut = Carte();
	cout << "getCouleur : " << (int)carteDefaut.getCouleur() << endl;
	cout << "getValeur : " << (int)carteDefaut.getValeur() << endl;
}
void DemoCarteL::demoCarteLConstructeurParValeur() {
	showSeparator();
	cout << "\t *** demoCarteLConstructeurParValeur *** ";
	showSeparator();
	Carte carteCustom = Carte(CouleurEnum::Coeur, ValeurEnum::Dame);
	cout << "getCouleur : " << (int)carteCustom.getCouleur() << endl;
	cout << "getValeur : " << (int)carteCustom.getValeur() << endl;
}
void DemoCarteL::demoCarteLConstructeurParRecopie() {
	showSeparator();
	cout << "\t *** demoCarteLConstructeurParRecopie *** ";
	showSeparator();
	Carte carteCustom = Carte(CouleurEnum::Coeur, ValeurEnum::Dame);
	Carte carteRecopie = Carte(carteCustom);
	cout << "getCouleur : " << (int)carteRecopie.getCouleur() << endl;
	cout << "getValeur : " << (int)carteRecopie.getValeur() << endl;
}
void DemoCarteL::demoVueCarteL() {
	showSeparator();
	cout << "\t *** demoVueCarteL *** ";
	showSeparator();
	Carte carteCustom = Carte(CouleurEnum::Coeur, ValeurEnum::Dame);
	CarteL* test = new CarteL();
	test->setCarteLinkee(new CarteL(carteCustom));
	VueCarteL* vue = new VueCarteL(test);
	cout << "show carte : ";
	vue->showCarte();
	cout << endl << "show  adresse carte linkee : ";
	vue->showAdresseCarteLinkee();
	cout << endl << "show carte linkee : ";
	vue->showCarteLinkee();
	cout << endl;
}

void DemoCarteL::lancer() {
	demoCarteLConstructeurParDefaut();
	demoCarteLConstructeurParValeur();
	demoCarteLConstructeurParRecopie();
	demoVueCarteL();
}