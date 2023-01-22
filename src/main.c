#include "../include/include.h"

int main(void) 
{
 	application app = initSDL() ;
	prepareScene(app) ;
	presentScene(app) ; 
	SDL_Delay(16) ;/* Cette attente sert à limiter notre boucle à environ 62 images par seconde et empêche également l'application de tourner à plein régime et de consommer beaucoup trop de temps du CPU.*/
	SDL_Delay(6000) ;//input() ;
	destroySDL(app);
	return 0 ;
}
