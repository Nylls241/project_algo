#include "../include/include.h"

/*-------------------------------------------------------------------------------------------------*/
/*prepareScene traite la préparation du rendu,on configure la couleur du rendu avec SDL_SetRenderDrawColor.cette fonction prend 5 paramètre : le pointer qu'on a créé dans init.c et le taux de couleur pour former une couleur (dans notre 96,128,et 255 pour former le bleu :) et 255 pour opaque */
 void prepareScene(application app)
{
	SDL_SetRenderDrawColor(app.rendu, 96, 128, 255, 255);
	SDL_RenderClear(app.rendu);// rafraîchi le rendu sur la fenêtre 
	
}
/*-------------------------------------------------------------------------------------------------*/
/*presentScene affiche le rendu qui prend un seul paramètre (ici app) . SDL_RenderPresent nous prensente le rendu */

void presentScene(application app )
{
	SDL_RenderPresent(app.rendu);
}
/*-------------------------------------------------------------------------------------------------*/

// Rediger par Nylls Gersan BOUTOTO
