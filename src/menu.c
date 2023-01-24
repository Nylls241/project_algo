#include "SDL.h"  
#include <stdio.h>
#include <stdlib.h>

void SDL_ExitWithError(const char *message);

int setWindowColor(SDL_Renderer *renderer, SDL_Color color)
{
    if(SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b) < 0)
        return -1;
    if(SDL_RenderClear(renderer) < 0)
        return -1;
    return 0;  
}

int main(void)
{


	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Color blanc = {255, 255, 255};


    setWindowColor(renderer, blanc); 
   

	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("Erreur d'initialisation de la SDL > %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}


	// Création de la fênêtre
	window = SDL_CreateWindow("Première fênêtre SDL",                             // Titre de la fenetre
														SDL_WINDOWPOS_CENTERED,   //abscisse (x)
														SDL_WINDOWPOS_CENTERED,   // ordonnee (y)
														400, 300,                 // largeur et hauteur de la fénétre en pixels
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

	if(SDL_RenderClear(renderer) != 0)    //Qui affiche le rendu de notre fênêtre : il renvoie 0 si elle réussit et une valeur négative sinon
	{
		SDL_ExitWithError("Erreur : Effacement du rendu échoué!");
	}  
	
/*--------------------------------------------------------------------*/
if (SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE ) != 0) // 255, 255, 255 désigne la couleur blanche, SDL_ALPHA_OPAQUE permet d'afficher la couleur
{
	SDL_ExitWithError("Impossible de changer la couleur pour le rendu!");
}

/*if (SDL_SetRenderDrawPoint(renderer, 100, 150) != 0)
{
	SDL_ExitWithError("Impossible de dessiner un point!");
}
if (SDL_SetRenderDrawPoint(renderer, 50, 50, 200, 200) != 0)
{
	SDL_ExitWithError("Impossible de dessiner une ligne!");
}
if (SDL_SetRenderDrawPoint(renderer, &rectangle) != 0)
{
	SDL_ExitWithError("Impossible de dessiner un rectangle!");
}
SDL_Rect rectangle;
rectangle.x = 200;
rectangle.y = 100;
rectangle.w = 150; // largeur
rectangle.h = 120; // hauteur
*/
	SDL_RenderPresent(renderer);
	SDL_Delay(5000); //Pour maintenir la fênêtre pendant 5 secondes
/*--------------------------------------------------------------------*/

	SDL_DestroyRenderer(renderer); //Pour détruire le rendu
	SDL_DestroyWindow(window);     //Pour détruire la fênêtre
    SDL_Quit();

	return 0; //return 0;
}

void SDL_ExitWithError(const char *message)
{
	SDL_Log("Erreur : %s > %s\n", message, SDL_GetError);
	SDL_Quit();
	exit(EXIT_FAILURE);
} 


