#include "../include/include.h"

int main(void) 
{
	application app = prepareScene( app) ;

	app = creer_texture(app,dessiner_rectangle(position_plateau_x,position_plateau_y,largeur_ecran,hauteur_ecran)) ;

	presentScene(app) ; 

	SDL_Delay(16) ;/* Cette attente sert à limiter notre boucle à environ 62 images par seconde et empêche également l'application de tourner à plein régime et de consommer beaucoup trop de temps du CPU.*/
	input() ;//SDL_Delay(6000) ;//input() ;
	destroySDL(app);
	return 0 ;
}
