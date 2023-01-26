#include "../include/include.h"

application display_text()
{

	application app;
	app.fenetre = NULL;
	app.rendu = NULL;


	// Initialisation de la SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Erreur lors de l'initialisation de la SDL : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}


	//Initialisation de SDL_ttf

	if (TTF_Init() != 0)
	{
		printf("Erreur lors de l'initialisation de SDL_ttf%s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}


	// Chargement de la police

	TTF_Font* police = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf", 20);
	if (police == NULL)
	{
		printf("Erreur lors du chargement de la police. %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}



	// Création de la fenêtre


	app.fenetre = SDL_CreateWindow("Partie de *RUMMIKUB*",                        // Titre de la fenetre
														SDL_WINDOWPOS_CENTERED,   //Abscisse (x)
														SDL_WINDOWPOS_CENTERED,   // Ordonnée (y)
														400, 300,                 // Largeur et hauteur de la fenêtre en pixels
														SDL_WINDOW_SHOWN );       // Drapeau : on peut aussi mettre 0 par défaut



	// Création du rendu

	app.rendu = SDL_CreateRenderer(app.fenetre,                       // Fenêtre dans laquelle on met le rendu
								  -1,                                 //Pour gérer le driver de l'affichage
								  SDL_RENDERER_SOFTWARE);               // Rendu logiciel



	// Initialisation de la couleur du texte
	SDL_Color text_color = {255, 0, 0, 0}    // Nous avons choisi ici la couleur rouge pour afficher la couleur du texte de notre jeu.



	// Texte à afficher

	char* text[] = "Bienvenue sur le jeu *RUMMIKUB*"



	// Création de la surface contenant le texte

	SDL_Surface* surface = TTF_RenderText_Blended(police, text, text_color);
	if (surface == NULL)
	{
		printf("Erreur lors de la création de la surface. %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}



	// Création de la texture à partir de la surface

	SDL_Texture* texture = SDL_CreateTextureFromSurface(app.rendu, surface);
	if (texture == NULL)
	{
		printf("Erreur lors de la création de la texture. %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}



	// Positions et dimensions de la texture

	SDL_Rect rectangle = {100,100,surface->w,surface->h};



	// Ici nous entrerons dans la boucle principale;
	//Nous éffectuerons notement la la gestion des différents évènements pouvant se produire dans cette partie.

	bool exit

	while(!exit)
	{
		// Commençons par la gestion des évènements.

		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				true = exit;
			}
		}

		// Fonction pour éffacer l'écran.

		SDL_RenderClear(app.rendu);


		// Affichage du texte : ici nous introduisons la fonction pour afficher notre texte à l'écran.

		SDL_RenderCopy(app.rendu, texture, NULL, &rectangle);

		//Mise à jour de l'affichage

		SDL_RenderPresent(app.rendu);

	}



	// Libérqtion des ressources.

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	TTF_CloseFont(police);
	SDL_DestroyRenderer(app.rendu);
	SDL_DestroyWindow(app.fenetre);
	TTF_Quit();
	SDL_QUIT();





	return 0;
}
