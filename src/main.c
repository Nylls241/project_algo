#include "../include/include.h"

int main(void) 
{
	 initSDL() ;
	 application app = initSDL() ;
	 	prepareScene( app ) ;
		presentScene( app) ;
		doInput() ;
		destroySDL(app) ;
		SDL_Delay(16) ;
	return 0 ;
}
