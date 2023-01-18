#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>
#include <stdbool.h> // type booleen

typedef enum COULEUR
{
		joker,jaune,rouge,bleu,noir,vide
}COULEUR;


typedef struct TUILE
{
		COULEUR couleur;
		int nombre;
}TUILE;

typedef struct PLAYER
{
        char pseudo[30];
//        TUILES chevalets[38];
		int score;
}PLAYER;

//Partie de Slim
//Création des tuiles avant leur distribution (Slim)
void choisir_les_tuiles(TUILE tuiles[106])
{
	TUILE temp;
	int i;
	int x;
	for(i=0;i<13;i++)
	{
		tuiles[i].nombre= i + 1;
		tuiles[i].couleur=jaune;
		tuiles[i + 13].nombre= i + 1;
		tuiles[i + 13].couleur=rouge;
		tuiles[i + 26].nombre= i + 1;
		tuiles[i + 26].couleur=bleu;
		tuiles[i + 39].nombre= i + 1;
		tuiles[i + 39].couleur=noir;
		tuiles[i + 52].nombre= i + 1;
		tuiles[i + 52].couleur=jaune;
		tuiles[i + 65].nombre= i + 1;
		tuiles[i + 65].couleur=rouge;
		tuiles[i + 78].nombre= i + 1;
		tuiles[i + 78].couleur=bleu;
		tuiles[i + 91].nombre= i + 1;
		tuiles[i + 91].couleur=noir;
	}
	tuiles[104].couleur=joker;
	tuiles[105].couleur=joker;
	tuiles[104].nombre= 30;
	tuiles[105].nombre= 30;
	
//	for(i=0;i<106;i++)
//	{
//		printf("%d, %d \n", tuiles[i].nombre, tuiles[x].nombre);
//	}
	for(i=0;i<106;i++)
	{
		x = (rand()%106);
		temp.nombre = tuiles[i].nombre;
		temp.couleur = tuiles[i].couleur;
		tuiles[i].nombre = tuiles[x].nombre;
		tuiles[i].couleur = tuiles[x].couleur;
		tuiles[x].nombre = temp.nombre;
		tuiles[x].couleur = temp.couleur;
	}
}

//Distribution des tuiles selon le nomrbe des joueurs
void distribuer_cartes(int nombre_joueurs, TUILE joueur1[2][19], TUILE joueur2[2][19], TUILE joueur3[2][19], TUILE joueur4[2][19], TUILE tuiles[106], int* curseur)
{
	int i=0;
	for(i=0;i<7;i++)
	{
		joueur1[0][i].nombre=tuiles[*curseur].nombre;
		joueur1[0][i].couleur=tuiles[*curseur].couleur;
		*curseur = *curseur + 1;
		joueur1[1][i].nombre=tuiles[*curseur].nombre;
		joueur1[1][i].couleur=tuiles[*curseur].couleur;
		*curseur = *curseur + 1;
	}
	for(i=0;i<7;i++)
	{
		joueur2[0][i].nombre=tuiles[*curseur].nombre;
		joueur2[0][i].couleur=tuiles[*curseur].couleur;
		*curseur = *curseur + 1;
		joueur2[1][i].nombre=tuiles[*curseur].nombre;
		joueur2[1][i].couleur=tuiles[*curseur].couleur;
	}
	if(nombre_joueurs == 3 || nombre_joueurs == 4)
	{
		for(i=0;i<7;i++)
		{
			joueur3[0][i].nombre=tuiles[*curseur].nombre;
			joueur3[0][i].couleur=tuiles[*curseur].couleur;
			*curseur = *curseur + 1;
			joueur3[1][i].nombre=tuiles[*curseur].nombre;
			joueur3[1][i].couleur=tuiles[*curseur].couleur;
			*curseur = *curseur + 1;
		}
	}	
	if(nombre_joueurs == 4)
	{
		for(i=0;i<7;i++)
		{
			joueur4[0][i].nombre=tuiles[*curseur].nombre;
			joueur4[0][i].couleur=tuiles[*curseur].couleur;
			*curseur = *curseur + 1;
			joueur4[1][i].nombre=tuiles[*curseur].nombre;
			joueur4[1][i].couleur=tuiles[*curseur].couleur;
			*curseur = *curseur + 1;
		}
	}	
}


void deplacer_tuile_du_chevalet_vers_grille(int abscisse_tuile_dans_grille, int ordonnee_tuile_dans_grille,int abscisse_tuile_dans_chevalet, int ordonnee_tuile_dans_chevalet, TUILE joueur[2][19], TUILE tuiles [212][212])
{
	TUILE temp;
	temp.nombre = tuiles[abscisse_tuile_dans_grille][ordonnee_tuile_dans_grille].nombre;
	temp.couleur = tuiles[abscisse_tuile_dans_grille][ordonnee_tuile_dans_grille].couleur;
	tuiles[abscisse_tuile_dans_grille][ordonnee_tuile_dans_grille].nombre=joueur[abscisse_tuile_dans_chevalet][ordonnee_tuile_dans_chevalet].nombre;
	tuiles[abscisse_tuile_dans_grille][ordonnee_tuile_dans_grille].couleur=joueur[abscisse_tuile_dans_chevalet][ordonnee_tuile_dans_chevalet].couleur;
	joueur[abscisse_tuile_dans_chevalet][ordonnee_tuile_dans_chevalet].nombre= temp.nombre;
	joueur[abscisse_tuile_dans_chevalet][ordonnee_tuile_dans_chevalet].couleur= temp.couleur;
}

void echanger_tuile_dans_chevalet(int abscisse1, int ordonnee1,int abscisse2, int ordonnee2, TUILE tuiles [212][212])
{
	TUILE temp;
	temp.nombre = tuiles[abscisse1][ordonnee1].nombre;
	temp.couleur = tuiles[abscisse1][ordonnee1].couleur;
	tuiles[abscisse1][ordonnee1].nombre = tuiles[abscisse2][ordonnee2].nombre;
	tuiles[abscisse1][ordonnee1].couleur = tuiles[abscisse2][ordonnee2].couleur;
	tuiles[abscisse2][ordonnee2].nombre = temp.nombre;
	tuiles[abscisse2][ordonnee2].couleur = temp.couleur;
}

typedef struct CASE
{
	int x;
	int y;
	int zone;
}CASE;

void piocher(TUILE joueur[2][19], TUILE tuiles[106], int* curseur)
{
	int i = 0;
	int j = 0;
	int continuer = 0;
	for(i = 0; i < 2; i ++){
		for(j = 0; j < 19; j ++){
			if (joueur[i][j].couleur == vide && continuer == 0)
			{
				continuer = 1;
				joueur[i][j].nombre=tuiles[*curseur].nombre;
				joueur[i][j].couleur=tuiles[*curseur].couleur;
				*curseur = *curseur + 1;
				
			}
		}
	}
}

CASE case_cliquee (SDL_Rect coordonnees, int decallageX, int decallageY)
{
	CASE Case;
	int x = coordonnees.x;
	int y = coordonnees.y;
	if ( x < 131 || x > 956 || y < 620 )
	{
		Case.x = (x + decallageX)/43;
		Case.y = (y + decallageY)/50;
		Case.zone = 2;
	}
	else
	{
		Case.zone = 1;
		Case.x = (x - 131)/43;
		if (y > 670)
		{
			Case.y = 0;
		}
		else
		{
			Case.y = 1;
		}
	}
	return Case;
}

SDL_Rect Coordonnee_de_Case (CASE Case, int decallageX, int decallageY)
{
	SDL_Rect rep;
	if (Case.zone == 1)
	{
		rep.x = (Case.x * 43) + 131;
		if (Case.y == 0)
		{
			rep.y = 670;
		}
		else
		{
			rep.y = 620;
		}
		
	}
	else if (Case.zone == 2)
	{
		rep.x = (Case.x * 43) - decallageX;
		rep.y = (Case.y * 50) - decallageY;
	}
	return rep;
}

