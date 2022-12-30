#include "SDL.h"
#include "structures.h"
#include "init_draw"

void prepareScene(void)
{
	SDL_SetRenderDrawColor(app.rendu, 96, 128, 255, 255);
	SDL_RenderClear(app.rendu);
}

void presentScene(void)
{
	SDL_RenderPresent(app.rendu);
}
