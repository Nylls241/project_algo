#include "../include/include.h"

// Creation d'une surface rectangulaire à partir d'une texture

void texture_to_rect(SDL_Renderer *rendu, SDL_Texture *texture, SDL_Rect *rectangle)
{
    SDL_QueryTexture(texture, NULL, NULL, &(rectangle->w), &(rectangle->h));
    SDL_RenderCopy(rendu, texture, NULL, rectangle);
}

// Fonction pour afficher des images à l'écran

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

// FONCTION DE CONFIGURATION DES JOUEURS

void menu_joueur(SDL_Renderer *rendu)
{
    SDL_Rect background_rect;
    SDL_Rect p1_rect;
    SDL_Rect p2_rect;
    SDL_Rect p3_rect;
    SDL_Rect p4_rect;
    // SDL_Rect back_rect;
    SDL_Rect lancer_rect;


    ///////////////////////////////////

    background_rect.x = 0;
    background_rect.y = 0;
    background_rect.w = 800;
    background_rect.h = 800;

    ///////////////////////////////////

    lancer_rect.x = 137;
    lancer_rect.y = 600;
    lancer_rect.w = 526;
    lancer_rect.h = 50;

    ///////////////////////////////////

    // back_rect.x = 137;
    // back_rect.y = 740;
    // back_rect.w = 526;
    // back_rect.h = 50;

    ///////////////////////////////////    


    p1_rect.x = 20;
    p1_rect.y = 20;
    p1_rect.w = 367;
    p1_rect.h = 50;

    ///////////////////////////////////

    p2_rect.x = 20;
    p2_rect.y = 90;
    p2_rect.w = 367;
    p2_rect.h = 50;

    ///////////////////////////////////

    p3_rect.x = 20;
    p3_rect.y = 160;
    p3_rect.w = 367;
    p3_rect.h = 50;

    ///////////////////////////////////

    p4_rect.x = 20;
    p4_rect.y = 230;
    p4_rect.w = 367;
    p4_rect.h = 50;


    afficher_image("images/jeu-rummikub.bmp", &background_rect, rendu);
    afficher_image("buttons/joueur1.bmp", &p1_rect, rendu);
    afficher_image("buttons/joueur2.bmp", &p2_rect, rendu);
    afficher_image("buttons/joueur3.bmp", &p3_rect, rendu);
    afficher_image("buttons/joueur4.bmp", &p4_rect, rendu);
    afficher_image("buttons/commencer.bmp", &lancer_rect, rendu);
    //afficher_image("buttons/retour.bmp", &back_rect, rendu);

    // Dessinons les lignes de renseignement des pseudos des joueurs

    SDL_RenderDrawLine(rendu, 397, 70, 764, 70);
    SDL_RenderDrawLine(rendu, 397, 140, 764, 140);
    SDL_RenderDrawLine(rendu, 397, 210, 764, 210);
    SDL_RenderDrawLine(rendu, 397, 280, 764, 280);

    SDL_RenderPresent(rendu);
}

// FONCTION DE PRESENTATION DE LA FENETRE D'ACCUEIL

void accueil(SDL_Renderer *rendu)
{
    SDL_Rect background_rect;
    SDL_Rect commencer_rect;
    // SDL_Rect quit_rect;
    SDL_Rect scores_rect;

    ///////////////////////////////////

    background_rect.x = 0;
    background_rect.y = 0;
    background_rect.w = 800;
    background_rect.h = 800;

    //////////////////////////////////

    // commencer_rect.x = 137;
    // commencer_rect.y = 600;
    // commencer_rect.w = 526;
    // commencer_rect.h = 50;

    /////////////////////////////////

    scores_rect.x = 137;
    scores_rect.y = 670;
    scores_rect.w = 526;
    scores_rect.h = 50;

    /////////////////////////////////

    commencer_rect.x = 137;
    commencer_rect.y = 740;
    commencer_rect.w = 526;
    commencer_rect.h = 50;

    ////////////////////////////////
    ////////////////////////////////

    afficher_image("background.bmp", &background_rect, rendu);
    afficher_image("buttons/partie.bmp", &commencer_rect, rendu);
    afficher_image("buttons/scores.bmp", &scores_rect, rendu);
    // afficher_image("buttons/quitter.bmp", &quit_rect, rendu);

    SDL_RenderPresent(rendu);
}

// Cette fonction nous servira pour afficher du texte à l'écran

