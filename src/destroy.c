#include "SDL.h"
#include "init_draw.h"
#include "structures.h"

void destroySDL(void)
{
        SDL_DestroyRenderer(app.rendu) ; // Detruit le rendu 

        SDL_DestroyWindow(app.fenetre) ; //Detruit la fenêtre 

        SDL_Quit() ; // Quitte la SDL

}

