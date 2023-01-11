#include "../include/include.h"

int main(void) 
{
 	application app = initSDL() ;
	prepareScene(app) ;
	CreeTexture(app) ; 
	presentScene(app) ; 
	input() ;
	destroySDL(app);
	return 0 ;
}
