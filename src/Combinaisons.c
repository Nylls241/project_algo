/*Fichier écrit par Guillaume FROMENT et Belinda AWUDZA

Il a pour but de tester et d'implémenter les combinaisons du rummicube*/

#include "../include/include.h"

void print_tuile(tuile t){
    printf("%d ", t.valeur);
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

int verif_tuile(tuile t){
    if (t.valeur > 0 && t.valeur < 15 && t.couleur > 0 && t.couleur < 5){
        return 1; //tuile valide
    }
    return 0; //tuile invalide
}

/*fonction qui compte combien de tuile il y a dans une combinaison et renvoie le nombre de tuile qu'il y a dans une combinaison*/
int nb_tuile(combinaison combi){
  int n=0;
  int i=0;
  //si la tuile suivante a pour valeur 0 alors les cases suivantes sont vides
    while(combi.list[i].valeur!=0){
      n=n+1;
      i++;
    }

  return n;
}

void print_combinaison(combinaison c){
    tuile t;
    int i=0;
    do{
        i = i+1;
        t = c.list[i-1];
        if (verif_tuile(t) == 1){
            printf("\n\n\nTuile num %d : \n", i);
            print_tuile(t);
        }
        else{
            printf("break\n");
            break;
        }
    }while(verif_tuile(t));
    printf("isValid = %d\n", c.isValid);
    printf("FIN DE COMBINAISON\n");
}

/*cette fonction prend en paramètre une fonction et renvoie 1 si la fonction est valide et 0 sinon*/
int est_valide_combi(combinaison combi){
    /*condition initaile la combinaison doit avoir un nombre de tuiles supérieur ou egal à 3*/
    /*combinaisons des carrés de tuiles */
    if (nb_tuile(combi)>=3){
        //si on est en présence d'une combinaison de 3 tuiles
        if(nb_tuile(combi)==3){
            // verifions si les couleurs sont différentes
            if(combi.list[0].couleur!=combi.list[1].couleur && combi.list[1].couleur!=combi.list[2].couleur && combi.list[0].couleur!=combi.list[2].couleur){
                //verifions si les valeurs sont les mêmes
                if (combi.list[0].valeur==combi.list[1].valeur && combi.list[0].valeur==combi.list[2].valeur && combi.list[1].valeur == combi.list[2].valeur){
                combi.isValid=1;
                }
            }
            else{
                int intCouleur=combi.list[0].couleur;
                int intValeur=combi.list[0].valeur;
                if(combi.list[0].couleur==intCouleur && combi.list[1].couleur && combi.list[1].couleur==intCouleur && combi.list[2].couleur==intCouleur){
                    if (combi.list[0].valeur==intValeur && combi.list[1].valeur==intValeur+1 && combi.list[2].valeur == intValeur+2){
                        combi.isValid=1;
                    }
                }
            }
        }
        //si on est en presence d'une combinaison de 4 tuile
        if(nb_tuile(combi)==4){
            // verifions si les couleurs sont différentes
            if(combi.list[0].couleur!=combi.list[1].couleur && combi.list[0].couleur!=combi.list[3].couleur && combi.list[1].couleur!=combi.list[2].couleur &&combi.list[1].couleur!=combi.list[3].couleur && combi.list[0].couleur!=combi.list[2].couleur && combi.list[3].couleur!=combi.list[2].couleur  ){
                //verifions si les valeurs sont les mêmes
                if(combi.list[0].valeur ==combi.list[1].valeur && combi.list[0].valeur==combi.list[3].valeur && combi.list[1].valeur ==combi.list[2].valeur &&combi.list[1].valeur==combi.list[3].valeur && combi.list[0].valeur==combi.list[2].valeur && combi.list[3].valeur==combi.list[2].valeur){
                combi.isValid=1;
                }
            }
            else{
                int intCouleur=combi.list[0].couleur;
                int intValeur=combi.list[0].valeur;
                if(combi.list[0].couleur==intCouleur && combi.list[1].couleur && combi.list[1].couleur==intCouleur && combi.list[2].couleur==intCouleur && combi.list[3].couleur==intCouleur){
                //verifions que c'est une suite
                    if (combi.list[0].valeur==intValeur && combi.list[1].valeur==intValeur+1 && combi.list[2].valeur == intValeur+2 && combi.list[3].valeur==intValeur+3){
                    combi.isValid=1;
                    }
                }
            }
        }
        if(nb_tuile(combi)>4){
            int intCouleur=combi.list[0].couleur;
            int intValeur=combi.list[0].valeur;
            int n=0;
            for(int i=0;i<nb_tuile(combi);i++){
                if(combi.list[i].couleur==intCouleur && combi.list[i].valeur==intValeur+i){
                n=n+1;
                }
            }
            if(n==nb_tuile(combi)){
                combi.isValid=1;
            }
        }


    }

    return combi.isValid;
}



/***
 * Test des fonctions
*/
/*int main (void){
    combinaison c;

    tuile r1;
    r1.valeur = 1;
    r1.couleur = 1;

    tuile r2;
    r2.valeur = 2;
    r2.couleur = 1;

    tuile r3;
    r3.valeur = 3;
    r3.couleur = 1;

    tuile v1;
    v1.valeur = 1;
    v1.couleur = 2;

    tuile o1;
    o1.valeur = 1;
    o1.couleur = 3;

    tuile b1;
    b1.valeur = 1;
    b1.couleur = 4;

    c.list[0] = r1;
    c.list[1] = r2;
    c.list[2] = r3;
    //c.list[3] = b1;

    c.isValid = est_valide_combi(c);

    printf("%d\n", c.isValid);
    //print_tuile(r1);
    //printf("%d\n", verif_tuile(r1));
    //print_tuile(n1);
    //printf("%d\n", verif_tuile(n1));
    //print_tuile(o1);
    //printf("%d\n", verif_tuile(o1));
    //print_tuile(b1);
    //printf("%d\n", verif_tuile(b1));
    return 0;
}*/