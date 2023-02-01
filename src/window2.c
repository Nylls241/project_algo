#include "../include/include.h"

application white_window()
{

    application app;
    app.fenetre = NULL;
    app.rendu = NULL;
    app.image = NULL;
    app.texture = NULL;

    SDL_Init(SDL_INIT_VIDEO); //POUR INITIALISER LA SDL

    TTF_Init(); //pour initialiser la SDL_TTF

   
    TTF_Font* font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf", 20); // la police du texte

    app.fenetre = SDL_CreateWindow("RUMMIKUB",                              // Titre de la fenetre
                                    SDL_WINDOWPOS_CENTERED,                 //abscisse (x)
                                    SDL_WINDOWPOS_CENTERED,                 // ordonnee (y)
                                    500, 300,                               // largeur et hauteur de la fénétre en pixels
                                    SDL_WINDOW_SHOWN );                     //Drapeau : on peut aussi mettre 0 par défaut  



    app.rendu = SDL_CreateRenderer(app.fenetre,                             // Fênêtre dans laquelle on met le rendu
                                  -1,                                       //Pour gérer le driver de l'affichage
                                  SDL_RENDERER_SOFTWARE                     // Rendu logiciel        
                                  );



    SDL_SetRenderDrawColor(app.rendu, 255, 255, 255, 255); // Couleur blanche
    SDL_RenderClear(app.rendu); //Afficher la couleur du rendu

    SDL_Color TextColor;
    TextColor.r = 0;
    TextColor.g = 0;
    TextColor.b = 0;

    // Création de la surface du texte.


    SDL_Surface* TextSurface = TTF_RenderText_Solid(font, "Veuillez saisir votre pseudo", TextColor);

    // Récupération de la surface de la fenêtre

    SDL_Surface* fenetre1 = SDL_GetWindowSurface(app.fenetre); // La surface ou l'on mettra le texte


    // Création de la surface de destination du texte

    SDL_Rect Rect;
    Rect.x = (fenetre1->w - TextSurface->w)/4;
    Rect.y = (fenetre1->h - TextSurface->h)/4;
    Rect.w = TextSurface->w;
    Rect.h = TextSurface->h;


     while (1)  // Pour éviter que la fenetre se ferme
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

      
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_FreeSurface(TextSurface);

   

    return app;
}