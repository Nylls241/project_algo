#include "../include/include.h"

void doInput(void)
{
	SDL_bool program_launched = SDL_TRUE
	while(program_launched)
	{
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{	
			switch (event.type)
			{	
				case SDL_QUIT:
					 program_launched = SDL_FALSE ;
					 break;

				default:
					break;
			}
		}	
	}	
}