void afficher_texte(SDL_Renderer *rendu, char *texte, int x, int y)
{

    // INITIALISATION DE LA LIBRAIRIE SDL_TTF


     if (TTF_Init() != 0)
    {
        printf("Erreur d'initialisation de la TTF >");
    }

    // Charge la police depuis un fichier, avec une taille de police de 45


    TTF_Font *police = TTF_OpenFont("police1.ttf", 20);

    // Si la police est nulle, alors il y'a erreur

    if (police == NULL)
    {
        printf("Erreur de chargement de la police >>:%s\n", TTF_GetError());
    }

    SDL_Surface *TextSurface;
    SDL_Texture *TextTexture;

    // Couleur du texte(couleur de code #33FCFF -> (BLEU-CIEL))

    SDL_Color TextColor;
    TextColor.r = 51;
    TextColor.g = 252;
    TextColor.b = 255;


    // Creation de la surface SDL sur laquelle on rendra notre texte 

    TextSurface = TTF_RenderText_Solid(police, texte, TextColor);

    // Verifions ici si la surface est bien chargee

    if (TextSurface == NULL)
    {
        printf("Erreur de creation de surface de rendu du texte :%s\n", TTF_GetError());
    }

    TextTexture = SDL_CreateTextureFromSurface(rendu, TextSurface);
    if (TextTexture == NULL)
    {
         printf("Erreur lors de la creation de la texture :%s\n", SDL_GetError());
    }
    SDL_FreeSurface(TextSurface);

    // Surface de destination de TextSurface

    SDL_Rect DstRect;
    DstRect.x = x;
    DstRect.y = y;
    DstRect.w = 367;
    DstRect.h = 50;

    // Mettons notre texture dans un rectangle

    SDL_QueryTexture(TextTexture, NULL, NULL, &(DstRect.w), &(DstRect.h));
    SDL_RenderCopy(rendu, TextTexture, NULL, &DstRect);

    // AFFICHONS LE RESULTAT
    //SDL_RenderPresent(rendu);

    // Liberation des ressources

    // SDL_FreeSurface(TextSurface);
    // TTF_CloseFont(police);

}

// Cette fonction calcule la longueur d'une chaine de caractere

