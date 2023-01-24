#ifndef INIT_DRAW_H
#define INIT_DRAW_H

void input(void);
int SDL_ErrorQuit(const char *message) ;
application dessine_plateau(application app) ;
application prepareScene(application app ) ;
void presentScene(application app ) ;
application initSDL(void) ;
application dessin_plateau(application app,SDL_Rect rectangle) ;
SDL_Rect position_plateau(int x , int y );
application dessin_chevalet (application app);
void charger_tuile(application app , tuile t) ;
#endif 
