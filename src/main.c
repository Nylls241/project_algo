#include "../include/include.h"

int main(void) 
{
	application app = prepareScene( app) ;

	app = dessin_chevalet(app) ;
	presentScene(app) ; 

	SDL_Delay(16) ;/* Cette attente sert à limiter notre boucle à environ 62 images par seconde et empêche également l'application de tourner à plein régime et de consommer beaucoup trop de temps du CPU.*/
	input() ;
	destroySDL(app);
	return 0 ;
}
