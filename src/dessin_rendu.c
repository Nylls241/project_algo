#include "../include/include.h"

application prepareScene(application app)
{
	SDL_SetRenderDrawColor(app.rendu, 96, 128, 255, 255);
	SDL_RenderClear(app.rendu);
	
	return app;
}

void presentScene(application app)
{
	SDL_RenderPresent(app.rendu);
}