void dessiner_curseur_chevalet(int curseurchevalet, int decallageX, int decallageY, SDL_Surface* ecran)
{
	SDL_Surface *dessin = NULL;
    SDL_Rect positionCurseur;
    CASE Case;
    
	Case.x = curseurchevalet % 19;
	if ( curseurchevalet < 19)
	{
		Case.y = 1;
	}else{
		Case.y = 0;
	}
	Case.zone = 1;
    dessin = SDL_LoadBMP("images/curseur.bmp");
    positionCurseur = Coordonnee_de_Case(Case, decallageX, decallageY);
	SDL_BlitSurface(dessin, NULL, ecran, &positionCurseur);
    SDL_FreeSurface(dessin);
	
}

void dessiner_curseur(int curseurX, int curseurY, int decallageX, int decallageY, SDL_Surface* ecran)
{
	SDL_Surface *dessin = NULL;
    SDL_Rect positionCurseur;
    CASE Case;
    
	Case.x = curseurX;
	Case.y = curseurY;
	Case.zone = 2;
    dessin = SDL_LoadBMP("images/curseur.bmp");
    positionCurseur = Coordonnee_de_Case(Case, decallageX, decallageY);
	SDL_BlitSurface(dessin, NULL, ecran, &positionCurseur);
    SDL_FreeSurface(dessin);
	
}

void dessiner_tuile (SDL_Rect Coordonnee, TUILE tuile, SDL_Surface* ecran)
{
	SDL_Surface *dessin = NULL;
    SDL_Rect positionTuile;
    if (tuile.couleur == jaune)
    {
		switch(tuile.nombre){
			case 1 :
				dessin = SDL_LoadBMP("images/O_01.bmp");
				break;
			case 2 :
				dessin = SDL_LoadBMP("images/O_02.bmp");
				break;
			case 3 :
				dessin = SDL_LoadBMP("images/O_03.bmp");
				break;
			case 4 :
				dessin = SDL_LoadBMP("images/O_04.bmp");
				break;
			case 5 :
				dessin = SDL_LoadBMP("images/O_05.bmp");
				break;
			case 6 :
				dessin = SDL_LoadBMP("images/O_06.bmp");
				break;
			case 7 :
				dessin = SDL_LoadBMP("images/O_07.bmp");
				break;
			case 8 :
				dessin = SDL_LoadBMP("images/O_08.bmp");
				break;
			case 9 :
				dessin = SDL_LoadBMP("images/O_09.bmp");
				break;
			case 10 :
				dessin = SDL_LoadBMP("images/O_10.bmp");
				break;
			case 11 :
				dessin = SDL_LoadBMP("images/O_11.bmp");
				break;
			case 12 :
				dessin = SDL_LoadBMP("images/O_12.bmp");
				break;
			case 13 :
				dessin = SDL_LoadBMP("images/O_13.bmp");
				break;
		}
	}
	else if (tuile.couleur == rouge)
    {
		switch(tuile.nombre){
			case 1 :
				dessin = SDL_LoadBMP("images/r_01.bmp");
				break;
			case 2 :
				dessin = SDL_LoadBMP("images/r_02.bmp");
				break;
			case 3 :
				dessin = SDL_LoadBMP("images/r_03.bmp");
				break;
			case 4 :
				dessin = SDL_LoadBMP("images/r_04.bmp");
				break;
			case 5 :
				dessin = SDL_LoadBMP("images/r_05.bmp");
				break;
			case 6 :
				dessin = SDL_LoadBMP("images/r_06.bmp");
				break;
			case 7 :
				dessin = SDL_LoadBMP("images/r_07.bmp");
				break;
			case 8 :
				dessin = SDL_LoadBMP("images/r_08.bmp");
				break;
			case 9 :
				dessin = SDL_LoadBMP("images/r_09.bmp");
				break;
			case 10 :
				dessin = SDL_LoadBMP("images/r_10.bmp");
				break;
			case 11 :
				dessin = SDL_LoadBMP("images/r_11.bmp");
				break;
			case 12 :
				dessin = SDL_LoadBMP("images/r_12.bmp");
				break;
			case 13 :
				dessin = SDL_LoadBMP("images/r_13.bmp");
				break;
		}
	}
	else if (tuile.couleur == bleu)
    {
		switch(tuile.nombre){
			case 1 :
				dessin = SDL_LoadBMP("images/b_01.bmp");
				break;
			case 2 :
				dessin = SDL_LoadBMP("images/b_02.bmp");
				break;
			case 3 :
				dessin = SDL_LoadBMP("images/b_03.bmp");
				break;
			case 4 :
				dessin = SDL_LoadBMP("images/b_04.bmp");
				break;
			case 5 :
				dessin = SDL_LoadBMP("images/b_05.bmp");
				break;
			case 6 :
				dessin = SDL_LoadBMP("images/b_06.bmp");
				break;
			case 7 :
				dessin = SDL_LoadBMP("images/b_07.bmp");
				break;
			case 8 :
				dessin = SDL_LoadBMP("images/b_08.bmp");
				break;
			case 9 :
				dessin = SDL_LoadBMP("images/b_09.bmp");
				break;
			case 10 :
				dessin = SDL_LoadBMP("images/b_10.bmp");
				break;
			case 11 :
				dessin = SDL_LoadBMP("images/b_11.bmp");
				break;
			case 12 :
				dessin = SDL_LoadBMP("images/b_12.bmp");
				break;
			case 13 :
				dessin = SDL_LoadBMP("images/b_13.bmp");
				break;
		}
	}
	else if (tuile.couleur == noir)
    {
		switch(tuile.nombre){
			case 1 :
				dessin = SDL_LoadBMP("images/g_01.bmp");
				break;
			case 2 :
				dessin = SDL_LoadBMP("images/g_02.bmp");
				break;
			case 3 :
				dessin = SDL_LoadBMP("images/g_03.bmp");
				break;
			case 4 :
				dessin = SDL_LoadBMP("images/g_04.bmp");
				break;
			case 5 :
				dessin = SDL_LoadBMP("images/g_05.bmp");
				break;
			case 6 :
				dessin = SDL_LoadBMP("images/g_06.bmp");
				break;
			case 7 :
				dessin = SDL_LoadBMP("images/g_07.bmp");
				break;
			case 8 :
				dessin = SDL_LoadBMP("images/g_08.bmp");
				break;
			case 9 :
				dessin = SDL_LoadBMP("images/g_09.bmp");
				break;
			case 10 :
				dessin = SDL_LoadBMP("images/g_10.bmp");
				break;
			case 11 :
				dessin = SDL_LoadBMP("images/g_11.bmp");
				break;
			case 12 :
				dessin = SDL_LoadBMP("images/g_12.bmp");
				break;
			case 13 :
				dessin = SDL_LoadBMP("images/g_13.bmp");
				break;
		}
	}
	else if (tuile.couleur == joker)
    {
		dessin = SDL_LoadBMP("images/b0.bmp");
	}
    positionTuile = Coordonnee;
	SDL_BlitSurface(dessin, NULL, ecran, &positionTuile);
    SDL_FreeSurface(dessin);
}

void afficher_plateau (TUILE plateau [212][212], SDL_Surface* ecran, int decallageX, int decallageY)
{
	CASE Case;
	int i = 0;
	int j = 0;
	for(i = 0; i < 212; i ++){
		for(j = 0; j < 212; j ++){
			Case.x = i;
			Case.y = j;
			Case.zone = 2;
			dessiner_tuile (Coordonnee_de_Case (Case, decallageX, decallageY), plateau[i][j], ecran);
		}
	}
}

