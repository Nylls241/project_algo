#include "../include/include.h"

application white_window()
{

	application app;
	app.fenetre = NULL;
	app.rendu = NULL;

	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("Erreur d'initialisation de la SDL > %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	app.fenetre = SDL_CreateWindow("Première fênêtre SDL",                             // Titre de la fenetre
														SDL_WINDOWPOS_CENTERED,   //abscisse (x)
														SDL_WINDOWPOS_CENTERED,   // ordonnee (y)
														400, 300,                 // largeur et hauteur de la fénétre en pixels
														SDL_WINDOW_SHOWN );         //Drapeau : on peut aussi mettre 0 par défaut  



	app.rendu = SDL_CreateRenderer(app.fenetre,                             // Fênêtre dans laquelle on met le rendu
								  -1,                                 //Pour gérer le driver de l'affichage
								  SDL_RENDERER_SOFTWARE               // Rendu logiciel        
								  );


	SDL_SetRenderDrawColor(app.rendu, 255, 255, 255, 255); // 255, 255, 255 désigne la couleur blanche
	SDL_RenderClear(app.rendu);
	SDL_RenderPresent(app.rendu);
	return app;



}
