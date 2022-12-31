#include <stdio.h>
#include <stdlib.h>
#include "init_draw.h"
#include "SDL.h"
#include "defs.h"
#include "structures.h"


/*initSDL Initialise  la SDL , Crée et affiche une fenêtre et enfin  Crée un rendu */

void initSDL(void)
{
	 app.fenetre == NULL ;

         app.rendu = NULL ;

	int renduFlags, fenetreFlags ;//Commente

	renduFlags = SDL_RENDERER_ACCELERATED;//commente

	fenetreFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)//commente
	{
		 SDL_ErrorQuit(" initialisation de la SDL\n") ;//Commente
	}

	app.fenetre = SDL_CreateWindow("RUMMIKUB", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, fenetreFlags);//Commente

	if (app.fentre == NULL)
	{
		 SDL_ErrorQuit("création de la fenêtre\n") ;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");//Commente

	app.rendu = SDL_CreateRenderer(app.fenetre, -1, renduFlags);//Commente

	if (app.rendu == NULL)
	{
		SDL_ErrorQuit("création rendu\n ") ;

	}
}
/*SDL_ErrorQuit affiche un massage d'erreur , puis fait appel à la fonction SDL_GetError pour spécifier l'erreur , ensuite appel la fonction SDL_Quit pour quitter la SDL et enfin renvoie -1 et quitte le programme , cette fonction permet gerer les erreurs d'initialisation */

int SDL_ErrorQuit(const char *message)
{
        printf("ERREUR : %s ...>>> %s \n" ,message, SDL_GetError()) ; // Gestion d'erreur 
        SDL_Quit() ;
        return ( -1 ) ; //Quitte le programme

}

//Rediger par Nylls Gersan BOUTOTO
