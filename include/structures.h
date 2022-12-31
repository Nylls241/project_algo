#ifndef STRUCTS_H
#define  STRUCTS_H

//Structures rédigées par Nylls Gersan BOUTOTO :
typedef struct {
	SDL_Renderer *rendu;
	SDL_Window *fenetre;
} app;

//Structures rédigées par Guillaume FROMENT :
typedef struct tuile{
    int valeur; //valeur numérique de la tuile, le 14 est le joker
    int couleur; //couleur de la tuile : 1 = rouge, 2 = noir, 3 = orange, 4 = bleu
} tuile;

typedef struct combinaison{
    tuile list [14]; //permet de stocker toutes les tuiles de la combinaison
    int isValid; //permet de stocker la validité de la combinaison, qui est nécessaire pour la poser sur le chevalet
} combinaison;

//Seul un joueur peut voir son propre chevalet
typedef struct chevalet{
    int idJoueur; //id du joueur qui possède le chevalet
    tuile list [30]; //contient les tuiles du chevalet
} chevalet;

//tous les joueurs peuvent voir le plateau de jeu
typedef struct plateau{
    combinaison list [40]; // permet de stocker les combinaisons à afficher
} plateau;






#endif



