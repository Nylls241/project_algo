#include "SDL.h"
#include <stdlib.h>
#include <stdio.h>
#include "init_draw.h"

void doInput(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				break;

			default:
				break;
		}
	}
}
