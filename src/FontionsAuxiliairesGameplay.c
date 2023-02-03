/*
Prototypes des Fonctions de Guillaume FROMENT

Les codes suivants sont pour l'instant des algorithmes qui nous permettent de décider du comportement du système
*/

#include "../include/include.h"

void print_tuile(tuile t){
    printf(" Tuile : %d ", t.valeur);
    if (t.couleur == 0){
        printf("test\n");
    }
    else if (t.couleur == 1){
        printf("rouge\n");
    }
    else if (t.couleur == 2){
        printf("vert\n");
    }
    else if (t.couleur == 3){
        printf("orange\n");
    }
    else if (t.couleur == 4){
        printf("bleu\n");
    }
}

//Structures

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

    //affichage message pour confirmer le changement de tour

    /*gestion event*/

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

app_che pioche(int nb, app_che ac){
    //permet de piocher des tuiles depuis la réserve, généralement soit 1 ou 14
    //Besoin graphique : tuile, animation de déplacement de tuile
    int y=0;
    for (int i=1; i<=nb; i++){
        int n;
        int couleur;
        int a = 1;
        while(a){
            n = rand()%14+1; //permet d'obtenir un numéro de tuile
            couleur = rand()%4+1; //permet d'obtenir une couleur de tuile
            if (reserve [n-1] [couleur] > 0 && reserve [n-1] [couleur] < 3){ //si la tuile est dans la réserve, pour éviter les duplicatas
                a=0;
                reserve [n-1] [couleur] = reserve [n-1] [couleur] -1; //on enlève la tuile de la réserve
            }
        }
        //mettre la tuile dans le chevalet du joueur
        tuile t;
        t.valeur = n;
        t.couleur = couleur;
        

        a=1;
        printf("pioche\n");
        while (a){// cette boucle permet de placer la tuile piochée au bon endroit du chevalet
            if (ac.che.list[y].valeur == 0){// lorsqu'un chevalet est créé, il faut mettre la valeur des "tuiles" de la liste à 0 pour éviter les erreurs, 
                ac.che.list[y] = t;         //ainsi une tuile dont la valeur vaut 0 est un emplacement libre où placer les tuiles jouables 
                printf("pre_pioche\n");
                ac.app = dessin_tuile(ac.app,t,y);//print_tuile(t);// dessinons la tuile (ou les tuiles ) 
                a=0;
                printf("post_pioche\n");
            }
            else{
                y=y+1;
            }
        }

        
    }
    return ac;
     
}

void initReserve(){ //permet d'initialiser la réserve
    for (int n=1; n<14; n++){
        for (int c=1; c<5; c++){
            reserve [n-1] [c] = 2; //indique que la tuile est dans la réserve en 2 exemplaires
        }
    }
    reserve [14-1] [1] = 1; //génère le joker rouge
    reserve [14-1] [2] = 1; //génère le joker vert
    reserve [14-1] [3] = 1; //génère le joker orange
    reserve [14-1] [4] = 1; //génère le joker bleu
}

//IA
/* On considère que les ia testent les combinaisons possibles jusqu'a trouver la meilleure pour l'instant*/




//Plateau de Jeu


