#include "SDL.h"
#include <stdio.h>  

void SDL_ExitWithError(const char *message);

int main(int argc, char **argv)
{
	/*SDL_version nb;
	SDL_VERSION(&nb);
	printf("Bienvenue sur la SDL %d.%d.%d !\n", nb.major, nb.minor, nb.patch );*/

	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("Erruer d'initialisation de la SDL > %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}


	// Création de la fênêtre
	window = SDL_CreateWindow("Première fênêtre SDL",                             // Titre de la fenetre
														SDL_WINDOWPOS_CENTERED,   //abscisse (x)
														SDL_WINDOWPOS_CENTERED,   // ordonnee (y)
														800, 600,                 // largeur et hauteur de la fénétre en pixels
														SDL_WINDOW_SHOWN          //Drapeau : on peut aussi mettre 0 par défaut        
														); 

	if (window == NULL)
	{
		SDL_ExitWithError("Erreur : Création de la fênêtre échouée!");
		
	}

	// Création du rendu
	renderer = SDL_CreateRenderer(window,                             // Fênêtre dans laquelle on met le rendu
								  -1,                                 //Pour gérer le driver de l'affichage
								  SDL_RENDERER_SOFTWARE               // Rendu logiciel        
								  ); 


	if (renderer == NULL)
	{
		SDL_ExitWithError("Erreur : Création du rendu échouée!");
		
	}

	SDL_RenderPresent(renderer);
	if(SDL_RenderClear(renderer) != 0)    //Qui affiche le rendu de notre fênêtre : il renvoie 0 si elle réussit et une valeur négative sinon
	{
		SDL_ExitWithError("Erreur : Effacement du rendu échoué!");
	}  






	
/*--------------------------------------------------------------------*/
	SDL_Delay(5000); //Pour maintenir la fênêtre pendant 5 secondes
/*--------------------------------------------------------------------*/

	SDL_DestroyRenderer(renderer); //Pour détruire le rendu
	SDL_DestroyWindow(window);     //Pour détruire la fênêtre
    SDL_Quit();

	return EXIT_SUCCESS; //return 0;
}

void SDL_ExitWithError(const char *message)
{
	SDL_Log("Erreur : %s > %s\n", message, SDL_GetError);
	SDL_Quit();
	exit(EXIT_FAILURE);
}
