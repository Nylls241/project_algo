#include "../include/include.h"

/*-------------------------------------------------------------------------------------------------*/
//prepareScene traite la préparation de notre jeu
application prepareScene(application app)
{
	app = initSDL();
	SDL_SetRenderDrawColor(app.rendu, 96, 128, 255, 255);// couleur en arrière plan (ici ça sera bleu )
	SDL_RenderClear(app.rendu);// rafraîchi le rendu sur la fenêtre

	//app.image = SDL_LoadBMP("images/plateau.bmp") ; // charge le plateau dans app.image

/*	if (app.image == NULL) //  On vérifie que l'app.image a été chargé
	{
		detruit(app) ;
		SDL_ErrorQuit("echec chargement app.image \n") ;

	}*/

	return (app) ;
}


/*-------------------------------------------------------------------------------------------------*/
/*presentScene affiche le rendu qui prend un seul paramètre (ici app) . SDL_RenderPresent nous prensente le rendu de notre jeu */

void presentScene(application app )
{
	SDL_RenderPresent(app.rendu);// affiche le rendu sur la fenêtre ...
}
/*-------------------------------------------------------------------------------------------------*/
application dessin_plateau(application app ){
	app = prepareScene(app); //on prend la scène pour dessiner le plateau dessus
	app.image = SDL_LoadBMP("images/plateau.bmp") ;
	app.texture  = SDL_CreateTextureFromSurface(app.rendu , app.image) ;//Création de la app.texture à partir de la surface sur  app.rendu.
	SDL_FreeSurface(app.image) ; // on libère la surface , vu qu'on a déjà chargé l'app.image(surface) dans la app.texture.On en a plus besoin .

	SDL_Rect rectangle ;

	SDL_QueryTexture(app.texture, NULL, NULL,&rectangle.w,&rectangle.h) ; //Charge la app.texture en mémoire avec les dimmensions
	rectangle.x = position_plateau_x;
	rectangle.y = position_plateau_y;


	SDL_RenderCopy(app.rendu, app.texture, NULL,&rectangle); // Colle la app.texture ayant pour cadre (rectangle) sur app.rendu

	return(app) ;

}
/*-------------------------------------------------------------------------------------------------*/



/*-------------------------------------------------------------------------------------------------*/
//dessinons notre chevalet

application dessin_chevalet(application app) {
	app = dessin_plateau(app);//recupérons le plateau pour dessiner deçu

	SDL_Rect r ;
	r.x = position_chevaletx;
	r.y = position_chevalety;
	r.w = largeur_chevalet ;
	r.h = hauteur_chevalet ;
	SDL_RenderDrawRect(app.rendu,&r) ;//le rectangle du chevalet  est dessiné
	//dessinons la ligne du millieu
	SDL_SetRenderDrawColor(app.rendu,96,128,255,255) ; //couleur bleu de la ligne(on la charge)
	SDL_RenderDrawLine(app.rendu,position_chevaletx , position_chevalety + 50 ,position_chevaletx + largeur_chevalet,position_chevalety + 50 ) ;
	//dessinons les 15 colones
	for (int i =0 ; i<15 ; i++){
		SDL_SetRenderDrawColor(app.rendu,96,128,255,255) ;
		SDL_RenderDrawLine(app.rendu,position_chevaletx +(i * 43) , position_chevalety , position_chevaletx +(i *43) , position_chevalety + 100) ;
}
	return (app) ;
}

/*-------------------------------------------------------------------------------------------------*/


//fonction qui permet d'initialiser la réserve
//les tuiles de la même colonne sont donc sur la même ligne

void init_reserve(tuile res[4][14]){
for(int j=0;j<4;j++){
	for(int i=0; i<14;i++){
		tuile t1;
		t1.couleur=j+1;
		t1.valeur=i+1;

		res[j][i]=t1;
	}
}

}

/*-------------------------------------------------------------------------------------------------*/

