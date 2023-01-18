/*Fichier écrit par Guillaume FROMENT

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

int verif_combinaison(combinaison c){
    int length=0;
    tuile count = c.list[length];
    while(verif_tuile(count)){ //cette boucle permet de compter le nombre de tuile et de vérifier leur validité
        length = length+1;
        printf("\n\n\nTuile num %d : \n", length);
        print_tuile(count);
        
        count = c.list[length];
    }
    //length = length -1;
    printf("%d\n", length);
    if (length < 3){ //si la combinaison est trop petite, elle n'est pas valide
        return 0;
    }

    tuile t1 = c.list[0];
    tuile t2 = c.list[1];
    if (t1.valeur == t2.valeur){ //permet de voir si la fonction est supposée être un carré
        int carre = t1.valeur;
        tuile t3 = c.list[2];
        tuile t4;
        int couleurs [5]; //permet de compter les couleurs disponibles
        couleurs[1] = 1;
        couleurs[2] = 1;
        couleurs[3] = 1;
        couleurs[4] = 1;
        int l = 0; //permet de dire si la carré est de longueur 3 (l=0) ou 4 (l=1)
        if (length == 4){
            l=1;
            t4 = c.list[3];
        }
        if (t3.valeur != carre){
            return 0;
        }
        if (l == 1 && t4.valeur != carre){
            return 0;
        }
        couleurs[t1.couleur] = couleurs[t1.couleur]-1; //permet de signifier que la couleur n'est pas utilisable par une autre tuile
        couleurs[t2.couleur] = couleurs[t2.couleur]-1;
        couleurs[t3.couleur] = couleurs[t3.couleur]-1;
        if (l == 1){
            couleurs[t4.couleur] = couleurs[t4.couleur]-1;
        }
        if (couleurs[1] < 0 || couleurs[2] < 0 || couleurs[3] < 0 || couleurs[4] < 0){ //si chaque couleur est utilisée au plus une fois
            return 0;
        }
        return 1;
    }

    return 0;
}

int main (void){
    combinaison c;

    tuile r1;
    r1.valeur = 1;
    r1.couleur = 1;

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
    c.list[1] = v1;
    c.list[2] = o1;
    c.list[3] = b1;

    c.isValid = verif_combinaison(c);

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
}