#ifndef INIT_DRAW_H
#define INIT_DRAW_H

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