int string_length(const char* str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

// Cette fonction concatène deux chaînes de caracteres prises en parametre

char* string_concat(const char* str1, const char* str2)
{
    int len1 = string_length(str1);
    int len2 = string_length(str2);
    char* result = (char*)malloc(len1 + len2 + 1);
    strcpy(result, str1);
    strcpy(result + len1, str2);
    return result;
}

// FONCTION POUR LA SAISIE DU TEXTE PAR L'UTILISATEUR

// char* input_text(SDL_Renderer *rendu, int x, int y)
// {
//     SDL_bool run = SDL_TRUE;
//     SDL_Event ev;

//     char *text ;

//     SDL_StartTextInput();

//     while(run)
//     {
//         while(SDL_PollEvent(&ev) != 0 )
//         {
//             // Capture des evenements QUITTER et du clavier

//             if (ev.type == SDL_QUIT)
//             {
//                 run = SDL_FALSE;
//                 break;
//             }
//             if (ev.type == SDL_TEXTINPUT || ev.type == SDL_KEYDOWN)
//             {
//                 if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_BACKSPACE && string_length(text) > 0)
//                 {
//                     text[ string_length(text) - 1 ] = '\0';
//                     afficher_texte(rendu, text, x, y);
//                     SDL_RenderPresent(rendu);
//                 }
//                 else if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_BACKSPACE && string_length(text) <= 0)
//                 {
//                     run = SDL_FALSE;

//                 }
//             }
//         }
//     }
// }


//string_concat(text, alphabet[i]);


void modifier_pseudo(int *cas,char lettre,char *pseudo1, char *pseudo2, char *pseudo3, char *pseudo4){

    switch(*cas)
    {
    case 1:
        if (string_length(pseudo1) < 20)
        {
            string_concat(pseudo1, &lettre);
        }
        break;
    case 2:
        if (string_length(pseudo2) < 20)
        {
            string_concat(pseudo2, &lettre);
        }
        break;
    case 3:
        if (string_length(pseudo3) < 20)
        {
            string_concat(pseudo3, &lettre);
        }
        break;
    case 4:
        if (string_length(pseudo4) < 20)
        {
            string_concat(pseudo4, &lettre);
        }
        break;
    default:
        break;
    }
}



void pos_curseur(int* niv, int ref, SDL_Rect pseudo_rect){

    if(ref == (-1)){

        if(*niv > 1){
            *niv = *niv - 1 ;
            pseudo_rect.y = pseudo_rect.y - 70 ;
        }

    }

    else if( ref == 1){

        if(*niv < 4){
            *niv = *niv + 1 ;
            pseudo_rect.y = pseudo_rect.y + 70 ;
        }

    }
}


void move_last_caracter(char *mot){
    mot[string_length(mot) - 1] = '\0';
}



void move_last_caracter_pseudo(int *cas, char *pseudo1, char *pseudo2, char *pseudo3, char *pseudo4)
{
    switch(*cas)
    {

        case 1:
            if (string_length(pseudo1) > 0)
            {
                move_last_caracter(pseudo1);
            }
            break;
        case 2:
            if (string_length(pseudo2) > 0)
            {
                move_last_caracter(pseudo2);
            }
            break;
        case 3:
            if (string_length(pseudo3) > 0)
            {
                move_last_caracter(pseudo3);
            }
            break;
        case 4:
            if (string_length(pseudo4) > 0)
            {
                move_last_caracter(pseudo4);
            }
            break;
        default:
            break;

    }
}



// LA FONCTION SUIVANTE GERE ET AFFICHE LE MENU DE NOTRE JEU(AVANT-JEU).

char *execution()
{
    SDL_Window *fenetre = NULL;
    SDL_Renderer *rendu = NULL;

    SDL_bool condition = SDL_TRUE;


    SDL_Rect pseudo_rectangle;
    SDL_Rect pseudo1_rectangle;
    SDL_Rect pseudo2_rectangle;
    SDL_Rect pseudo3_rectangle;
    SDL_Rect pseudo4_rectangle;
    



    int position;
    position = 1;

    char pseudo1_name[20];
    char pseudo2_name[20];
    char pseudo3_name[20];
    char pseudo4_name[20];

    strcpy(pseudo1_name, "");
    strcpy(pseudo2_name, "");
    strcpy(pseudo3_name, "");
    strcpy(pseudo4_name, "");

    pseudo_rectangle.x = 397;
    pseudo_rectangle.y = 20;
    pseudo_rectangle.w = 367;
    pseudo_rectangle.h = 50;

    pseudo1_rectangle.x = 397;
    pseudo1_rectangle.y = 20;
    pseudo1_rectangle.w = 367;
    pseudo1_rectangle.h = 50;

    pseudo2_rectangle.x = 397;
    pseudo2_rectangle.y = 90;
    pseudo2_rectangle.w = 367;
    pseudo2_rectangle.h = 50;

    pseudo3_rectangle.x = 397;
    pseudo3_rectangle.y = 160;
    pseudo3_rectangle.w = 367;
    pseudo3_rectangle.h = 50;

    pseudo4_rectangle.x = 397;
    pseudo4_rectangle.y = 230;
    pseudo4_rectangle.w = 367;
    pseudo4_rectangle.h = 50;

    char texte1[] = "Veuillez indiquer les pseudos des joueurs dans les parties reservees ci-dessus";

     // INITIALISATION DE LA SDL

    if(SDL_Init(SDL_INIT_VIDEO != 0))
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s", SDL_GetError());
    }

    // Création de la fenêtre

    fenetre = SDL_CreateWindow("Jeu Rummikub", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              800, 800, SDL_WINDOW_SHOWN);
    if(fenetre == NULL)
    {
        fprintf(stderr, "Erreur de création de la fenêtre: %s", SDL_GetError());
    }


    // Création du rendu

    rendu = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    if (rendu == NULL)
    {
        fprintf(stderr, "Erreur de création du rendu : %s", SDL_GetError());
    }

    // AFFICHAGE DE LA PREMIERE FENETRE( celle qui contient le menu principal)

    accueil(rendu);
    


    // GESTION DES EVENEMENTS GRAPHIQUE ET DE DE FONCTIONNEMENT DE NOTRE JEU


    SDL_Event event;

    
    SDL_StartTextInput();

    while (condition) 
    {
        
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {


                case SDL_MOUSEBUTTONDOWN :
                    if (137 <= event.button.x && event.button.x<= 663 && 600<= event.button.y &&event.button.y<= 650)
                    {
                        //printf("<<<<<------ Vous avez clique sur le bouton COMMENCER ------>>>>>");
                        SDL_Quit(); //ici
                        //Notre première fenêtre se ferme ici
                        // Et on affiche ensuite la fenêtre de jeu
                        implemente_rummikub();
                        
                        
                    }
                    else if (137 <= event.button.x && event.button.x<= 663 && 670<= event.button.y &&event.button.y<= 720)
                    {
                        printf("Vous avez clique sur le bouton scores.");
                    }
                    else if (137 <= event.button.x && event.button.x<= 663 && 740<= event.button.y &&event.button.y<= 790)
                    {
                        menu_joueur(rendu);
                        afficher_texte(rendu, texte1, 20, 300);
                        SDL_RenderPresent(rendu);
                    }
                    else if (397 <= event.button.x && event.button.x<= 764 && 20<= event.button.y &&event.button.y<= 70)
                    {
                        //char *text = 
                        // input_text(rendu, 397, 20);
                        // printf("\n%s\n", text);
                        // afficher_texte(rendu, text, 397, 20);
                    }
                    break;

                case SDL_KEYDOWN:



                    if (event.key.keysym.sym == SDLK_a){ // Si la touche enfoncee est la touche "a" du clavier
                                                         // C'est pareil pour les touches qui suivent.
                                                         // ICI ON AFFICHE LA LETTRE A
                    
                        modifier_pseudo(&position, 'A', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_b)
                    {
                        modifier_pseudo(&position, 'B', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_c)
                    {
                        modifier_pseudo(&position, 'C', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_d)
                    {
                        modifier_pseudo(&position, 'D', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_e)
                    {
                        modifier_pseudo(&position, 'E', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_f)
                    {
                        modifier_pseudo(&position, 'F', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_g)
                    {
                        modifier_pseudo(&position, 'H', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_h)
                    {
                        modifier_pseudo(&position, 'H', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_i)
                    {
                        modifier_pseudo(&position, 'I', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_j)
                    {
                        modifier_pseudo(&position, 'J', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_k)
                    {
                        modifier_pseudo(&position, 'K', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_l)
                    {
                        modifier_pseudo(&position, 'L', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_m)
                    {
                        modifier_pseudo(&position, 'M', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_n)
                    {
                        modifier_pseudo(&position, 'N', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_o)
                    {
                        modifier_pseudo(&position, 'O', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_p)
                    {
                        modifier_pseudo(&position, 'P', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_q)
                    {
                        modifier_pseudo(&position, 'Q', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_r)
                    {
                        modifier_pseudo(&position, 'R', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_s)
                    {
                        modifier_pseudo(&position, 'S', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_t)
                    {
                        modifier_pseudo(&position, 'T', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_u)
                    {
                        modifier_pseudo(&position, 'U', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_v)
                    {
                        modifier_pseudo(&position, 'V', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_w)
                    {
                        modifier_pseudo(&position, 'W', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_x)
                    {
                        modifier_pseudo(&position, 'X', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_y)
                    {
                        modifier_pseudo(&position, 'Y', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if (event.key.keysym.sym == SDLK_z)
                    {
                        modifier_pseudo(&position, 'Z', pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }

                    else if(event.key.keysym.sym == SDLK_BACKSPACE) // Si on enfonce la touche Backspace du clavier
                    {
                        move_last_caracter_pseudo(&position, pseudo1_name, pseudo2_name, pseudo3_name, pseudo4_name);
                    }
                    else if (event.key.keysym.sym == SDLK_UP) //Si on enfonce la touche Up(Haut) du clavier
                    {
                        pos_curseur(&position, -1, pseudo_rectangle);
                    }
                    else if (event.key.keysym.sym == SDLK_DOWN) // Si on enfonce la touche Down(Bas) du clavier
                    {
                        pos_curseur(&position, -1, pseudo_rectangle);
                    }
                    else{}
                    break;


                case SDL_QUIT:

                    condition = SDL_FALSE;
                    break;

                default :
                    break;
            }

        } 
    }
    afficher_texte(rendu, pseudo1_name, 397, 20);
    afficher_texte(rendu, pseudo2_name, 397, 90);
    afficher_texte(rendu, pseudo3_name, 397, 160);
    afficher_texte(rendu, pseudo4_name, 397, 210);
    SDL_RenderPresent(rendu);


    // LIBERATION DES RESSOURCES
    SDL_StopTextInput();
    TTF_Quit();
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();

}


// int main(int argc, char *argv[])
// {
    
//     execution();
    
    
//     return 0;
// }





// NOTE : CE TRAVAIL A ETE EFFECTUE PAR "OSCAR BOOG" ET "SALAMATA MBAYE".
// NOUS AVONS EU DES DIFFICULTES POUR LA GESTION DES EVENEMENTS DE SAISIE DE TEXTE
// IL ETAIT JUSTEMENT DÛ AU QUE NOUS NE POUVIONS PAS RECUPERER LE TEXTE SAISI
// DU COUP NOUS AVONS ABANDONNE LA SAISIE DES NOMS PAR L'UTILISATEUR
