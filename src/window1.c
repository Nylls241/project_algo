#include "../include/include.h"

application white_window()
{

	application app;
	app.fenetre = NULL;
	app.rendu = NULL;
	app.image = NULL;
	app.texture = NULL;

	if(SDL_Init(SDL_INIT_VIDEO) != 0)  //initialisation de la SDL
	{
		SDL_Log("Erreur d'initialisation de la SDL > %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	TTF_Init();

	// Charger une police
	TTF_Font* font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf", 30);
	app.fenetre = SDL_CreateWindow("RUMMIKUB",                             // Titre de la fenetre
														SDL_WINDOWPOS_CENTERED,   //abscisse (x)
														SDL_WINDOWPOS_CENTERED,   // ordonnee (y)
<<<<<<< HEAD
														1280, 720,                // largeur et hauteur de la fénétre en pixels
														SDL_WINDOW_SHOWN );       //Drapeau : on peut aussi mettre 0 par défaut  
=======
														800, 800,                 // largeur et hauteur de la fénétre en pixels
														SDL_WINDOW_SHOWN );         //Drapeau : on peut aussi mettre 0 par défaut  
>>>>>>> 38d76cabeaff5f202da92043de510ec4f071fe1d



	app.rendu = SDL_CreateRenderer(app.fenetre,               // Fênêtre dans laquelle on met le rendu
								  -1,                         //Pour gérer le driver de l'affichage
								  SDL_RENDERER_SOFTWARE       // Rendu logiciel        
								  );

  	 SDL_Surface* fenetre1 = SDL_GetWindowSurface(app.fenetre);

    app.image = SDL_LoadBMP("background.bmp");
    app.texture = SDL_CreateTextureFromSurface(app.rendu, app.image);

     // Copier l'image sur la surface de la fenêtre
    SDL_BlitSurface(app.image, NULL, fenetre1, NULL);

    SDL_Color TextColor;
    TextColor.r = 227;
    TextColor.g = 128;
    TextColor.b = 125;

    // Création de la surface du texte.
	SDL_Surface* TextSurface = TTF_RenderText_Solid(font, "Bienvenue dans le jeu du RUMMIKUB",TextColor);


<<<<<<< HEAD
    SDL_RenderCopy(app.rendu, app.texture, NULL, NULL);
  
	SDL_RenderPresent(app.rendu);

	 
	return app;
=======
    // Création de la surface de destination du texte
	SDL_Rect Rect;
    Rect.x = (fenetre1->w - TextSurface->w)/4;
    Rect.y = (fenetre1->h - TextSurface->h)/4;
    Rect.w = TextSurface->w;
    Rect.h = TextSurface->h;

     while (1) 
    {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            }
        }
        
       	SDL_BlitSurface(TextSurface, NULL, fenetre1, &Rect);
        SDL_UpdateWindowSurface(app.fenetre);
        SDL_RenderPresent(app.rendu);

    }

      

  //  SDL_RenderCopy(app.rendu, app.texture, NULL, NULL);
	
>>>>>>> 38d76cabeaff5f202da92043de510ec4f071fe1d

	TTF_CloseFont(font);
    TTF_Quit();
         SDL_FreeSurface(app.image);

    SDL_FreeSurface(TextSurface);


    return app;


}
