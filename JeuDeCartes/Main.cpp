#include "Main.hpp"
#include "Donne.hpp"

Main::Main(int numJoueur, CarteL * premiereCarte) :numJoueur(numJoueur), cagnotte(0), Paquet(premiereCarte)
{
}

int Main::getNumJoueur()
{
	return this->numJoueur;
}

int Main::getCagnotte()
{
	return this->cagnotte;
}

VueMain::VueMain(Main* main) : main(main), VuePaquet(main)
{
}

VueMain::~VueMain() {
	delete main;
}

void VueMain::showNumJoueur()
{
	cout <<"NumJoueur : "<< main->getNumJoueur();
}

void VueMain::showCagnotte()
{
	cout << "Cagnotte : " << main->getCagnotte();
}

void DemoMain::demoMain()
{
	showSeparator();
	cout << "\t *** demoMain *** ";
	showSeparator();
	Carte carteCustom = Carte(CouleurEnum::Coeur, ValeurEnum::Dame);
	CarteL* c = new CarteL(carteCustom);
	Main m = Main(4, c);
	m.addCarteALaFin(new CarteL());

	VueMain* vueMain = new VueMain(&m);
	cout << "\tAffichage de la main d'un joueur : " << endl;
	vueMain->showPaquet();

	cout << "\t";
	vueMain->showNumJoueur();
	cout << endl<<"\t";
	vueMain->showCagnotte();
}

void DemoMain::lancer()
{
	demoMain();
}
