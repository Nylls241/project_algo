#include "../include/include.h"

application white_window()
{

	application app;
	app.fenetre = NULL;
	app.rendu = NULL;
	app.image = NULL;
	app.texture = NULL;

	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("Erreur d'initialisation de la SDL > %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	app.fenetre = SDL_CreateWindow("RUMMIKUB",                             // Titre de la fenetre
														SDL_WINDOWPOS_CENTERED,   //abscisse (x)
														SDL_WINDOWPOS_CENTERED,   // ordonnee (y)
														800, 600,                 // largeur et hauteur de la fénétre en pixels
														SDL_WINDOW_SHOWN );         //Drapeau : on peut aussi mettre 0 par défaut  



	app.rendu = SDL_CreateRenderer(app.fenetre,                             // Fênêtre dans laquelle on met le rendu
								  -1,                                 //Pour gérer le driver de l'affichage
								  SDL_RENDERER_SOFTWARE               // Rendu logiciel        
								  );

	/*SDL_Surface* image = SDL_LoadBMP("background.bmp");
    if (image == NULL) {
        printf("Unable to load image! SDL Error: %s\n", SDL_GetError());
        return app;
    }


*/

	/*SDL_SetRenderDrawColor(app.rendu, 255, 255, 255, 255); // 255, 255, 255 désigne la couleur blanche
	SDL_RenderClear(app.rendu);*/

    app.image = SDL_LoadBMP("background.bmp");
    app.texture = SDL_CreateTextureFromSurface(app.rendu, app.image);
    SDL_FreeSurface(app.image);

    SDL_Rect rectangle;
    SDL_QueryTexture(app.texture, NULL, NULL, &rectangle.w, &rectangle.h);
    rectangle.x = 0;
    rectangle.y = 0;


    SDL_RenderCopy(app.rendu, app.texture, NULL, NULL);
    


	
	SDL_RenderPresent(app.rendu);
   
    //SDL_DestroyTexture(app.texture);
	return app;



}
