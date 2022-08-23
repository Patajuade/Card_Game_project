
#ifndef CARTE_HPP
#define CARTE_HPP
#include "Enum.hpp" //Pour accéder aux enums

class Carte {

protected:
	CouleurEnum couleur;
	ValeurEnum valeur;
public:
	Carte(); // constructeur par défaut
	Carte(CouleurEnum couleur, ValeurEnum valeur); //Constructeur par valeurs
	Carte(Carte* carte);//Constructeur par recopie
	CouleurEnum getCouleur(); //Permet de récupérer la couleur d'une carte
	void setCouleur(CouleurEnum couleur); //Permet d'écraser la couleur d'une carte
	ValeurEnum getValeur(); // Récupérer la valeur
	void setValeur(ValeurEnum valeur); // Ecraser la valeur
};

#endif