#ifndef INIT_DRAW_H
#define INIT_DRAW_H

void Input(void);
int SDL_ErrorQuit(const char *message) ;
void prepareScene(application app) ;
void presentScene(application app ) ;
application initSDL(void) ;

#endif 
