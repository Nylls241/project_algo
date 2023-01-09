/*
Prototypes des Fonctions de Guillaume FROMENT

Les codes suivants sont pour l'instant des algorithmes qui nous permettent de décider du comportement du système
*/

#include "../include/include.h"


//Structures
int reserve [15] [4]; //permet de "stocker" les tuiles, numéro, puis couleur

//Score 

int* initScore(int scores[]){
    //Prend les scores enregistrés et les mets à 0, afin de s'asssurer qu'ils soient vides en début de partie
    //les scores des 4 joueurs sont regroupés dans le tableau "scores"
    scores[0]=0;
    scores[1]=0;
    scores[2]=0;
    scores[3]=0;
    return scores;
}

//Normalement inutile car il n'y a pas de calcul intermédiaire des scores
int* updateScore(int scores[], int idJoueur, int value){
    //IdJoueur est l'id utilisé pour désigner le joueur en jeu
    //value est la valeur positive ou négative à ajouter au score
    if (idJoueur>=1 && idJoueur<=4){
        scores[idJoueur-1]=scores[idJoueur-1]+value;
    }
    else {
        //peut être ajouter la gestion des erreurs
    }
    return scores;
}

int* finalScore(int scores[], chevalet chevalets[]){
    int values[4]; //chacune des cases est associée à un chevalet, et par extension son joueur
    values[0]=0;
    values[1]=0;
    values[2]=0;
    values[3]=0;
    /*
    Récupérer les scores des chevalets de chaque joueur
    et les passer en négatif
    joker = -30 points
    Passer les résultats dans values
    Le joueur ayant fini à la somme des valeurs absolue des scores des autres joueurs
    */
    for (int y=0; y<4; y++){
        for (int i; i<30; i++){
            if(chevalets[y].list[i].valeur != 14){ //on vérifie si la tuile est un joker
                values[y]=values[y]+chevalets[y].list[i].valeur; //on récupère la valeur de la tuile et on l'ajoute à values[y]
            }
            else{
                values[y]=values[y]+30; //Si la tuile est un joker elle vaut 30 points
            }
        }
    }
    for (int j=0; j<4; j++){
        if(values[j]!=0){
            scores[j]=scores[j]-values[j]; //les perdants ont un score négatif
        }
        else{
            scores[j]=scores[j]+values[0]+values[1]+values[2]+values[3]; //le gagnant à la valeur absolue de la somme des scores des autres joueurs pour la partie
        }
    }

    return scores;
}

void afficheScore(int scores[]){
    //affiche les scores joueur par joueur
    //Besoins graphiques : affichage texte et tableau
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
    //Besoins graphiques : affichage texte
    ot = ot + 1;
    ot = ot%nbj;
    return ot;
}

int isMyTurn(int t, int idJoueur){
    //permet de vérifier si c'est le tour du joueur lorsqu'il tente une action
    //l'action ne sera validée que si la condition est vraie
    //Besoin graphique : texte pour prévenir le joueur qu'il ne peut pas jouer
    if (t == (idJoueur-1)){
        return 1;
    }
    else {
        return 0;
        //Affiche un message demandant au joueur d'attendre son tour
    }
}



//Pioche

void pioche(int nb, int idJoueur){
    //permet de piocher des tuiles depuis la réserve, généralement soit 1 ou 14
    //Besoin graphique : tuile, animation de déplacement de tuile

    for (int i=1; i<nb; i++){
        int n;
        int c;
        int a = 1;
        while(a){
            n = rand()%14+1; //permet d'obtenir un numéro de tuile
            c = rand()%4+1; //permet d'obtenir une couleur de tuile
            if (reserve [n-1] [c-1] > 0){ //si la tuile est dans la réserve, pour éviter les duplicatas
                a=0;
                reserve [n-1] [c-1] = reserve [n-1] [c-1] -1; //on enlève la tuile de la réserve
            }
        }
        //mettre la tuile dans le chevalet du joueur
        //tuile t;
        //t.valeur = n;
        //t.couleur = c;
    }
}

void initReserve(){
    for (int n=1; n<14; n++){
        for (int c=1; c<5; c++){
            /*tuile nt; //génère la tuile
            nt.valeur = n;
            nt.couleur = c;*/
            reserve [n-1] [c-1] = 2; //indique que la tuile est dans la réserve en 2 exemplaires
        }
    }
    reserve [14-1] [1-1] = 1; //génère le joker rouge
    reserve [14-1] [2-1] = 1; //génère le joker noir
    reserve [14-1] [3-1] = 1; //génère le joker orange
    reserve [14-1] [4-1] = 1; //génère le joker bleu
}

//IA
/* On considère que les ia testent les combinaisons possibles jusqua trouver la meilleur pour l'instant*/



//Chevalets





//Plateau de Jeu



