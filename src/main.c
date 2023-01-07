#include "../include/include.h"

int main(void) 
{
 	application app = initSDL() ;
	Input() ;
	prepareScene(app) ;
	presentScene(app) ; 
	destroySDL(app);
	return 0 ;
}