void afficher_joueur (SDL_Surface* ecran, int joueurActif)
{
	int i = 0;
	int j = 0;
	
	SDL_Rect postitionPseudo;
	postitionPseudo.x = 0;
	postitionPseudo.y = 720;
	SDL_Surface *dessin = NULL;
	if(joueurActif == 1){
		dessin = SDL_LoadBMP("lettres/J1.bmp");
	}else if(joueurActif == 2){
		dessin = SDL_LoadBMP("lettres/J2.bmp");
	}else if(joueurActif == 3){
		dessin = SDL_LoadBMP("lettres/J3.bmp");
	}else{
		dessin = SDL_LoadBMP("lettres/J4.bmp");
	}
	SDL_BlitSurface(dessin, NULL, ecran, &postitionPseudo);
	
    SDL_FreeSurface(dessin);
}

void afficher_chevalet (TUILE chevalet [2][19], SDL_Surface* ecran)
{
	
	CASE Case;
	int i = 0;
	int j = 0;
	
	SDL_Rect postitionChevalet;
	postitionChevalet.x = 131;
	postitionChevalet.y = 620;
	SDL_Surface *dessin = NULL;
	
	dessin = SDL_LoadBMP("images/chevalet.bmp");
	SDL_BlitSurface(dessin, NULL, ecran, &postitionChevalet);
    
	for(i = 0; i < 2; i ++){
		for(j = 0; j < 19; j ++){
			Case.x = j;
			Case.y = i;
			Case.zone = 1;
			dessiner_tuile (Coordonnee_de_Case (Case, 0, 0), chevalet[i][j], ecran);
		}
	}
	
    SDL_FreeSurface(dessin);
}

