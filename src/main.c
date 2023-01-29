#include "../include/include.h"

int main(void) 
{
	
	application app = dessin_tuile(app,14);//  on pioche 14 tuile au debut de la partie 

	presentScene(app) ; //le jeu est lancé 

	SDL_Delay(16) ;/* Cette attente sert à limiter notre boucle à environ 62 images par seconde et empêche également l'application de tourner à plein régime et de consommer beaucoup trop de temps du CPU.*/
	input() ; //la fenêtre du jeu est lancé
	destroySDL(app);
	return 0 ;
}
