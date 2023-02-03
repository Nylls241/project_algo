#ifndef INIT_DRAW_H
#define INIT_DRAW_H

application fenetre_menu();
application white_window();
void input(void);
int SDL_ErrorQuit(const char *message) ;
application dessine_plateau(application app) ;
application prepareScene(application app ) ;
void presentScene(application app ) ;
application initSDL(void) ;

application dessin_plateau(application app) ;
application dessin_chevalet (application app);
application dessin_tuile(application app,int nb);
application implemente_rummikub() ; 


void texture_to_rect(SDL_Renderer *rendu, SDL_Texture *texture, SDL_Rect *rectangle) ; 
void afficher_image (char *chemin, SDL_Rect *rectangle, SDL_Renderer *rendu); 
void menu_joueur(SDL_Renderer *rendu);
void accueil(SDL_Renderer *rendu); 
void afficher_texte(SDL_Renderer *rendu, char *texte, int x, int y);
int string_length(const char* str);
char* string_concat(const char* str1, const char* str2);
void modifier_pseudo(int *cas,char lettre,char *pseudo1, char *pseudo2, char *pseudo3, char *pseudo4);
void move_last_caracter(char *mot);
void move_last_caracter_pseudo(int *cas, char *pseudo1, char *pseudo2, char *pseudo3, char *pseudo4);
char *execution();



//int reserve [15] [5]; //permet de "stocker" les tuiles, numéro, puis couleur
int* initScore(int scores[]);
int* finalScore(int scores[], chevalet chevalets[]);
void afficheScore(int scores[]);
void sauvegardeScore(int scores);
int initTour();
int nextTurn(int ot, int nbj);
int isMyTurn(int t, int idJoueur);
app_che pioche(int nb, app_che ac);
void initReserve();


#endif 
