#include "../include/include.h"

/*-------------------------------------------------------------------------------------------------*/
/*prepareScene traite la préparation du rendu,on configure la couleur du rendu avec SDL_SetRenderDrawColor.cette fonction prend 5 paramètre : le pointer qu'on a créé dans init.c et le taux de couleur pour former une couleur (dans notre 96,128,et 255 pour former le bleu :) et 255 pour opaque */
 void prepareScene(application app)
{
	SDL_SetRenderDrawColor(app.rendu, 96, 128, 255, 255);
	SDL_RenderClear(app.rendu);// rafraîchi le rendu sur la fenêtre 
	

}

	}


void CreeTexture(application app ) // image = IMG_Load(source) 
{
	SDL_Texture *texture = NULL ; 
	SDL_Surface *image = NULL ; 

	image = SDL_LoadBMP("../image/plateau.bmp") ;

	if (image == NULL) // Gestion d'erreur 
	{
		detruit(app) ; 
		SDL_ErrorQuit("echec chargement image \n") ;

	}

	texture = SDL_CreateTextureFromSurface(app.rendu , image) ;//Création de la texture à partir de la surface .
	
	SDL_FreeSurface(image) ; 

	if (texture == NULL)// Gestion d'erreur 
	{
		detruit(app) ;
                SDL_ErrorQuit("echec chargement texture \n") ;
	}

	SDL_Rect rectangle ; 
	rectangle.x = 0 :
	rectangle.y = 0 ;

	SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) ; //Charge la texture avec les dimmensions(wigth, hight) 

	SDL_RenderCopy(app.rendu, texture, NULL, &rectangle); // Colle la texture ayant pour cadre (rectangle) sur le rendu 

}
/**/
/*-------------------------------------------------------------------------------------------------*/
/*presentScene affiche le rendu qui prend un seul paramètre (ici app) . SDL_RenderPresent nous prensente le rendu */

void presentScene(application app )
{
	SDL_RenderPresent(app.rendu);// affiche le rendu sur la fenêtre ... 
}
/*-------------------------------------------------------------------------------------------------*/

// Rediger par Nylls Gersan BOUTOTO
