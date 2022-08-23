
#include "Carte.hpp"
#include "Enum.hpp"
using namespace std;


Carte::Carte() : Carte(CouleurEnum::Pique, ValeurEnum::As) {} 
// Le constructeur par défaut appelle le constructeur par valeurs juste en dessous avec les valeurs en argument.

Carte::Carte(Carte* carte) : Carte(carte->couleur, carte->valeur){}
  
Carte::Carte(CouleurEnum Couleur, ValeurEnum Valeur) {
	this->couleur = Couleur;//On aurait aussi pu écrire this->Couleur = 0 (car Pique est le 1er de l'énum)
	this->valeur = Valeur;
};


CouleurEnum Carte::getCouleur() {
	return this->couleur;
}
void Carte::setCouleur(CouleurEnum couleur) {
	this->couleur = couleur;
}
ValeurEnum Carte::getValeur() {
	return this->valeur;
}
void Carte::setValeur(ValeurEnum valeur) {
	this->valeur = valeur;
};