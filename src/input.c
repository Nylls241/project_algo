#include "../include/include.h"

void Input(void)
{
	SDL_bool programm = SDL_TRUE ;


	while (programm) 
	{
		SDL_Event event ;

		while(SDL_PollEvent(&event)) 
		{
			switch(event.type)
			{
				case SDL_QUIT:
					programm = SDL_FALSE ;
					break ;
				default:
					break ;
			}
		}
	}
}
