#include "../include/include.h"

int main(void) 
{
	initSDL() ;
	prepareScene() ;
	doInput() ;
	presentScene() ;
	destroySDL() ;

	return 0 ;
}
