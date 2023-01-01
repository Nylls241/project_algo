#include <stdio.h>
#include "SDL_image.h"
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
	
	window = SDL_CreateWindow("Première fenetre SDL " ,SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED ,1080,722,0);
	if (window == NULL)
		SDL_ErrorQuit("création de la fenêtre\n") ;
		
	rendu = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE) ;

	if (rendu == NULL) 
		SDL_ErrorQuit("création rendu ") ;

	/*-------------------------------------------------------------------*/

	 SDL_SetRenderDrawColor(rendu , 96 , 128 ,255 ,255) ;
        SDL_Rect rect ;
        rect.x = 0 ;
        rect.y = 0 ;
        rect.w =1080;
        rect.h = 720 ;

        SDL_RenderDrawRect(rendu , &rect) ;
	SDL_RenderPresent(rendu) ;

	image = SDL_LoadBMP("plateau.bmp") ;

	if (image == NULL) 
	{
		SDL_ErrorQuit("l'image n'est pas chargé") ;
	}
	texture = SDL_CreateTextureFromSurface(rendu , image) ;
	SDL_FreeSurface(image) ;
	if (texture == NULL) 
	{
                SDL_ErrorQuit("texture n'est pas chargé") ;
	}
	SDL_QueryTexture(texture, NULL ,NULL ,&rect.w ,&rect.h) ; 
	SDL_RenderCopy(rendu,texture,NULL,&rect);	


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





