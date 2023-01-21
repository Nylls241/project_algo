#include "../include/include.h"

/*-------------------------------------------------------------------------------------------------*/
/*prepareScene traite la préparation du rendu,on configure la couleur du rendu avec SDL_SetRenderDrawColor.cette fonction prend 5 paramètre : le pointer qu'on a créé dans init.c et le taux de couleur pour former une couleur (dans notre 96,128,et 255 pour former le bleu :) et 255 pour opaque */
void prepareScene(application app)
{
	SDL_SetRenderDrawColor(app.rendu, 96, 128, 255, 255);
	SDL_RenderClear(app.rendu);// rafraîchi le rendu sur la fenêtre 
	application app = dessine_plateau(app) ;
}
/**/
application dessine_plateau(application app)  
{
	SDL_Texture *texture = NULL ; 

	if (app.image == NULL) //  On vérifie que l'app.image a été chargé
	{
		detruit(app) ; 
		SDL_ErrorQuit("echec chargement app.image \n") ;

	}

	texture = SDL_CreateTextureFromSurface(app.rendu , app.image) ;//Création de la texture à partir de la surface sur  app.rendu.
	
	SDL_FreeSurface(app.image) ; // on libère la surface , vu qu'on a déjà chargé l'app.image(surface) dans la texture.On en a plus besoin .

	if (texture == NULL)//On vérifie que la texture a bien été crée 
	{
		detruit(app) ;
                SDL_ErrorQuit("echec chargement texture \n") ;
	}

	SDL_Rect rectangle ; //On créé le rectangle qui servira de cadre pour notre texture .

	SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) ; //Charge la texture en mémoire avec les dimmensions(wigth, hight) 

	rectangle.x = 0 ;//positon en x de la texture sur la fenêtre 
	rectangle.y = 0 ;//Position en y de la texture sur la fenêtre


	SDL_RenderCopy(app.rendu, texture, NULL, &rectangle); // Colle la texture ayant pour cadre (rectangle) sur app.rendu 

	return (app) ; 
}


/*-------------------------------------------------------------------------------------------------*/
/*presentScene affiche le rendu qui prend un seul paramètre (ici app) . SDL_RenderPresent nous prensente le rendu */

void presentScene(application app )
{
	SDL_RenderPresent(app.rendu);// affiche le rendu sur la fenêtre ... 
}
/*-------------------------------------------------------------------------------------------------*/

// Rediger par Nylls Gersan BOUTOTO