int est_coup_valide(TUILE plateau [212][212], TUILE plateau_copie [212][212], int premierCoup)
{
	int total = 0;
	int i = 0;
	int j = 0;
	int rep = 1;
	for(i = 2; i < 210; i ++){
		for(j = 2; j < 210; j ++){
			if (plateau_copie[i][j].couleur == vide || (plateau_copie[i][j].couleur == plateau[i][j].couleur && plateau_copie[i][j].nombre == plateau[i][j].nombre))
			{
				//printf("_");
			}
			else if( (plateau_copie[i - 2][j].nombre == plateau_copie[i - 1][j].nombre && plateau_copie[i - 1][j].nombre == plateau_copie[i][j].nombre) ||
					  (plateau_copie[i - 1][j].nombre == plateau_copie[i][j].nombre && plateau_copie[i][j].nombre == plateau_copie[i + 1][j].nombre) ||
					  (plateau_copie[i][j].nombre == plateau_copie[i + 1][j].nombre && plateau_copie[i + 1][j].nombre == plateau_copie[i + 2][j].nombre) ||
					  (plateau_copie[i][j - 2].nombre == plateau_copie[i][j - 1].nombre && plateau_copie[i][j - 1].nombre == plateau_copie[i][j].nombre) ||
					  (plateau_copie[i][j - 1].nombre == plateau_copie[i][j].nombre && plateau_copie[i][j].nombre == plateau_copie[i][j + 1].nombre) ||
					  (plateau_copie[i][j].nombre == plateau_copie[i][j + 1].nombre && plateau_copie[i][j + 1].couleur == plateau_copie[i][j + 2].nombre) )
			{
				//printf("2");
			}
			else if( ( (plateau_copie[i - 2][j].nombre == (plateau_copie[i - 1][j].nombre + 1) && plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre + 1)) ||
					  (plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre + 1) && plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre + 1)) ||
					  (plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre + 1) && plateau_copie[i + 1][j].nombre == (plateau_copie[i + 2][j].nombre + 1)) ||
					  (plateau_copie[i][j - 2].nombre == (plateau_copie[i][j - 1].nombre + 1) && plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre + 1)) ||
					  (plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre + 1) && plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre + 1)) ||
					  (plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre + 1) && plateau_copie[i][j + 1].couleur == (plateau_copie[i][j + 2].nombre + 1)) ||
					  (plateau_copie[i - 2][j].nombre == (plateau_copie[i - 1][j].nombre - 1) && plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre - 1)) ||
					  (plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre - 1) && plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre - 1)) ||
					  (plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre - 1) && plateau_copie[i + 1][j].nombre == (plateau_copie[i + 2][j].nombre - 1)) ||
					  (plateau_copie[i][j - 2].nombre == (plateau_copie[i][j - 1].nombre - 1) && plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre - 1)) ||
					  (plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre - 1) && plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre - 1)) ||
					  (plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre - 1) && plateau_copie[i][j + 1].couleur == (plateau_copie[i][j + 2].nombre - 1)) ) &&
					  ( (plateau_copie[i - 2][j].couleur == plateau_copie[i - 1][j].couleur && plateau_copie[i - 1][j].couleur == plateau_copie[i][j].couleur) ||
					  (plateau_copie[i - 1][j].couleur == plateau_copie[i][j].couleur && plateau_copie[i][j].couleur == plateau_copie[i + 1][j].couleur) ||
					  (plateau_copie[i][j].couleur == plateau_copie[i + 1][j].couleur && plateau_copie[i + 1][j].couleur == plateau_copie[i + 2][j].couleur) ||
					  (plateau_copie[i][j - 2].couleur == plateau_copie[i][j - 1].couleur && plateau_copie[i][j - 1].couleur == plateau_copie[i][j].couleur) ||
					  (plateau_copie[i][j - 1].couleur == plateau_copie[i][j].couleur && plateau_copie[i][j].couleur == plateau_copie[i][j + 1].couleur) ||
					  (plateau_copie[i][j].couleur == plateau_copie[i][j + 1].couleur && plateau_copie[i][j + 1].couleur == plateau_copie[i][j + 2].couleur) ) )
			{
				//printf("3");
			}
			else
			{
				rep = 0;
				//printf("X");
			}
		}
		//printf(" . .\n");
	}
	for(i = 2; i < 210; i ++){
		if (plateau_copie[i][0].couleur == vide || (plateau_copie[i][0].couleur == plateau[i][0].couleur && plateau_copie[i][0].nombre == plateau[i][0].nombre))
		{
			//printf("_");
		}
		else if( (plateau_copie[i - 2][j].nombre == plateau_copie[i - 1][0].nombre && plateau_copie[i - 1][0].nombre == plateau_copie[i][0].nombre) ||
				  (plateau_copie[i - 1][j].nombre == plateau_copie[i][0].nombre && plateau_copie[i][0].nombre == plateau_copie[i + 1][0].nombre) ||
				  (plateau_copie[i][0].nombre == plateau_copie[i + 1][0].nombre && plateau_copie[i + 1][0].nombre == plateau_copie[i + 2][0].nombre) ||
				  (plateau_copie[i][0].nombre == plateau_copie[i][1].nombre && plateau_copie[i][2].couleur == plateau_copie[i][3].nombre) )
		{
			//printf("2");
		}
		else if(((plateau_copie[i - 2][0].nombre == (plateau_copie[i - 1][0].nombre + 1) && plateau_copie[i - 1][0].nombre == (plateau_copie[i][0].nombre + 1)) ||
				  (plateau_copie[i - 1][0].nombre == (plateau_copie[i][0].nombre + 1) && plateau_copie[i][0].nombre == (plateau_copie[i + 1][0].nombre + 1)) ||
				  (plateau_copie[i][0].nombre == (plateau_copie[i + 1][0].nombre + 1) && plateau_copie[i + 1][0].nombre == (plateau_copie[i + 2][0].nombre + 1)) ||
				  (plateau_copie[i][0].nombre == (plateau_copie[i][j + 0].nombre + 1) && plateau_copie[0][2].couleur == (plateau_copie[i][3].nombre + 1)) ||
				  (plateau_copie[i - 2][0].nombre == (plateau_copie[i - 0][j].nombre - 1) && plateau_copie[i - 1][0].nombre == (plateau_copie[i][0].nombre - 1)) ||
				  (plateau_copie[i - 1][0].nombre == (plateau_copie[i][0].nombre - 1) && plateau_copie[i][0].nombre == (plateau_copie[i + 1][0].nombre - 1)) ||
				  (plateau_copie[i][0].nombre == (plateau_copie[i + 1][0].nombre - 1) && plateau_copie[i + 1][0].nombre == (plateau_copie[i + 2][0].nombre - 1)) ||
				  (plateau_copie[i][0].nombre == (plateau_copie[i][1].nombre - 1) && plateau_copie[i][2].couleur == (plateau_copie[i][3].nombre - 1)) ) &&
				  ( (plateau_copie[i - 2][0].couleur == plateau_copie[i - 1][0].couleur && plateau_copie[i - 1][0].couleur == plateau_copie[i][0].couleur) ||
				  (plateau_copie[i - 1][0].couleur == plateau_copie[i][0].couleur && plateau_copie[i][0].couleur == plateau_copie[i + 1][0].couleur) ||
				  (plateau_copie[i][0].couleur == plateau_copie[i + 1][0].couleur && plateau_copie[i + 1][0].couleur == plateau_copie[i + 2][0].couleur) ||
				  (plateau_copie[i][0].couleur == plateau_copie[i][1].couleur && plateau_copie[i][2].couleur == plateau_copie[i][3].couleur) ) )
		{
			//printf("3");
		}
		else
		{
			rep = 0;
			//printf("X");
		}
		//printf(" . .\n");
	}
	for(i = 2; i < 210; i ++){
		j = 211;
		if (plateau_copie[i][j].couleur == vide || (plateau_copie[i][j].couleur == plateau[i][j].couleur && plateau_copie[i][j].nombre == plateau[i][j].nombre))
		{
			//printf("_");
		}
		else if( (plateau_copie[i - 2][j].nombre == plateau_copie[i - 1][j].nombre && plateau_copie[i - 1][j].nombre == plateau_copie[i][j].nombre) ||
				  (plateau_copie[i - 1][j].nombre == plateau_copie[i][j].nombre && plateau_copie[i][j].nombre == plateau_copie[i + 1][j].nombre) ||
				  (plateau_copie[i][j].nombre == plateau_copie[i + 1][j].nombre && plateau_copie[i + 1][j].nombre == plateau_copie[i + 2][j].nombre) ||
				  (plateau_copie[i][j - 2].nombre == plateau_copie[i][j - 1].nombre && plateau_copie[i][j - 1].nombre == plateau_copie[i][j].nombre) )
		{
			//printf("2");
		}
		else if(((plateau_copie[i - 2][j].nombre == (plateau_copie[i - 1][j].nombre + 1) && plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre + 1)) ||
				  (plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre + 1) && plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre + 1)) ||
				  (plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre + 1) && plateau_copie[i + 1][j].nombre == (plateau_copie[i + 2][j].nombre + 1)) ||
				  (plateau_copie[i][j - 2].nombre == (plateau_copie[i][j - 1].nombre + 1) && plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre + 1)) ||
				  (plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre + 1) && plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre + 1)) ||
				  (plateau_copie[i - 2][j].nombre == (plateau_copie[i - 1][j].nombre - 1) && plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre - 1)) ||
				  (plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre - 1) && plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre - 1)) ||
				  (plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre - 1) && plateau_copie[i + 1][j].nombre == (plateau_copie[i + 2][j].nombre - 1)) ||
				  (plateau_copie[i][j - 2].nombre == (plateau_copie[i][j - 1].nombre - 1) && plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre - 1)) ) &&
				  ( (plateau_copie[i - 2][j].couleur == plateau_copie[i - 1][j].couleur && plateau_copie[i - 1][j].couleur == plateau_copie[i][j].couleur) ||
				  (plateau_copie[i - 1][j].couleur == plateau_copie[i][j].couleur && plateau_copie[i][j].couleur == plateau_copie[i + 1][j].couleur) ||
				  (plateau_copie[i][j].couleur == plateau_copie[i + 1][j].couleur && plateau_copie[i + 1][j].couleur == plateau_copie[i + 2][j].couleur) ||
				  (plateau_copie[i][j - 2].couleur == plateau_copie[i][j - 1].couleur && plateau_copie[i][j - 1].couleur == plateau_copie[i][j].couleur)) )
		{
			//printf("3");
		}
		else
		{
			rep = 0;
			//printf("X");
		}
	}
	
	for(j = 2; j < 210; j ++){
		i = 0;
		if (plateau_copie[i][j].couleur == vide || (plateau_copie[i][j].couleur == plateau[i][j].couleur && plateau_copie[i][j].nombre == plateau[i][j].nombre))
		{
			//printf("_");
		}
		else if( (plateau_copie[i][j].nombre == plateau_copie[i + 1][j].nombre && plateau_copie[i + 1][j].nombre == plateau_copie[i + 2][j].nombre) ||
				  (plateau_copie[i][j - 2].nombre == plateau_copie[i][j - 1].nombre && plateau_copie[i][j - 1].nombre == plateau_copie[i][j].nombre) ||
				  (plateau_copie[i][j - 1].nombre == plateau_copie[i][j].nombre && plateau_copie[i][j].nombre == plateau_copie[i][j + 1].nombre) ||
				  (plateau_copie[i][j].nombre == plateau_copie[i][j + 1].nombre && plateau_copie[i][j + 1].couleur == plateau_copie[i][j + 2].nombre) )
		{
			//printf("2");
		}
		else if(((plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre + 1) && plateau_copie[i + 1][j].nombre == (plateau_copie[i + 2][j].nombre + 1)) ||
				  (plateau_copie[i][j - 2].nombre == (plateau_copie[i][j - 1].nombre + 1) && plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre + 1)) ||
				  (plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre + 1) && plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre + 1)) ||
				  (plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre + 1) && plateau_copie[i][j + 1].couleur == (plateau_copie[i][j + 2].nombre + 1)) ||
				  (plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre - 1) && plateau_copie[i + 1][j].nombre == (plateau_copie[i + 2][j].nombre - 1)) ||
				  (plateau_copie[i][j - 2].nombre == (plateau_copie[i][j - 1].nombre - 1) && plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre - 1)) ||
				  (plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre - 1) && plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre - 1)) ||
				  (plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre - 1) && plateau_copie[i][j + 1].couleur == (plateau_copie[i][j + 2].nombre - 1)) ) &&
				  ( (plateau_copie[i][j].couleur == plateau_copie[i + 1][j].couleur && plateau_copie[i + 1][j].couleur == plateau_copie[i + 2][j].couleur) ||
				  (plateau_copie[i][j - 2].couleur == plateau_copie[i][j - 1].couleur && plateau_copie[i][j - 1].couleur == plateau_copie[i][j].couleur) ||
				  (plateau_copie[i][j - 1].couleur == plateau_copie[i][j].couleur && plateau_copie[i][j].couleur == plateau_copie[i][j + 1].couleur) ||
				  (plateau_copie[i][j].couleur == plateau_copie[i][j + 1].couleur && plateau_copie[i][j + 1].couleur == plateau_copie[i][j + 2].couleur) ) )
		{
			//printf("3");
		}
		else
		{
			rep = 0;
			//printf("X");
		}
	}
	
	for(j = 2; j < 210; j ++){
		i = 211;
		if (plateau_copie[i][j].couleur == vide || (plateau_copie[i][j].couleur == plateau[i][j].couleur && plateau_copie[i][j].nombre == plateau[i][j].nombre))
		{
			//printf("_");
		}
		else if( (plateau_copie[i - 2][j].nombre == plateau_copie[i - 1][j].nombre && plateau_copie[i - 1][j].nombre == plateau_copie[i][j].nombre) ||
				  (plateau_copie[i][j - 2].nombre == plateau_copie[i][j - 1].nombre && plateau_copie[i][j - 1].nombre == plateau_copie[i][j].nombre) ||
				  (plateau_copie[i][j - 1].nombre == plateau_copie[i][j].nombre && plateau_copie[i][j].nombre == plateau_copie[i][j + 1].nombre) ||
				  (plateau_copie[i][j].nombre == plateau_copie[i][j + 1].nombre && plateau_copie[i][j + 1].couleur == plateau_copie[i][j + 2].nombre) )
		{
			//printf("2");
		}
		else if(((plateau_copie[i - 2][j].nombre == (plateau_copie[i - 1][j].nombre + 1) && plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre + 1)) ||
				  (plateau_copie[i][j - 2].nombre == (plateau_copie[i][j - 1].nombre + 1) && plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre + 1)) ||
				  (plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre + 1) && plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre + 1)) ||
				  (plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre + 1) && plateau_copie[i][j + 1].couleur == (plateau_copie[i][j + 2].nombre + 1)) ||
				  (plateau_copie[i - 2][j].nombre == (plateau_copie[i - 1][j].nombre - 1) && plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre - 1)) ||
				  (plateau_copie[i][j - 2].nombre == (plateau_copie[i][j - 1].nombre - 1) && plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre - 1)) ||
				  (plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre - 1) && plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre - 1)) ||
				  (plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre - 1) && plateau_copie[i][j + 1].couleur == (plateau_copie[i][j + 2].nombre - 1)) ) &&
				  ( (plateau_copie[i - 2][j].couleur == plateau_copie[i - 1][j].couleur && plateau_copie[i - 1][j].couleur == plateau_copie[i][j].couleur) ||
				  (plateau_copie[i][j - 2].couleur == plateau_copie[i][j - 1].couleur && plateau_copie[i][j - 1].couleur == plateau_copie[i][j].couleur) ||
				  (plateau_copie[i][j - 1].couleur == plateau_copie[i][j].couleur && plateau_copie[i][j].couleur == plateau_copie[i][j + 1].couleur) ||
				  (plateau_copie[i][j].couleur == plateau_copie[i][j + 1].couleur && plateau_copie[i][j + 1].couleur == plateau_copie[i][j + 2].couleur) ) )
		{
			//printf("3");
		}
		else
		{
			rep = 0;
			//printf("X");
		}
	}
	
	for(j = 2; j < 210; j ++){
		i = 1;
		if (plateau_copie[i][j].couleur == vide || (plateau_copie[i][j].couleur == plateau[i][j].couleur && plateau_copie[i][j].nombre == plateau[i][j].nombre))
		{
			//printf("_");
		}
		else if( (plateau_copie[i - 1][j].nombre == plateau_copie[i][j].nombre && plateau_copie[i][j].nombre == plateau_copie[i + 1][j].nombre) ||
				  (plateau_copie[i][j].nombre == plateau_copie[i + 1][j].nombre && plateau_copie[i + 1][j].nombre == plateau_copie[i + 2][j].nombre) ||
				  (plateau_copie[i][j - 2].nombre == plateau_copie[i][j - 1].nombre && plateau_copie[i][j - 1].nombre == plateau_copie[i][j].nombre) ||
				  (plateau_copie[i][j - 1].nombre == plateau_copie[i][j].nombre && plateau_copie[i][j].nombre == plateau_copie[i][j + 1].nombre) ||
				  (plateau_copie[i][j].nombre == plateau_copie[i][j + 1].nombre && plateau_copie[i][j + 1].couleur == plateau_copie[i][j + 2].nombre) )
		{
			//printf("2");
		}
		else if(( (plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre + 1) && plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre + 1)) ||
				  (plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre + 1) && plateau_copie[i + 1][j].nombre == (plateau_copie[i + 2][j].nombre + 1)) ||
				  (plateau_copie[i][j - 2].nombre == (plateau_copie[i][j - 1].nombre + 1) && plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre + 1)) ||
				  (plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre + 1) && plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre + 1)) ||
				  (plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre + 1) && plateau_copie[i][j + 1].couleur == (plateau_copie[i][j + 2].nombre + 1)) ||
				  (plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre - 1) && plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre - 1)) ||
				  (plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre - 1) && plateau_copie[i + 1][j].nombre == (plateau_copie[i + 2][j].nombre - 1)) ||
				  (plateau_copie[i][j - 2].nombre == (plateau_copie[i][j - 1].nombre - 1) && plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre - 1)) ||
				  (plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre - 1) && plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre - 1)) ||
				  (plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre - 1) && plateau_copie[i][j + 1].couleur == (plateau_copie[i][j + 2].nombre - 1)) ) &&
				  ( (plateau_copie[i - 1][j].couleur == plateau_copie[i][j].couleur && plateau_copie[i][j].couleur == plateau_copie[i + 1][j].couleur) ||
				  (plateau_copie[i][j].couleur == plateau_copie[i + 1][j].couleur && plateau_copie[i + 1][j].couleur == plateau_copie[i + 2][j].couleur) ||
				  (plateau_copie[i][j - 2].couleur == plateau_copie[i][j - 1].couleur && plateau_copie[i][j - 1].couleur == plateau_copie[i][j].couleur) ||
				  (plateau_copie[i][j - 1].couleur == plateau_copie[i][j].couleur && plateau_copie[i][j].couleur == plateau_copie[i][j + 1].couleur) ||
				  (plateau_copie[i][j].couleur == plateau_copie[i][j + 1].couleur && plateau_copie[i][j + 1].couleur == plateau_copie[i][j + 2].couleur) ) )
		{
			//printf("3");
		}
		else
		{
			rep = 0;
			//printf("X");
		}
	}
	
	for(j = 2; j < 210; j ++){
		i = 210;
		if (plateau_copie[i][j].couleur == vide || (plateau_copie[i][j].couleur == plateau[i][j].couleur && plateau_copie[i][j].nombre == plateau[i][j].nombre))
		{
			//printf("_");
		}
		else if( (plateau_copie[i - 2][j].nombre == plateau_copie[i - 1][j].nombre && plateau_copie[i - 1][j].nombre == plateau_copie[i][j].nombre) ||
				  (plateau_copie[i - 1][j].nombre == plateau_copie[i][j].nombre && plateau_copie[i][j].nombre == plateau_copie[i + 1][j].nombre) ||
				  (plateau_copie[i][j - 2].nombre == plateau_copie[i][j - 1].nombre && plateau_copie[i][j - 1].nombre == plateau_copie[i][j].nombre) ||
				  (plateau_copie[i][j - 1].nombre == plateau_copie[i][j].nombre && plateau_copie[i][j].nombre == plateau_copie[i][j + 1].nombre) ||
				  (plateau_copie[i][j].nombre == plateau_copie[i][j + 1].nombre && plateau_copie[i][j + 1].couleur == plateau_copie[i][j + 2].nombre) )
		{
			//printf("2");
		}
		else if(((plateau_copie[i - 2][j].nombre == (plateau_copie[i - 1][j].nombre + 1) && plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre + 1)) ||
				  (plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre + 1) && plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre + 1)) ||
				  (plateau_copie[i][j - 2].nombre == (plateau_copie[i][j - 1].nombre + 1) && plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre + 1)) ||
				  (plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre + 1) && plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre + 1)) ||
				  (plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre + 1) && plateau_copie[i][j + 1].couleur == (plateau_copie[i][j + 2].nombre + 1)) ||
				  (plateau_copie[i - 2][j].nombre == (plateau_copie[i - 1][j].nombre - 1) && plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre - 1)) ||
				  (plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre - 1) && plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre - 1)) ||
				  (plateau_copie[i][j - 2].nombre == (plateau_copie[i][j - 1].nombre - 1) && plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre - 1)) ||
				  (plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre - 1) && plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre - 1)) ||
				  (plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre - 1) && plateau_copie[i][j + 1].couleur == (plateau_copie[i][j + 2].nombre - 1)) ) &&
				  ( (plateau_copie[i - 2][j].couleur == plateau_copie[i - 1][j].couleur && plateau_copie[i - 1][j].couleur == plateau_copie[i][j].couleur) ||
				  (plateau_copie[i - 1][j].couleur == plateau_copie[i][j].couleur && plateau_copie[i][j].couleur == plateau_copie[i + 1][j].couleur) ||
				  (plateau_copie[i][j - 2].couleur == plateau_copie[i][j - 1].couleur && plateau_copie[i][j - 1].couleur == plateau_copie[i][j].couleur) ||
				  (plateau_copie[i][j - 1].couleur == plateau_copie[i][j].couleur && plateau_copie[i][j].couleur == plateau_copie[i][j + 1].couleur) ||
				  (plateau_copie[i][j].couleur == plateau_copie[i][j + 1].couleur && plateau_copie[i][j + 1].couleur == plateau_copie[i][j + 2].couleur) ))
		{
			//printf("3");
		}
		else
		{
			rep = 0;
			//printf("X");
		}
	}
	
	for(i = 2; i < 210; i ++){
		j = 210;
		if (plateau_copie[i][j].couleur == vide || (plateau_copie[i][j].couleur == plateau[i][j].couleur && plateau_copie[i][j].nombre == plateau[i][j].nombre))
		{
			//printf("_");
		}
		else if( (plateau_copie[i - 2][j].nombre == plateau_copie[i - 1][j].nombre && plateau_copie[i - 1][j].nombre == plateau_copie[i][j].nombre) ||
				  (plateau_copie[i - 1][j].nombre == plateau_copie[i][j].nombre && plateau_copie[i][j].nombre == plateau_copie[i + 1][j].nombre) ||
				  (plateau_copie[i][j].nombre == plateau_copie[i + 1][j].nombre && plateau_copie[i + 1][j].nombre == plateau_copie[i + 2][j].nombre) ||
				  (plateau_copie[i][j - 2].nombre == plateau_copie[i][j - 1].nombre && plateau_copie[i][j - 1].nombre == plateau_copie[i][j].nombre) ||
				  (plateau_copie[i][j - 1].nombre == plateau_copie[i][j].nombre && plateau_copie[i][j].nombre == plateau_copie[i][j + 1].nombre) )
		{
			//printf("2");
		}
		else if(((plateau_copie[i - 2][j].nombre == (plateau_copie[i - 1][j].nombre + 1) && plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre + 1)) ||
				  (plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre + 1) && plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre + 1)) ||
				  (plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre + 1) && plateau_copie[i + 1][j].nombre == (plateau_copie[i + 2][j].nombre + 1)) ||
				  (plateau_copie[i][j - 2].nombre == (plateau_copie[i][j - 1].nombre + 1) && plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre + 1)) ||
				  (plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre + 1) && plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre + 1)) ||
				  (plateau_copie[i - 2][j].nombre == (plateau_copie[i - 1][j].nombre - 1) && plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre - 1)) ||
				  (plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre - 1) && plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre - 1)) ||
				  (plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre - 1) && plateau_copie[i + 1][j].nombre == (plateau_copie[i + 2][j].nombre - 1)) ||
				  (plateau_copie[i][j - 2].nombre == (plateau_copie[i][j - 1].nombre - 1) && plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre - 1)) ||
				  (plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre - 1) && plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre - 1)) ) && ( (plateau_copie[i - 2][j].couleur == plateau_copie[i - 1][j].couleur && plateau_copie[i - 1][j].couleur == plateau_copie[i][j].couleur) ||
				  (plateau_copie[i - 1][j].couleur == plateau_copie[i][j].couleur && plateau_copie[i][j].couleur == plateau_copie[i + 1][j].couleur) ||
				  (plateau_copie[i][j].couleur == plateau_copie[i + 1][j].couleur && plateau_copie[i + 1][j].couleur == plateau_copie[i + 2][j].couleur) ||
				  (plateau_copie[i][j - 2].couleur == plateau_copie[i][j - 1].couleur && plateau_copie[i][j - 1].couleur == plateau_copie[i][j].couleur) ||
				  (plateau_copie[i][j - 1].couleur == plateau_copie[i][j].couleur && plateau_copie[i][j].couleur == plateau_copie[i][j + 1].couleur) ))
		{
			//printf("3");
		}
		else
		{
			rep = 0;
			//printf("X");
		}
	}
	
	for(i = 2; i < 210; i ++){
		j = 1;
		if (plateau_copie[i][j].couleur == vide || (plateau_copie[i][j].couleur == plateau[i][j].couleur && plateau_copie[i][j].nombre == plateau[i][j].nombre))
		{
			//printf("_");
		}
		else if( (plateau_copie[i - 2][j].nombre == plateau_copie[i - 1][j].nombre && plateau_copie[i - 1][j].nombre == plateau_copie[i][j].nombre) ||
				  (plateau_copie[i - 1][j].nombre == plateau_copie[i][j].nombre && plateau_copie[i][j].nombre == plateau_copie[i + 1][j].nombre) ||
				  (plateau_copie[i][j].nombre == plateau_copie[i + 1][j].nombre && plateau_copie[i + 1][j].nombre == plateau_copie[i + 2][j].nombre) ||
				  (plateau_copie[i][j - 1].nombre == plateau_copie[i][j].nombre && plateau_copie[i][j].nombre == plateau_copie[i][j + 1].nombre) ||
				  (plateau_copie[i][j].nombre == plateau_copie[i][j + 1].nombre && plateau_copie[i][j + 1].couleur == plateau_copie[i][j + 2].nombre) )
		{
			//printf("2");
		}
		else if(((plateau_copie[i - 2][j].nombre == (plateau_copie[i - 1][j].nombre + 1) && plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre + 1)) ||
				  (plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre + 1) && plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre + 1)) ||
				  (plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre + 1) && plateau_copie[i + 1][j].nombre == (plateau_copie[i + 2][j].nombre + 1)) ||
				  (plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre + 1) && plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre + 1)) ||
				  (plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre + 1) && plateau_copie[i][j + 1].couleur == (plateau_copie[i][j + 2].nombre + 1)) ||
				  (plateau_copie[i - 2][j].nombre == (plateau_copie[i - 1][j].nombre - 1) && plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre - 1)) ||
				  (plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre - 1) && plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre - 1)) ||
				  (plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre - 1) && plateau_copie[i + 1][j].nombre == (plateau_copie[i + 2][j].nombre - 1)) ||
				  (plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre - 1) && plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre - 1)) ||
				  (plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre - 1) && plateau_copie[i][j + 1].couleur == (plateau_copie[i][j + 2].nombre - 1)) ) &&
				  ( (plateau_copie[i - 2][j].couleur == plateau_copie[i - 1][j].couleur && plateau_copie[i - 1][j].couleur == plateau_copie[i][j].couleur) ||
				  (plateau_copie[i - 1][j].couleur == plateau_copie[i][j].couleur && plateau_copie[i][j].couleur == plateau_copie[i + 1][j].couleur) ||
				  (plateau_copie[i][j].couleur == plateau_copie[i + 1][j].couleur && plateau_copie[i + 1][j].couleur == plateau_copie[i + 2][j].couleur) ||
				  (plateau_copie[i][j - 1].couleur == plateau_copie[i][j].couleur && plateau_copie[i][j].couleur == plateau_copie[i][j + 1].couleur) ||
				  (plateau_copie[i][j].couleur == plateau_copie[i][j + 1].couleur && plateau_copie[i][j + 1].couleur == plateau_copie[i][j + 2].couleur) ) )
		{
			//printf("3");
		}
		else
		{
			rep = 0;
			//printf("X");
		}
	}
	
	i = 0;
	j = 0;
	if (plateau_copie[i][j].couleur == vide || (plateau_copie[i][j].couleur == plateau[i][j].couleur && plateau_copie[i][j].nombre == plateau[i][j].nombre))
	{
		//printf("_");
	}
	else if(  (plateau_copie[i - 1][j].nombre == plateau_copie[i][j].nombre && plateau_copie[i][j].nombre == plateau_copie[i + 1][j].nombre) ||
			  (plateau_copie[i][j].nombre == plateau_copie[i + 1][j].nombre && plateau_copie[i + 1][j].nombre == plateau_copie[i + 2][j].nombre) ||
			  (plateau_copie[i][j].nombre == plateau_copie[i][j + 1].nombre && plateau_copie[i][j + 1].couleur == plateau_copie[i][j + 2].nombre) )
	{
		//printf("2");
	}
	else if(((plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre + 1) && plateau_copie[i + 1][j].nombre == (plateau_copie[i + 2][j].nombre + 1)) ||
			 (plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre + 1) && plateau_copie[i][j + 1].couleur == (plateau_copie[i][j + 2].nombre + 1)) ||
			 (plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre - 1) && plateau_copie[i + 1][j].nombre == (plateau_copie[i + 2][j].nombre - 1)) ||
			 (plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre - 1) && plateau_copie[i][j + 1].couleur == (plateau_copie[i][j + 2].nombre - 1)) ) &&
			  ( (plateau_copie[i][j].couleur == plateau_copie[i + 1][j].couleur && plateau_copie[i + 1][j].couleur == plateau_copie[i + 2][j].couleur) ||
			  (plateau_copie[i][j].couleur == plateau_copie[i][j + 1].couleur && plateau_copie[i][j + 1].couleur == plateau_copie[i][j + 2].couleur) ) )
	{
		//printf("3");
	}
	else
	{
		rep = 0;
		//printf("X");
	}
	
	i = 211;
	j = 211;
	if (plateau_copie[i][j].couleur == vide || (plateau_copie[i][j].couleur == plateau[i][j].couleur && plateau_copie[i][j].nombre == plateau[i][j].nombre))
	{
		//printf("_");
	}
	else if( (plateau_copie[i - 2][j].nombre == plateau_copie[i - 1][j].nombre && plateau_copie[i - 1][j].nombre == plateau_copie[i][j].nombre) ||
			  (plateau_copie[i][j - 2].nombre == plateau_copie[i][j - 1].nombre && plateau_copie[i][j - 1].nombre == plateau_copie[i][j].nombre) )
	{
		//printf("2");
	}
	else if(((plateau_copie[i - 2][j].nombre == (plateau_copie[i - 1][j].nombre + 1) && plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre + 1)) ||
			 (plateau_copie[i][j - 2].nombre == (plateau_copie[i][j - 1].nombre + 1) && plateau_copie[i][j - 1].couleur == (plateau_copie[i][j].nombre + 1)) ||
			 (plateau_copie[i - 2][j].nombre == (plateau_copie[i - 1][j].nombre - 1) && plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre - 1)) ||
			 (plateau_copie[i][j - 2].nombre == (plateau_copie[i][j - 1].nombre - 1) && plateau_copie[i][j - 1].couleur == (plateau_copie[i][j].nombre - 1)) )&&
			 ( (plateau_copie[i - 2][j].couleur == plateau_copie[i - 1][j].couleur && plateau_copie[i - 1][j].couleur == plateau_copie[i][j].couleur) ||
			  (plateau_copie[i][j - 2].couleur == plateau_copie[i][j - 1].couleur && plateau_copie[i][j - 1].couleur == plateau_copie[i][j].couleur) ))
	{
		//printf("3");
	}
	else
	{
		rep = 0;
		//printf("X");
	}
	
	i = 211;
	j = 0;
	if (plateau_copie[i][j].couleur == vide || (plateau_copie[i][j].couleur == plateau[i][j].couleur && plateau_copie[i][j].nombre == plateau[i][j].nombre))
	{
		//printf("_");
	}
	else if( (plateau_copie[i - 2][j].nombre == plateau_copie[i - 1][j].nombre && plateau_copie[i - 1][j].nombre == plateau_copie[i][j].nombre) ||
			 (plateau_copie[i][j].nombre == plateau_copie[i][j + 1].nombre && plateau_copie[i][j + 1].couleur == plateau_copie[i][j + 2].nombre) )
	{
		//printf("2");
	}
	else if(((plateau_copie[i - 2][j].nombre == (plateau_copie[i - 1][j].nombre + 1) && plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre + 1)) ||
			 (plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre + 1) && plateau_copie[i][j + 1].couleur == (plateau_copie[i][j + 2].nombre + 1)) ||
			 (plateau_copie[i - 2][j].nombre == (plateau_copie[i - 1][j].nombre - 1) && plateau_copie[i - 1][j].nombre == (plateau_copie[i][j].nombre - 1)) ||
			 (plateau_copie[i][j].nombre == (plateau_copie[i][j + 1].nombre - 1) && plateau_copie[i][j + 1].couleur == (plateau_copie[i][j + 2].nombre - 1)) )&&
			  ( (plateau_copie[i - 2][j].couleur == plateau_copie[i - 1][j].couleur && plateau_copie[i - 1][j].couleur == plateau_copie[i][j].couleur) ||
			  (plateau_copie[i][j].couleur == plateau_copie[i][j + 1].couleur && plateau_copie[i][j + 1].couleur == plateau_copie[i][j + 2].couleur) ))
	{
		//printf("3");
	}
	else
	{
		rep = 0;
		//printf("X");
	}
	
	i = 0;
	j = 211;
	if (plateau_copie[i][j].couleur == vide || (plateau_copie[i][j].couleur == plateau[i][j].couleur && plateau_copie[i][j].nombre == plateau[i][j].nombre))
	{
		//printf("_");
	}
	else if( (plateau_copie[i][j].nombre == plateau_copie[i + 1][j].nombre && plateau_copie[i + 1][j].nombre == plateau_copie[i + 2][j].nombre) ||
			 (plateau_copie[i][j - 2].nombre == plateau_copie[i][j - 1].nombre && plateau_copie[i][j - 1].nombre == plateau_copie[i][j].nombre) )
	{
		//printf("2");
	}
	else if( ((plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre + 1) && plateau_copie[i + 1][j].nombre == (plateau_copie[i + 2][j].nombre + 1)) ||
			 (plateau_copie[i][j - 2].nombre == (plateau_copie[i][j - 1].nombre + 1) && plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre +1)) ||
			 (plateau_copie[i][j].nombre == (plateau_copie[i + 1][j].nombre - 1) && plateau_copie[i + 1][j].nombre == (plateau_copie[i + 2][j].nombre - 1)) ||
			 (plateau_copie[i][j - 2].nombre == (plateau_copie[i][j - 1].nombre - 1) && plateau_copie[i][j - 1].nombre == (plateau_copie[i][j].nombre - 1)) ) &&
			 ( (plateau_copie[i][j].couleur == plateau_copie[i + 1][j].couleur && plateau_copie[i + 1][j].couleur == plateau_copie[i + 2][j].couleur) ||
			  (plateau_copie[i][j - 2].couleur == plateau_copie[i][j - 1].couleur && plateau_copie[i][j - 1].couleur == plateau_copie[i][j].couleur) ))
	{
		//printf("3");
	}
	else
	{
		rep = 0;
		//printf("X");
	}
	for(i = 2; i < 210; i ++){
		for(j = 2; j < 210; j ++){
			total = total + plateau_copie[i][j].nombre;
		}
	}
	if (premierCoup && total < 30)
	{
		rep = 0;
	}
	
	return rep;
		
}

