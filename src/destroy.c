#include "../include/include.h"

/* La fonction destroy libère la mémoire propement , pour ne pas avoir des fuites de mémoire */

void destroySDL(application app)
{
        SDL_DestroyRenderer(app.rendu) ; // Detruit le rendu 

        SDL_DestroyWindow(app.fenetre) ; //Detruit la fenêtre 

	SDL_DestroyTexture(app.texture) ; //Detruit la texture 

        SDL_Quit() ; // Quitte la SDL

}
void detruit(application app )
{
        SDL_DestroyRenderer(app.rendu) ;// Detruit le rendu
        SDL_DestroyWindow(app.fenetre) ;// Detruit le fenetre
}


