#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"


int SDL_ErrorQuit(const char *message) ; 

int main (void) 
	
{
	SDL_Window *window = NULL ; 

	if(SDL_Init(SDL_INIT_VIDEO) != 0) //Initialisation de la SDL... 
		
		SDL_ErrorQuit(" initialisation de la SDL") ;
	
	// Exécution du programme 
	/*----------------------------------------------------------------------------------*/
	
	window = SDL_CreateWindow("Première fenetre SDL " ,SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED ,800,600,0) ;
	if (window == NULL)
		SDL_ErrorQuit("création de la fenêtre\n") ;
		


	SDL_Delay(6000) ;// 6 secondes d'affichages









	/*-----------------------------------------------------------------------------------*/
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