int main(int argc, char *argv[])
{
	int nombre;
	int premierCoup = 1;
	int decallageX = 43 * 106 - (1080 / 2);
	int decallageY = 50 * 106 - (800 / 2);
    char user[30];
	printf ("Entrer le nombre de joueur (entre 2 et 4): ");
	scanf("%d", &nombre);
	PLAYER joueurs[nombre];

    for (int i = 0; i < nombre; i++) {
        printf ("Entrer le pseudo du joueur %d\n", i+1);
        scanf("%s", &user);
        strcpy(joueurs[i].pseudo , user);
    }
    for (int j = 0; j < nombre; j++) {
        printf ("Pseudo du joueur : %s\n ", joueurs[j].pseudo);
    }
    
    
	srand(time(NULL));
    SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Surface *ecran = NULL;
    SDL_Surface *ArrierePlan = NULL;
    SDL_Rect positionArriere_plan;
    SDL_Rect positionCarte;
    SDL_Event event;
    
    SDL_WM_SetIcon(SDL_LoadBMP("sdl_icone.bmp"), NULL);
    ecran = SDL_SetVideoMode(1080, 800, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("RUMIKUBE", NULL);
    
    
	TUILE tuiles[106];

    
    TUILE plateau [212][212];
    TUILE plateau_copie [212][212];
	int i = 0;
	int j = 0;
	int k = 0;
	int score = 0;
	int curseur = 0;
	for(i = 0; i < 212; i ++){
		for(j = 0; j < 212; j ++){
			plateau[i][j].couleur = vide;
			plateau[i][j].nombre = 0;
		}
	}
	
	//les chevalets des joueurs
	TUILE joueur[4][2][19];
	TUILE joueurActif[2][19];
	int nbjoueurActif = 0;
	int curseurX = 106;
	int curseurY = 106;
	int curseurchevalet = 0;	
    int continuer = 1;
    int gagner = 1;
  
	choisir_les_tuiles(tuiles);
  
	//Iniatialisation des chevalets des joueurs 
	for(j = 0; j < 4; j ++){
		for(i = 0; i < 19; i ++){
			joueur[j][0][i].nombre = 0;
			joueur[j][0][i].nombre = 0;
			joueur[j][1][i].nombre = 0;
			joueur[j][1][i].nombre = 0;
			joueur[j][0][i].couleur = vide;
			joueur[j][0][i].couleur = vide;
			joueur[j][1][i].couleur = vide;
			joueur[j][1][i].couleur = vide;
		}
	}
    
    distribuer_cartes(nombre,joueur[0],joueur[1],joueur[2],joueur[3], tuiles, &curseur); //On a pris nombre de joueur = 2 (exemple)
    
    positionArriere_plan.x = 0;
    positionArriere_plan.y = 0;
    positionCarte.x = 150;
    positionCarte.y = 586;
	ArrierePlan = SDL_LoadBMP("images/plateau.bmp");
	SDL_BlitSurface(ArrierePlan, NULL, ecran, &positionArriere_plan);
	
	
    for(i = 0; i < 212; i ++){
		for(j = 0; j < 212; j ++){
			plateau_copie[i][j] = plateau[i][j];
		}
	}
	
    for(i = 0; i < 2; i ++){
		for(j = 0; j < 19; j ++){
			joueurActif[i][j] = joueur[0][i][j];
		}
	}
    
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_KEYDOWN:				
				
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						continuer = 0;
						break;
					case SDLK_p:
						piocher(joueur[nbjoueurActif], tuiles, &curseur);
						if (est_coup_valide(plateau, plateau_copie, premierCoup))
						{
							for(i = 0; i < 212; i ++){
								for(j = 0; j < 212; j ++){
									plateau[i][j] = plateau_copie[i][j];
								}
							}
							for(i = 0; i < 2; i ++){
								for(j = 0; j < 19; j ++){
									joueur[nbjoueurActif][i][j] = joueurActif[i][j];
								}
							}
							premierCoup = 0;
						}
						if (nbjoueurActif == (nombre - 1))
						{
							nbjoueurActif = 0;
						}else{
							nbjoueurActif = nbjoueurActif + 1;
						}
						for(i = 0; i < 2; i ++){
							for(j = 0; j < 19; j ++){
								joueurActif[i][j] = joueur[nbjoueurActif][i][j];
							}
						}
						for(i = 0; i < 212; i ++){
							for(j = 0; j < 212; j ++){
								plateau_copie[i][j] = plateau[i][j];
							}
						}
						break;
					case SDLK_s:
						if (curseurY < 212)
						{
							curseurY = curseurY + 1;
						}
						break;
					case SDLK_z:
						if (curseurY > 0)
						{
							curseurY = curseurY - 1;
						}
						break;
					case SDLK_d:
						if (curseurX < 212)
						{
							curseurX = curseurX + 1;
						}
						break;
					case SDLK_q:
						if (curseurX > 0)
						{
							curseurX = curseurX - 1;
						}
						break;
					case SDLK_e:
						if (curseurchevalet < 37)
						{
							curseurchevalet = curseurchevalet + 1;
						}
						break;
					case SDLK_a:
						if (curseurchevalet > 0)
						{
							curseurchevalet = curseurchevalet - 1;
						}
						break;
					case SDLK_UP:
						decallageY = decallageY + 10;
						//printf("testup %d\n", decallageY);
						break;
					case SDLK_DOWN:
						decallageY = decallageY - 10;
						//printf("testdown %d\n", decallageY);
						break;
					case SDLK_LEFT:
						decallageX = decallageX + 10;
						//printf("testleft %d\n", decallageX);
						break;
					case SDLK_RIGHT:
						decallageX = decallageX - 10;
						//printf("testright %d\n", decallageX);
						break;
					case SDLK_RETURN:
						if ( curseurchevalet < 19)
						{
							i = 1;
						}else{
							i = 0;
						}
						deplacer_tuile_du_chevalet_vers_grille(curseurX, curseurY, i, (curseurchevalet % 19), joueurActif, plateau_copie);
						break;
					case SDLK_t:
						//printf("test_triche\n");
						for(i = 0; i < 2; i ++){
							for(j = 0; j < 19; j ++){
								joueurActif[i][j].couleur == vide;
								joueurActif[i][j].nombre == 0;
							}
						}
						for(i = 0; i < 212; i ++){
							for(j = 0; j < 212; j ++){
								plateau[i][j] = plateau_copie[i][j];
							}
						}
						for(i = 0; i < 2; i ++){
							for(j = 0; j < 19; j ++){
								joueur[nbjoueurActif][i][j] = joueurActif[i][j];
							}
						}
						break;
					default:
						break;
				}
				break;
            case SDL_QUIT:
                continuer = 0;
                break;
			}
                
                
		ArrierePlan = SDL_LoadBMP("images/plateau.bmp");
		SDL_BlitSurface(ArrierePlan, NULL, ecran, &positionArriere_plan);
		afficher_plateau (plateau_copie, ecran, decallageX, decallageY);
		afficher_chevalet(joueurActif, ecran);
		dessiner_curseur(curseurX, curseurY, decallageX, decallageY, ecran);
		dessiner_curseur_chevalet(curseurchevalet, decallageX, decallageY, ecran);
		afficher_joueur (ecran, nbjoueurActif + 1);
		
		SDL_Flip(ecran);
		
		gagner = 1;
		for(i = 0; i < 2; i ++){
			for(j = 0; j < 19; j ++){
				if (joueurActif[i][j].couleur != vide)
				{
					gagner = 0;
				}
			}
		}
		if(gagner && est_coup_valide(plateau, plateau_copie, 0) )
		{
			continuer = 0;
			printf ("%s a gagné\n ", joueurs[nbjoueurActif].pseudo);
		}
    }
	
    SDL_FreeSurface(ArrierePlan);
    SDL_FreeSurface(ecran);
	SDL_Quit;
    
    printf ("scores\n");
    for(i = 0; i < nombre; i ++){
		score = 0;
		for(j = 0; j < 2; j ++){
			for(k = 0; k < 19; k ++){
				score = score + joueur[i][j][k].nombre;
			}
		}
		printf ("%s : %d \n ", joueurs[i].pseudo, score);
	}
    
    return 0;
}
