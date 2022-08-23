#include "Pile.hpp"


Pile::Pile(CouleurEnum couleur, CarteL* premiereCarte) : couleur(couleur) , Paquet(premiereCarte)
{
}

CouleurEnum Pile::getCouleur()
{
	return this->couleur;
}

VuePile::VuePile(Pile* pile) : pile(pile), VuePaquet(pile)
{
	
}

VuePile::~VuePile() {
	delete pile;
}

void VuePile::showCouleur()
{
	cout << "Couleur de la pile : " << VueCarteL::convertCouleurEnum(pile->getCouleur());
}

void DemoPile::demoPile()
{
	showSeparator();
	cout << "\t *** demoPile *** ";
	showSeparator();
	Carte carteCustom = Carte(CouleurEnum::Coeur, ValeurEnum::Dame);
	CarteL* c = new CarteL(carteCustom);
	Pile pile = Pile(CouleurEnum::Coeur, c);
	pile.addCarteALaFin(new CarteL(Carte(CouleurEnum::Coeur, ValeurEnum::Roi)));

	VuePile* vp = new VuePile(&pile);
	cout << "\tAffichage d'une pile : " << endl;
	vp->showPaquet();

	cout << "\t";
	vp->showCouleur();
}

void DemoPile::lancer()
{
	demoPile();
}
