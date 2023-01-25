#include "../include/include.h"

int main(void) 
{
	
	application app = dessin_chevalet(app);//on a la scène , le plateau , et le chavalet prêt 

/*	chevalet c; //chevalet de test
        c.idJoueur = 0; //id du joueur possédant le chevalet, inutile ici

	initReserve(); // initialise la réserve

	app_che ac;
	ac.app = app;
	ac.che = c;

	ac = pioche(14, ac); 
	app = ac.app ;*/
	presentScene(app) ; 

	SDL_Delay(16) ;/* Cette attente sert à limiter notre boucle à environ 62 images par seconde et empêche également l'application de tourner à plein régime et de consommer beaucoup trop de temps du CPU.*/
	input() ;
	destroySDL(app);
	return 0 ;
}
