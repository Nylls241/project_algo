#ifndef INIT_DRAW_H
#define INIT_DRAW_H

void input(void);
int SDL_ErrorQuit(const char *message) ;
application dessine_plateau(application app) ;
application prepareScene(application app ) ;
void presentScene(application app ) ;
application initSDL(void) ;
application creer_texture(application app,SDL_Rect rectangle) ;
SDL_Rect dessiner_rectangle(int x , int y , int w ,int h);
application white_window();

#endif 
