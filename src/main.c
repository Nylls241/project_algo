#include "../include/include.h"

int main(void) 
{
 	application app = initSDL() ;
	prepareScene(app) ;
	presentScene(app) ; 
	Input() ;
	destroySDL(app);
	return 0 ;
}