//affichons les tuiles à était écrite à patir de plusieurs code réuni
application dessin_tuile(application app,int nb ){

	app = dessin_chevalet(app) ; //recupérons le chavalet pour poser les tuiles

	int n ; //pour le numéro de la tuile
	int c ;//pour la couleur
	//int chevalet [30] ; //dimension du chevalet 15 * 2
	tuile reserve[4][14]; // la reserve
	init_reserve(reserve);


	/*-------------------------------------------------------------*/
	//On gère le fait d'afficher les tuiles de manières aléatoires
	for (int i = 0 ; i<nb; i ++){



		n = rand()%14+1; //permet d'obtenir un numéro de tuile
		c = rand()%4+1 ;//permet d'obtenir une couleur de tuile
//tant que la tuile choisie n'est pas dans la réserve on change de tuile
		while(reserve[c-1][n-1].valeur==0){// la valeur d'une tuile est égale à 0 veut signifier que la tuile n'est plus dans la réserve
			n = rand()%14+1; //permet d'obtenir un numéro de tuile
			c = rand()%4+1 ;//permet d'obtenir une couleur de tuile
		}

		tuile t ;
		t.valeur = n ;
		t.couleur = c;

		/*-------------------------------------------------------------*/


//A partir d'ici la tuile qui sera affichée est déjà connue
//on enleve d'abord la tuile de réserve avant de l'afficher
reserve[c-1][n-1].valeur =0;

		if (t.couleur == 3) //tuile_orange
	    {
			switch(t.valeur){
				case 1 :
					app.image = SDL_LoadBMP("images/O_01.bmp");
					break;
				case 2 :
					app.image = SDL_LoadBMP("images/O_02.bmp");
					break;
				case 3 :
					app.image = SDL_LoadBMP("images/O_03.bmp");
					break;
				case 4 :
					app.image = SDL_LoadBMP("images/O_04.bmp");
					break;
				case 5 :
					app.image = SDL_LoadBMP("images/O_05.bmp");
					break;
				case 6 :
					app.image = SDL_LoadBMP("images/O_06.bmp");
					break;
				case 7 :
					app.image = SDL_LoadBMP("images/O_07.bmp");
					break;
				case 8 :
					app.image = SDL_LoadBMP("images/O_08.bmp");
					break;
				case 9 :
					app.image = SDL_LoadBMP("images/O_09.bmp");
					break;
				case 10 :
					app.image = SDL_LoadBMP("images/O_10.bmp");
					break;
				case 11 :
					app.image = SDL_LoadBMP("images/O_11.bmp");
					break;
				case 12 :
					app.image = SDL_LoadBMP("images/O_12.bmp");
					break;
				case 13 :
					app.image = SDL_LoadBMP("images/O_13.bmp");
					break;
				case 14 :
					app.image = SDL_LoadBMP("images/O0.bmp") ;
					break ;
			}
		}
		else if (t.couleur == 1)//tuile_rouge
	    {
			switch(t.valeur){
				case 1 :
					app.image = SDL_LoadBMP("images/r_01.bmp");
					break;
				case 2 :
					app.image = SDL_LoadBMP("images/r_02.bmp");
					break;
				case 3 :
					app.image = SDL_LoadBMP("images/r_03.bmp");
					break;
				case 4 :
					app.image = SDL_LoadBMP("images/r_04.bmp");
					break;
				case 5 :
					app.image = SDL_LoadBMP("images/r_05.bmp");
					break;
				case 6 :
					app.image = SDL_LoadBMP("images/r_06.bmp");
					break;
				case 7 :
					app.image = SDL_LoadBMP("images/r_07.bmp");
					break;
				case 8 :
					app.image = SDL_LoadBMP("images/r_08.bmp");
					break;
				case 9 :
					app.image = SDL_LoadBMP("images/r_09.bmp");
					break;
				case 10 :
					app.image = SDL_LoadBMP("images/r_10.bmp");
					break;
				case 11 :
					app.image = SDL_LoadBMP("images/r_11.bmp");
					break;
				case 12 :
					app.image = SDL_LoadBMP("images/r_12.bmp");
					break;
				case 13 :
					app.image = SDL_LoadBMP("images/r_13.bmp");
					break;
				case 14 :
					app.image = SDL_LoadBMP("images/r0.bmp") ;
					break ;
			}
		}
		else if (t.couleur == 4){// tuile bleu

			switch(t.valeur){
				case 1 :
					app.image = SDL_LoadBMP("images/b_01.bmp");
					break;
				  case 2 :
					app.image = SDL_LoadBMP("images/b_02.bmp");
					break;
				case 3 :
					app.image = SDL_LoadBMP("images/b_03.bmp");
					break;
				case 4 :
					app.image = SDL_LoadBMP("images/b_04.bmp");
					break;
				case 5 :
					app.image = SDL_LoadBMP("images/b_05.bmp");
					break;
				case 6 :
					app.image = SDL_LoadBMP("images/b_06.bmp");
					break;
				case 7 :
					app.image = SDL_LoadBMP("images/b_07.bmp");
					break;
				case 8 :
					app.image = SDL_LoadBMP("images/b_08.bmp");
					break;
				case 9 :
					app.image = SDL_LoadBMP("images/b_09.bmp");
					break;
				case 10 :
					app.image = SDL_LoadBMP("images/b_10.bmp");
					break;
				case 11 :
					app.image = SDL_LoadBMP("images/b_11.bmp");
					break;
				case 12 :
					app.image = SDL_LoadBMP("images/b_12.bmp");
					break;
				case 13 :
					app.image = SDL_LoadBMP("images/b_13.bmp");
					break;
				case 14 :
					app.image = SDL_LoadBMP("images/b_14.bmp");
					break;
			}
		}
		else if (t.couleur == 2)//tuile verte
	    {
			switch(t.valeur){
				case 1 :
					app.image = SDL_LoadBMP("images/g_01.bmp");
					break;
				case 2 :
					app.image = SDL_LoadBMP("images/g_02.bmp");
					break;
				case 3 :
					app.image = SDL_LoadBMP("images/g_03.bmp");
					break;
				case 4 :
					app.image = SDL_LoadBMP("images/g_04.bmp");
					break;
				case 5 :
					app.image = SDL_LoadBMP("images/g_05.bmp");
					break;
				case 6 :
					app.image = SDL_LoadBMP("images/g_06.bmp");
					break;
				case 7 :
					app.image = SDL_LoadBMP("images/g_07.bmp");
					break;
				case 8 :
					app.image = SDL_LoadBMP("images/g_08.bmp");
					break;
				case 9 :
					app.image = SDL_LoadBMP("images/g_09.bmp");
					break;
				case 10 :
					app.image = SDL_LoadBMP("images/g_10.bmp");
					break;
				case 11 :
					app.image = SDL_LoadBMP("images/g_11.bmp");
					break;
				case 12 :
					app.image = SDL_LoadBMP("images/g_12.bmp");
					break;
				case 13 :
					app.image = SDL_LoadBMP("images/g_13.bmp");
					break;
				case 14 :
					app.image = SDL_LoadBMP("image/g0.bmp") ;
			}
		}

		/*--------------------------------------------------------------*/


	/*--------------------------------------------------------------*/

		app.texture  = SDL_CreateTextureFromSurface(app.rendu , app.image) ;//Création de la app.texture à partir de la surface sur  app.image.

		SDL_Rect rectangle ; //création du rectangle qui nous servira à positionner les tuiles aux bon endroit

		SDL_FreeSurface(app.image) ; // on libère la surface , vu qu'on a déjà chargé l'app.image(surface) dans la app.texture.On en a plus besoin .

		SDL_QueryTexture(app.texture, NULL, NULL,&rectangle.w,&rectangle.h) ; //Charge la app.texture en mémoire avec les dimmensions

		//position tuiles, le switch sert à positionner une tuile à la position i
		if(i<15){ //si i est est  inferieur à 15 on est sur la première ligne donc la position y du chevalet ne change pas et on place la tuile à la case i
			rectangle.x = position_chevaletx+i*largeur_tuile;
			rectangle.y = position_chevalety;
		}else{//si i est est  supérieur à 15 on est sur la seconde ligne donc la position y du chevalet ne change pas et on place la tuile à la case i
			rectangle.x = position_chevaletx+(i-15)*largeur_tuile;
			rectangle.y = position_chevalety+hauteur_tuile;
		}

		//là

	/*------------------------------------------------------------------------------------*/
		SDL_RenderCopy(app.rendu, app.texture, NULL,&rectangle); // Colle la app.texture ayant pour cadre (rectangle) sur app.rendu
	}
        return app;

}

/*-------------------------------------------------------------------------------------------------*/




// Rediger par Nylls Gersan BOUTOTO, Belinda AWUDZA et Guillaume FROMENT
