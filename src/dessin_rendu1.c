#include "../include/include.h"

/*-------------------------------------------------------------------------------------------------*/
/*prepareScene traite la préparation du rendu,on configure la couleur du rendu avec SDL_SetRenderDrawColor.cette fonction prend 5 paramètre : le pointer qu'on a créé dans init.c et le taux de couleur pour former une couleur (dans notre 96,128,et 255 pour former le bleu :) et 255 pour opaque */
void prepareScene(application app)
{
	SDL_SetRenderDrawColor(app.rendu, 96, 128, 255, 255);
	SDL_RenderClear(app.rendu);// rafraîchi le rendu sur la fenêtre 

	app.image = SDL_LoadBMP("../images/plateau.bmp") ; 

	if (app.image == NULL) //  On vérifie que l'app.image a été chargé
	{
		detruit(app) ; 
		SDL_ErrorQuit("echec chargement app.image \n") ;

	}

	app.texture = SDL_CreateTextureFromSurface(app.rendu , app.image) ;//Création de la app.texture à partir de la surface sur  app.rendu.
	
	SDL_FreeSurface(app.image) ; // on libère la surface , vu qu'on a déjà chargé l'app.image(surface) dans la app.texture.On en a plus besoin .

	if (app.texture == NULL)//On vérifie que la app.texture a bien été crée 
	{
		detruit(app) ;
                SDL_ErrorQuit("echec chargement app.texture \n") ;
	}

	SDL_Rect rectangle ; //On créé le rectangle qui servira de cadre pour notre app.texture .
	rectangle.x = 0 ;//positon en x de la app.texture sur la fenêtre 
	rectangle.y = 0 ;//Position en y de la app.texture sur la fenêtre
	rectangle.w = largeur_ecran;
	rectangle.h = hauteur_ecran ; 
	if( SDL_RenderDrawRect(app.rendu,&rectangle) != 0 ){

		SDL_ErrorQuit("échec dessin du rectangle\n") ;
	}
							

	SDL_QueryTexture(app.texture, NULL, NULL, &rectangle.w, &rectangle.h) ; //Charge la app.texture en mémoire avec les dimmensions(wigth, hight) 



	SDL_RenderCopy(app.rendu, app.texture, NULL, &rectangle); // Colle la app.texture ayant pour cadre (rectangle) sur app.rendu 

}


/*-------------------------------------------------------------------------------------------------*/
/*presentScene affiche le rendu qui prend un seul paramètre (ici app) . SDL_RenderPresent nous prensente le rendu */

void presentScene(application app )
{
	SDL_RenderPresent(app.rendu);// affiche le rendu sur la fenêtre ... 
}
/*-------------------------------------------------------------------------------------------------*/

// Rediger par Nylls Gersan BOUTOTO
