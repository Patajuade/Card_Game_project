
#include <iostream>
#include"CarteL.hpp"
#include"Paquet.hpp"
#include "Main.hpp"
#include "Pile.hpp"
#include "Donne.hpp"
using namespace std;


void initialisationVariablesProgramme() {
	srand(time(NULL)); //Pour changer la seed du random en fonction du temps
}

int main()
{
	initialisationVariablesProgramme();
	DemoCarteL::lancer();
	DemoPaquet::lancer();
	DemoMain::lancer();
	DemoPile::lancer();
	DemoDonne::lancer();
	cin.get();
}
