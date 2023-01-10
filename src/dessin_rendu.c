#include "../include/include.h"

/*-------------------------------------------------------------------------------------------------*/
/*prepareScene traite la préparation du rendu,on configure la couleur du rendu avec SDL_SetRenderDrawColor.cette fonction prend 5 paramètre : le pointer qu'on a créé dans init.c et le taux de couleur pour former une couleur (dans notre 96,128,et 255 pour former le bleu :) et 255 pour opaque */
 void prepareScene(application app)
{
	SDL_SetRenderDrawColor(app.rendu, 96, 128, 255, 255);
	SDL_RenderClear(app.rendu);// rafraîchi le rendu sur la fenêtre 
	
}
void construit(dessin des ,int x, int y,application app)
{
	des.image = NULL ;
	des.texture = NULL ;

	image = IMG_Load("../image/plateau.bmp");
	
	if (image == NULL) 
	{
		Detruit(app) ; 
		SDL_ErrorQuit("echec chargement image \n") ;

	}
	des.texture = SDL_CreateTextureFromSurface(app.rendu , des.image) ;

	if (texture == NULL)
	{
		Detruit(app) ;
                SDL_ErrorQuit("echec chargement image \n") ;
	}

	SDL_Rect rectangle ;

	rectangle.x = x;
	rectangle.y = y;
	SDL_QueryTexture(des.texture, NULL, NULL, &rectangle.w, &rectangle) ;

	SDL_RenderCopy(app.renderer, des.texture, NULL, &rectangle);
}
/*-------------------------------------------------------------------------------------------------*/
/*presentScene affiche le rendu qui prend un seul paramètre (ici app) . SDL_RenderPresent nous prensente le rendu */

void presentScene(application app )
{
	SDL_RenderPresent(app.rendu);
}
/*-------------------------------------------------------------------------------------------------*/

// Rediger par Nylls Gersan BOUTOTO
