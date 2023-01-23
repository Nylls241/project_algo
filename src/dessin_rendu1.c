#include "../include/include.h"

/*-------------------------------------------------------------------------------------------------*/
//prepareScene traite la préparation de notre jeu 
application prepareScene(application app)
{
	app = initSDL();
	SDL_SetRenderDrawColor(app.rendu, 96, 128, 255, 255);// couleur en arrière plan (ici ça sera bleu )
	SDL_RenderClear(app.rendu);// rafraîchi le rendu sur la fenêtre 

	app.image = SDL_LoadBMP("images/plateau.bmp") ; // charge le plateau dans app.image

	if (app.image == NULL) //  On vérifie que l'app.image a été chargé
	{
		detruit(app) ; 
		SDL_ErrorQuit("echec chargement app.image \n") ;

	}

	return (app) ;
}


/*-------------------------------------------------------------------------------------------------*/
/*presentScene affiche le rendu qui prend un seul paramètre (ici app) . SDL_RenderPresent nous prensente le rendu de notre jeu */

void presentScene(application app )
{
	SDL_RenderPresent(app.rendu);// affiche le rendu sur la fenêtre ... 
}
/*-------------------------------------------------------------------------------------------------*/
application creer_texture(application app ,SDL_Rect rectangle){
	

	app.texture  = SDL_CreateTextureFromSurface(app.rendu , app.image) ;//Création de la app.texture à partir de la surface sur  app.rendu.
	SDL_FreeSurface(app.image) ; // on libère la surface , vu qu'on a déjà chargé l'app.image(surface) dans la app.texture.On en a plus besoin .

	SDL_QueryTexture(app.texture, NULL, NULL,&rectangle.w,&rectangle.h) ; //Charge la app.texture en mémoire avec les dimmensions


	SDL_RenderCopy(app.rendu, app.texture, NULL,&rectangle); // Colle la app.texture ayant pour cadre (rectangle) sur app.rendu 

	return(app) ;

}
/*-------------------------------------------------------------------------------------------------*/
//dessine le rectangle
SDL_Rect dessiner_rectangle(int x , int y , int w ,int h){
	SDL_Rect rectangle ;
	rectangle.x = x ;
	rectangle.y = y;
	rectangle.w = w ; 
	rectangle.h = h ;
	
	return (rectangle) ;
}

/*-------------------------------------------------------------------------------------------------*/
//cette fonction sera appélé pour  dessiner les tuiles

void dessin_tuile(application app , tuile t){

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
                                break;
                }
        }
}
                                      

// Rediger par Nylls Gersan BOUTOTO
