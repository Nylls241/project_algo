#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"


int SDL_ErrorQuit(const char *message) ; 
void SDL_ErrorImage(void) ;

int main (void) 
	
{
	SDL_Surface *image = NULL ;

	SDL_Texture *texture = NULL ;

	SDL_Window *window = NULL ; 

	SDL_Renderer *rendu = NULL ; 

	if(SDL_Init(SDL_INIT_VIDEO) != 0) //Initialisation de la SDL... 
		
		SDL_ErrorQuit(" initialisation de la SDL") ;
	
	// Exécution du programme 
	/*----------------------------------------------------------------------------------*/
	
	window = SDL_CreateWindow("Première fenetre SDL " ,SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED ,800,600,0) ;
	if (window == NULL)
		SDL_ErrorQuit("création de la fenêtre\n") ;
		
	rendu = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE) ;

	if (rendu == NULL) 
		SDL_ErrorQuit("création rendu ") ;

	/*-------------------------------------------------------------------*/

	SDL_RenderPresent(rendu) ;

	image = SDL_BMP("~/Documents/IATIC_3/S1/PROJET/Codes/images/plateau.bmp") ;

	if (image == NULL) 
	{
		SDL_ErrorImage() ; 
		SDL_ErrorQuit("l'image n'est pas chargé") ;
	}
	texture = SDL_CreateTextureFromSurface(rendu , image) ;

	SDL_Delay(6000) ;// 6 secondes d'affichages









	/*-----------------------------------------------------------------------------------*/
	SDL_DestroyRenderer(rendu) ; // Detruit le rendu 

	SDL_DestroyWindow(window); //Detruit la fenêtre 
	
	SDL_Quit() ; // Quitte la SDL

	return 0 ;// Le programme c'est bien passé 
}

int SDL_ErrorQuit(const char *message)
{
	printf("ERREUR : %s ...>>> %s \n" ,message, SDL_GetError()) ; // Gestion d'erreur 
	SDL_Quit() ;
        return ( -1 ) ; //Quitte le programme


}
void SDL_ErrorImage(void) 
{
	SDL_DestroyRenderer(rendu) ; // Detruit le rendu 
	SDL_DestroyWindow(window); //Detruit la fenêtre 
}






