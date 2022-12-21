/*
Prototypes des Fonctions de Guillaume FROMENT

Les codes suivants sont pour l'instant des algorithmes qui nous permettent de décider du comportement du système
*/


//Score 

int initScore(int scores[]){
    //Prend les scores enregistrés et les mets à 0, afin de s'asssurer qu'ils soient vides en début de partie
    //les scores des 4 joueurs sont regroupés dans le tableau "scores"
    scores[0]=0;
    scores[1]=0;
    scores[2]=0;
    scores[3]=0;
    return scores;
}

int updateScore(int scores[], int idJoueur, int value){
    //IdJoueur est l'id utilisé pour désigner le joueur en jeu
    //value est la valeur positie ou négative à ajouter au score
    if (idJoueur>=1 && idJoueur<=4){
        scores[idJoueur-1]=scores[idJoueur-1]+value;
    }
    else {
        //peut être ajouter la gestion des erreurs
    }
    return scores;
}

int finalScore(int scores[]){
    int values[4];
    /*
    Récupérer les scores des chevalets de chaque joueur
    et les passer en négatif
    joker = -30 points
    Passer les résultats dans values
    Le joueur ayant fini à une valeur de 0
    */

    for (int i=0; i<4; i++){
        scores[i]=scores[i]+values;
    }

    return scores;
}

void afficheScore(int scores[]){
    //affiche les scores joueur par joueur
}

void sauvegardeScore(int scores){
    //sauvegarde les scores en fin de partie et les écrit dans le fichier
}

//Tours
int initTour(){
    //Remet à 0 l'ordre de jeu
    return 0;
}

int nextTurn(int ot, int nbj){
    //Permet le passage au tour de jeu suivant, nbj est le nombre de joueur participant à la partie
    ot = ot + 1;
    ot = ot%nbj;
    return ot;
}

int isMyTurn(int t, int idJoueur){
    //permet de vérifier si c'est le tour du joueur lorsqu'il tente une action
    //l'action ne sera validée que si la condition est vraie
    if (t == (idJoueur-1)){
        return 1;
    }
    else {
        return 0;
    }
}



//Pioche

int reserve [15] [4]; //permet de "stocker" les tuiles, numéro, puis couleur

typedef struct tuile{
    int valeur; //valeur numérique de la tuile, le 14 est le joker
    int couleur; //couleur de la tuile : 1 = rouge, 2 = noir, 3 = orange, 4 = bleu
} tuile;

typedef struct combinaison{
    tuile list [14]; //permet de stocker toutes les tuiles de la combinaison
    int isValid; //permet de stocker la validité de la combinaison, qui est nécessaire pour la poser sur le chevalet
} combinaison;

int pioche(int nb, int idJoueur){
    //permet de piocher des tuiles depuis la réserve, généralement soit 1 ou 14
    for (int i=1; i<nb; i++){
        int a = 1;
        while(a){
            int n = rand()%14+1; //permet d'obtenir un numéro de tuile
            int c = rand()%4+1; //permet d'obtenir une couleur de tuile
            if (reserve [n-1] [c-1] > 0){ //si la tuile est dans la réserve, pour éviter les duplicatas
                a=0;
                reserve [n-1] [c-1] = reserve [n-1] [c-1] -1; //on enlève la tuile de la réserve
            }
        }
        //mettre la tuile dans le chevalet du joueur
    }
}

void initReserve(){
    for (int n=1; n<14; n++){
        for (int c=1; c<5; c++){
            tuile nt; //génère la tuile
            nt.valeur = n;
            nt.couleur = c;
            reserve [n-1] [c-1] = 2; //indique que la tuile est dans la réserve en 2 exemplaires
        }
    }
    reserve [14-1] [1-1] = 1; //génère le joker rouge
    reserve [14-1] [2-1] = 1; //génère le joker noir
    reserve [14-1] [1-1] = 1; //génère le joker orange
    reserve [14-1] [2-1] = 1; //génère le de joker bleu
}

//IA
/* On considère que les ia testent les combinaisons possibles jusqua trouver la meilleur pour l'instant*/



//Chevalets

//Seul un joueur peut voir son propre chevalet
typedef struct chevalet{
    int idJoueur; //id du joueur qui possède le chevalet
    tuile list [30]; //contient les tuiles du chevalet
} chevalet;



//Plateau de Jeu

//tous les joueurs peuvent voir le plateau de jeu
typedef struct plateau{
    combinaison list [40]; // permet de stocker les combinaisons à afficher
} plateau;