#include "../include/include.h"

int main(void) 
{
	application app = prepareScene( app) ;

	app = creer_texture(app,dessiner_rectangle(position_plateau_x,position_plateau_y,largeur_ecran,hauteur_ecran)) ;
	SDL_Rect rectangle ;// le rectangle pour le chevalet
	rectangle.x = 131 ;
	rectangle.y = 620 ;
	rectangle.w = largeur_chevalet ;
	rectangle.h = hauteur_chevalet ;
	if (SDL_RenderDrawRect(app.rendu ,&rectangle) != 0){
		SDL_ErrorQuit("impossible de dessiner le rectangle \n") ;
	}

	presentScene(app) ; 

	SDL_Delay(16) ;/* Cette attente sert à limiter notre boucle à environ 62 images par seconde et empêche également l'application de tourner à plein régime et de consommer beaucoup trop de temps du CPU.*/
	input() ;//SDL_Delay(6000) ;//input() ;
	destroySDL(app);
	return 0 ;
}
