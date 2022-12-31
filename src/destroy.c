#include "../include/include.h"

void destroySDL(application app)
{
        SDL_DestroyRenderer(app.rendu) ; // Detruit le rendu 

        SDL_DestroyWindow(app.fenetre) ; //Detruit la fenêtre 

        SDL_Quit() ; // Quitte la SDL

}

