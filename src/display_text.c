#include "../include/include.h"








int main(int argc, char *argv[])
{

    SDL_Window *fenetre = NULL;
    SDL_Renderer *rendu = NULL;
    //SDL_Color blanc = {255, 255, 255, 255};

    if(SDL_Init(SDL_INIT_VIDEO != 0))
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Création de la fenêtre

    fenetre = SDL_CreateWindow("Jeu Rummikub", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              640, 480, SDL_WINDOW_SHOWN);
    if(fenetre == NULL)
    {
        fprintf(stderr, "Erreur de création de la fenêtre: %s", SDL_GetError());
        return EXIT_FAILURE;
    }


    // Création du rendu
    rendu = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    if (rendu == NULL)
    {
        fprintf(stderr, "Erreur de création du rendu : %s", SDL_GetError());
        return EXIT_FAILURE;
    }


    // Définition de la couleur du rendu 

    SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);

    if (SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255) != 0)
    {
        fprintf(stderr, "Erreur de changement de la couleur du rendu. : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_RenderClear(rendu);
    if (SDL_RenderClear(rendu) != 0)
    {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Initialisation de la SDL_ttf

    TTF_Init();
    if (TTF_Init() != 0)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL_ttf : %s", TTF_GetError());
        return EXIT_FAILURE;
    }

    // Dans cette partie, nous allons charger une police depuis un fichier, 
    // avec une taille de point à 30

    TTF_Font* police = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf", 15);
    if (!police)
    {
        fprintf(stderr, "Erreur de création de la police : %s", TTF_GetError());
        return EXIT_FAILURE;
    }


    // Couleur du texte, ici nous utiliserons le rouge.

    SDL_Color TextColor;
    TextColor.r = 255;
    TextColor.g = 0;
    TextColor.b = 0;

    // Création de la surface du texte.


    SDL_Surface* TextSurface = TTF_RenderText_Solid(police, 
        "Test de l'affichage de texte sur la SDL2",
        TextColor);

    if (!TextSurface)
    {
        fprintf(stderr, "Erreur de création du rendu du texte : %s", TTF_GetError());
        return EXIT_FAILURE;
    }

    // Récupération de la surface de la fenêtre

    SDL_Surface* fenetre1 = SDL_GetWindowSurface(fenetre);


    // Création de la surface de destination du texte

    SDL_Rect DstRect;
    DstRect.x = (fenetre1->w - TextSurface->w)/4;
    DstRect.y = (fenetre1->h - TextSurface->h)/4;
    DstRect.w = TextSurface->w;
    DstRect.h = TextSurface->h;


    //Affiche toute la surface en 100, 100



    //Mise à  jour de la fenêtre




    while (1) 
    {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            }
        }
        SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
        SDL_RenderClear(rendu);
        SDL_BlitSurface(TextSurface, NULL, fenetre1, &DstRect);
        SDL_UpdateWindowSurface(fenetre);
        SDL_RenderPresent(rendu);
    }

    TTF_CloseFont(police);
    SDL_FreeSurface(TextSurface);
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();

    return EXIT_SUCCESS;
}