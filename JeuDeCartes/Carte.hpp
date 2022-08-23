
#ifndef CARTE_HPP
#define CARTE_HPP
#include "Enum.hpp" //Pour acc�der aux enums

class Carte {

protected:
	CouleurEnum couleur;
	ValeurEnum valeur;
public:
	Carte(); // constructeur par d�faut
	Carte(CouleurEnum couleur, ValeurEnum valeur); //Constructeur par valeurs
	Carte(Carte* carte);//Constructeur par recopie
	CouleurEnum getCouleur(); //Permet de r�cup�rer la couleur d'une carte
	void setCouleur(CouleurEnum couleur); //Permet d'�craser la couleur d'une carte
	ValeurEnum getValeur(); // R�cup�rer la valeur
	void setValeur(ValeurEnum valeur); // Ecraser la valeur
};

#endif