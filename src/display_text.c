#include "../include/include.h"


























int main(int argc, char *argv[])
{
    SDL_Window *fenetre = NULL;
    SDL_Renderer *rendu = NULL;
    SDL_Color blanc = {255, 255, 255, 255};

    if(SDL_Init(SDL_INIT_VIDEO != 0))
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s", SDL_GetError());
        return EXIT_FAILURE;
    }


    fenetre = SDL_CreateWindow("Jeu Rummikub", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              640, 480, SDL_WINDOW_SHOWN);
    if(fenetre == NULL)
    {
        fprintf(stderr, "Erreur de création de la fenêtre: %s", SDL_GetError());
        return EXIT_FAILURE;
    }


    rendu = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    if (rendu == NULL)
    {
        fprintf(stderr, "Erreur de création du rendu : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    /*if (SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255) != 0)
    {
        fprintf(stderr, "Erreur de changement de la couleur du rendu. : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    if (SDL_RenderClear(rendu) != 0)
    {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        return EXIT_FAILURE;
    }*/

    // Initialisation de la SDL_ttf

    if (TTF_Init() != 0)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL_ttf : %s", TTF_GetError());
        return EXIT_FAILURE;
    }

    // Dans cette partie, nous allons charger une police depuis un fichier, 
    // avec une taille de point à 30

    TTF_Font* police = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf", 30);
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
        "Ceci est mon premier test de la librairie SDL_ttf",
        TextColor);

    if (!TextSurface)
    {
        fprintf(stderr, "Erreur de création du rendu du texte : %s", TTF_GetError());
        return EXIT_FAILURE;
    }


    // Création de la surface de destination du texte

    SDL_Rect DstRect;
    DstRect.x = 0;
    DstRect.y = 0;
    DstRect.w = TextSurface->w;
    DstRect.h = TextSurface->h;


    //Affiche toute la surface en 100, 100

    SDL_BlitSurface(TextSurface, NULL, TextSurface, &DstRect);







     
    
    SDL_Delay(5000);
    SDL_RenderPresent(rendu);
    SDL_Delay(5000);


    // Libère notre surface et notre police 

    SDL_FreeSurface(TextSurface);
    TTF_CloseFont(police);

    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}