#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"
#include "defs.h"
#include "structures.h"
#include "init_draw.h"

#include "destroy.h"


int main(void) 
{
	initSDL() ;
	prepareScene() ;
	doInput() ;
	presentScene() ;
	destroySDL() ;

	return  ;
}
