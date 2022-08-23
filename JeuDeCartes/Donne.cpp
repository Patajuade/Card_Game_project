#include "Donne.hpp"
#include <stdexcept>
#include <iterator>
#include <list>
using namespace std;

Donne::Donne(int nombreJoueur)
{
	if (nombreJoueur < 4 || nombreJoueur >= 6) {
		throw invalid_argument("Le nombre de joueur doit etre de 4 minimum et 6 maximum !");
	}

	mains = new list<Main*>();
	pique = new Pile(CouleurEnum::Pique,new CarteL(new Carte(CouleurEnum::Pique,ValeurEnum::As)));
	carreau = new Pile(CouleurEnum::Carreau, new CarteL(new Carte(CouleurEnum::Carreau, ValeurEnum::As)));
	coeur = new Pile(CouleurEnum::Coeur, new CarteL(new Carte(CouleurEnum::Coeur, ValeurEnum::As)));
	trefle = new Pile(CouleurEnum::Trefle, new CarteL(new Carte(CouleurEnum::Trefle, ValeurEnum::As)));
	pot = 0;
	int i, j;
	Paquet* paquet = new Paquet();

	for (i = 0; i < nombreJoueur; i++) { //On donne une carte à chaque joueur pour creer sa main
		CarteL* carte = paquet->pickCarteALIndex(0); //on pop(retire) la première carte du paquet
		mains->push_back(new Main(i, carte)); //ajouter un joueur
	}
	//La distribution des cartes à chaque joueur s'effectue sous forme de tour de table 
	//(Le premier joueur se voit donner la première carte du paquet, puis le 2eme joueur la deuxième carte, et ainsi de suite.)
	bool ilResteDesCartes = true;
	while (ilResteDesCartes) { //On distribue le reste des cartes du paquet aux joueurs
		for (i = 0; i < getNombreDeJoueurs(); i++) {
			if (paquet->getNombreCartes() > 0) {
				getMain(i)->addCarteALaFin(paquet->pickCarteALIndex(0));
			}
			else {
				ilResteDesCartes = false;
			}
		}
	}
}

Donne::~Donne() {
	delete mains;
	delete pique;
	delete carreau;
	delete coeur;
	delete trefle;
}

int Donne::getPot()
{
	return this->pot;
}

int Donne::getNombreDeJoueurs()
{
	return this->mains->size();
}

bool Donne::testCartePile(CarteL* carte, Pile* pile)
{
	return pile->getCouleur() == carte->getCouleur();
}

void Donne::bougerCarteSurPile(CarteL* carte) {
	if (testCartePile(carte, pique)) {
		pique->addCarteALaFin(carte);
	}
	else if (testCartePile(carte, carreau)) {
		carreau->addCarteALaFin(carte);
	}
	else if (testCartePile(carte, coeur)) {
		coeur->addCarteALaFin(carte);
	}
	else if (testCartePile(carte, trefle)) {
		trefle->addCarteALaFin(carte);
	}

}

Main* Donne::getMain(int index) {
	auto main_front = mains->begin();
	advance(main_front, index);
	return *main_front;
}

//list<Main*> *Donne::getMains()
//{
//	return this->mains;
//}

Pile* Donne::getPilePique()
{
	return this->pique;
}

Pile* Donne::getPileCarreau()
{
	return this->carreau;
}

Pile* Donne::getPileCoeur()
{
	return this->coeur;
}

Pile* Donne::getPileTrefle()
{
	return this->trefle;
}



VueDonne::VueDonne(Donne* donne) : donne(donne)
{
}

VueDonne::~VueDonne() {
	delete donne;
}

void VueDonne::showPiles()
{
	VuePaquet* vp;
	cout << endl << "Pile Pique : " << endl;
	vp = new VuePaquet(donne->getPilePique());
	vp->showPaquet();
	cout << endl << "Pile Carreau : " << endl;
	vp = new VuePaquet(donne->getPileCarreau());
	vp->showPaquet();
	cout << endl << "Pile Coeur : " << endl;
	vp = new VuePaquet(donne->getPileCoeur());
	vp->showPaquet();
	cout << endl << "Pile Trefle : " << endl;
	vp = new VuePaquet(donne->getPileTrefle());
	vp->showPaquet();

}

void VueDonne::showMains()
{
	int i = 0;
	VueMain* vueMain;
	for (i; i < donne->getNombreDeJoueurs(); i++) {
		vueMain = new VueMain(donne->getMain(i));
		cout << endl << "Main du joueur : " << i << endl;
		vueMain->showPaquet();
	}
}

void VueDonne::showPot()
{
	cout << "Le pot est de : " << donne->getPot();
}

void DemoDonne::demoDonne() {
	showSeparator();
	cout << "\t *** demoDonne *** ";
	showSeparator();
	try {
		Donne* donne = new Donne(4);
		VueDonne* vueDonne = new VueDonne(donne);
		vueDonne->showMains();
		//cout << "Ce message sera affiche"; //ce message est affiché car il n'y a pas d'erreur qui est throw dans le constructeur de Donne
	}
	catch (const invalid_argument& e) {
		cout << endl << e.what();
	}
}

void DemoDonne::demoNombreJoueursIncorrect() {
	try {
		Donne* donne = new Donne(0);
		VueDonne* vueDonne = new VueDonne(donne);
		cout << "Ne sera jamais affiche"; //ce message n'est pas affiché car il y a une erreur qui est throw dans le constructeur de Donne
	}
	catch (const invalid_argument& e) {
		cout << endl << e.what();
	}
}

void DemoDonne::demoMouvementPile()
{
	showSeparator();
	cout << "\t *** demoMouvementPile *** ";
	showSeparator();
	try {
		Donne* donne = new Donne(4);
		VueDonne* vueDonne = new VueDonne(donne);
		cout << endl << "Avant" << endl;
		vueDonne->showMains();
		vueDonne->showPiles();
		showSeparator();
		donne->bougerCarteSurPile(donne->getMain(0)->pickCarteALIndex(1));
		donne->bougerCarteSurPile(donne->getMain(0)->pickCarteALIndex(1));
		donne->bougerCarteSurPile(donne->getMain(0)->pickCarteALIndex(1));
		donne->bougerCarteSurPile(donne->getMain(0)->pickCarteALIndex(1));
		donne->bougerCarteSurPile(donne->getMain(0)->pickCarteALIndex(1));
		donne->bougerCarteSurPile(donne->getMain(0)->pickCarteALIndex(1));
		donne->bougerCarteSurPile(donne->getMain(0)->pickCarteALIndex(1));
		donne->bougerCarteSurPile(donne->getMain(0)->pickCarteALIndex(1));
		donne->bougerCarteSurPile(donne->getMain(0)->pickCarteALIndex(1));
		cout << endl << "Apres" << endl;
		vueDonne->showMains();
		vueDonne->showPiles();
		//cout << "Ce message sera affiche"; //ce message est affiché car il n'y a pas d'erreur qui est throw dans le constructeur de Donne
	}
	catch (const invalid_argument& e) {
		cout << endl << e.what();
	}
}

void DemoDonne::lancer() {
	demoDonne();
	demoMouvementPile();
	//demoNombreJoueursIncorrect();
}