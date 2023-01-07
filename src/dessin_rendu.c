#include "../include/include.h"

 void prepareScene(application app)
{
	SDL_SetRenderDrawColor(app.rendu, 96, 128, 255, 255);
	//SDL_RenderClear(app.rendu);
	
}

void presentScene(application app )
{
	SDL_RenderPresent(app.rendu);
}
