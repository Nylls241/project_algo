#include "../include/include.h"


void texture_to_rect(SDL_Renderer *rendu, SDL_Texture *texture, SDL_Rect *rectangle)
{
    SDL_QueryTexture(texture, NULL, NULL, &(rectangle->w), &(rectangle->h));
    SDL_RenderCopy(rendu, texture, NULL, rectangle);
}

void afficher_image (char *chemin, SDL_Rect *rectangle, SDL_Renderer *rendu)
{
    SDL_Surface *background = NULL;
    SDL_Texture *texture_backgroung = NULL;
    background = SDL_LoadBMP(chemin);

    if (background != NULL)
    {
        texture_backgroung = SDL_CreateTextureFromSurface(rendu, background);
        SDL_FreeSurface(background);
        texture_to_rect(rendu, texture_backgroung, rectangle);
    }
    else
    {
        printf("Erreur de chargement de l'image\n");
    }
}

void start(SDL_Renderer *rendu)
{
    SDL_Rect back_rect;
    SDL_Rect p1_rect;
    SDL_Rect p2_rect;
    SDL_Rect p3_rect;
    SDL_Rect p4_rect;

    ///////////////////////////////////
    back_rect.x = 0;
    back_rect.y = 0;
    back_rect.w = 800;
    back_rect.h = 800;
    ///////////////////////////////////

    p1_rect.x = 20;
    p1_rect.y = 500;
    p1_rect.w = 367;
    p1_rect.h = 50;

    ///////////////////////////////////

    p2_rect.x = 20;
    p2_rect.y = 570;
    p2_rect.w = 367;
    p2_rect.h = 50;

    ///////////////////////////////////

    p3_rect.x = 413;
    p3_rect.y = 500;
    p3_rect.w = 367;
    p3_rect.h = 50;

    ///////////////////////////////////

    p4_rect.x = 413;
    p4_rect.y = 570;
    p4_rect.w = 367;
    p4_rect.h = 50;

    ///////////////////////////////////



    afficher_image("background.bmp", &back_rect, rendu);
    afficher_image("buttons/joueur1.bmp", &p1_rect, rendu);
    afficher_image("buttons/joueur2.bmp", &p2_rect, rendu);
    afficher_image("buttons/joueur3.bmp", &p3_rect, rendu);
    afficher_image("buttons/joueur4.bmp", &p4_rect, rendu);

    SDL_RenderPresent(rendu);
}

int main(int argc, char *argv[])
{

    SDL_Window *fenetre = NULL;
    SDL_Renderer *rendu = NULL;
    SDL_bool condition = SDL_TRUE;
    

    if(SDL_Init(SDL_INIT_VIDEO != 0))
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Création de la fenêtre

    fenetre = SDL_CreateWindow("Jeu Rummikub", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              800, 800, SDL_WINDOW_SHOWN);
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


    /*SDL_Surface *background = NULL;
    SDL_Texture *texture_backgroung = NULL;*/



    // CHARGEMENT DES DIFFERENTES IMAGES ET ILLUSTRATIONS

    SDL_Rect back_rect;
    SDL_Rect p1_rect;
    SDL_Rect p2_rect;
    SDL_Rect p3_rect;
    SDL_Rect p4_rect;
    SDL_Rect commencer_rect;
    SDL_Rect quit_rect;
    SDL_Rect scores_rect;




    back_rect.x = 0;
    back_rect.y = 0;
    back_rect.w = 800;
    back_rect.h = 800;

    /////////////////////////////////

    ///////////////////////////////////

    commencer_rect.x = 137;
    commencer_rect.y = 600;
    commencer_rect.w = 526;
    commencer_rect.h = 50;

    ///////////////////////////////////

    scores_rect.x = 137;
    scores_rect.y = 670;
    scores_rect.w = 526;
    scores_rect.h = 50;

    ///////////////////////////////////

    quit_rect.x = 137;
    quit_rect.y = 740;
    quit_rect.w = 526;
    quit_rect.h = 50;



    afficher_image("background.bmp", &back_rect, rendu);
    /*afficher_image("buttons/joueur1.bmp", &p1_rect, rendu);
    afficher_image("buttons/joueur2.bmp", &p2_rect, rendu);
    afficher_image("buttons/joueur3.bmp", &p3_rect, rendu);
    afficher_image("buttons/joueur4.bmp", &p4_rect, rendu);*/
    afficher_image("buttons/commencer.bmp", &commencer_rect, rendu);
    afficher_image("buttons/scores.bmp", &scores_rect, rendu);
    afficher_image("buttons/quitter.bmp", &quit_rect, rendu);
    SDL_RenderPresent(rendu);
    //SDL_Delay(10000);
































































    /*

    // Initialisation de la SDL_ttf

    TTF_Init();
    if (TTF_Init() != 0)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL_ttf : %s", TTF_GetError());
        return EXIT_FAILURE;
    }

    // Dans cette partie, nous allons charger une police depuis un fichier, 
    // avec une taille de point à 15
    // /usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf : ceci est le chemin de notre police 
    // qui est ici DejaVuSans-Bold.ttf

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

    */


    //Mise à  jour de la fenêtre


    SDL_Event event;


    while (condition) 
    {
        
        while (SDL_PollEvent(&event)) {
            switch (event.type)
            {
                case SDL_MOUSEBUTTONDOWN :
                    if (137 <= event.button.x && event.button.x<= 663 && 600<= event.button.y &&event.button.y<= 650)
                    {
                        start(rendu);
                    }
                    else if (137 <= event.button.x && event.button.x<= 663 && 670<= event.button.y &&event.button.y<= 720)
                    {
                        printf("Vous avez clique sur le bouton scores.");
                    }
                    else if (137 <= event.button.x && event.button.x<= 663 && 740<= event.button.y &&event.button.y<= 790)
                    {
                        printf("Vous avez clique sur le bouton quitter.");
                    }
                    break;
                case SDL_QUIT :
                    condition = SDL_FALSE;
                    break;
                default :
                    break;
            }
        }
        
    }

    //TTF_CloseFont(police);
    //SDL_FreeSurface(TextSurface);
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();

    return EXIT_SUCCESS;
}