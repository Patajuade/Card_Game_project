# Jeu de cartes

## Participants au projet

Canavaggio-Diana Manon LA209563

De Baere Iléana LA206784


## Important

> Une branche a été créée pour chaque étape.

- [PR étape 1](https://github.com/gosseyec/G2IleanaManon/pull/1), [Branche étape 1](https://github.com/gosseyec/G2IleanaManon/tree/etape1)

- [PR étape 2](https://github.com/gosseyec/G2IleanaManon/pull/2), [Branche étape 2](https://github.com/gosseyec/G2IleanaManon/tree/etape2)

- [PR étape 3](https://github.com/gosseyec/G2IleanaManon/pull/5), [Branche étape 3](https://github.com/gosseyec/G2IleanaManon/tree/etape3)

## Informations importantes sur le rendu final
Je n'ai pas eu le temps de finir le projet. J'ai cependant fini l'étape 3. Comme le jeu n'est pas fonctionnel (car c'est le but de l'étape 4), j'ai fait des classes de démo pour chaque classe dans lesquelles se trouvent des méthodes applicant chaque fonctionnalité et les montrant en fonctionnement (par exemple, dans la classe DemoPaquet, on trouvera une methode demoPaquetMelangerPaquet(), qui affichera dans la console un paquet mélangé).


## Avancement du projet

> Ci dessous les taches accomplies et à terminer. Les taches accomplies sont listées sous la balise `terminé`, tandis que les taches à accomplir sont sous la balise `à faire`.
Les taches en cours de réalisation se trouvent sous la balise `en cours`.

## Etape 1

> <i style="color:#4ad300">Terminé</i>

* Créez une première classe Carte qui mémorisera les informations d’une carte : sa couleur et sa valeur. Utilisez deux énumérations pour cela.
* Créez une seconde classe CarteL héritée de la première qui contiendra en plus l’adresse d’une autre carte qui lui est linkée.
* Définir les attributs en protected et décrire les méthodes de manipulation correspondantes en public.
* Ecrire le diagramme UML décrivant cela et m’appeler pour vérifier.
* Créez une troisième classe appelée Paquet qui représentera un paquet de cartes. Il contiendra l’adresse du début du paquet 
* Ce paquet sera rempli de cartes linkées (52) allouées de manière dynamique sur le tas (new).
* Décrire les méthodes permettant de faire cela. Ajouter au schéma UML et m’appeler.
* Réaliser le code avec un petit programme de test. 
* Commenter le code
* Commit après chaque modification, puis push.

## Etape 2

> <i style="color:#4ad300">Terminé</i>

* Se créer une bibliothèque d’outils (méthodes) permettant de manipuler un paquet de cartes.
* Pour cela se définir une convention de nommage des méthodes (Français, anglais, majuscule, minuscule,…).
* En plus des constructeurs/destructeurs, Il y aura au moins les méthodes suivantes : 
    -	Assesseurs pour les données membres
    -	Ajouter une carte à la fin
    -	Prendre une carte dans le paquet
    -	Effectuer un mélange aléatoire
* Commit et push

## Etape 3
> <i style="color:#4ad300">Terminé</i>

* Créer une classe Main qui va hériter de Paquet et qui contiendra en plus un numéro de joueur et une cagnotte (entier).
* Créer une classe Pile qui va hériter de Paquet et qui contiendra la couleur de la pile.
* Créer une classe Donne qui va gérer un tour de jeu. Elle contiendra entra 4 et 6 mains, 4 piles de couleurs différentes (pique, coeur, carreau, trèfle) et un pot (entier).

* Elle contiendra au moins les méthodes suivantes :
    - Répartir les cartes en quatre mains.
    - Créer les 4 piles.
    - Tester si une carte peut aller sur une pile.
    - Effectuer un mouvement d’une carte sur une pile.
* Démarrer un tour de jeu qui renvoie comme valeur 10%de la somme gagnée (par la banque)
* Mettre à jour UML et Readme
* Commit et push

## Etape 4

> <i style="color:red">A faire</i>

> <i style="color:yellow">En cours </i>

* Faire jouer les 4 joueurs les uns après les autres.
* Le tour de jeu se déroule comme suit :
    - Répartir les cartes entre les mains
    - Chaque joueur à son tour va tester ses cartes pour voir si une carte est jouable.
    - Si oui, il va la jouer.
    - Si aucune carte n’est jouable, il va augmenter le pot de 1 diminuer la cagnotte du joueur de 1.
    - Passer au joueur suivant jusqu’à ce qu’un joueur n’a plus de cartes.
    - Ajouter le pot à la cagnotte du joueur gagnant (-10%)
* Supprimer toutes les cartes restantes
* Si un joueur est ruiné, le jeu s’arrête de lui-même, on peut aussi arrêter entre chaque tour ou voir si la banque fait crédit.
* Faire un petit programme de test.
* Mettre à jour UML et Readme
* Commit et push

## Etape 5

* Adaptez pour 5 ou 6 joueurs.
* Mettre les paramètres (nombre de cartes, difficulté du mélange dans un fichier).
* Créez une DB avec des joueurs, l’évolution de leur cagnotte en fonction des parties.
* Leurs dépôts sur leur portefeuille.
* Mettre à jour UML et Readme
* Commit et push

## Etape 6
* Permettre aux joueurs de jouer réellement
* Permettre l'emploi de bots
* Mettre à jour UML et Readme
* Commit et push
