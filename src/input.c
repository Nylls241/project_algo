#include "../include/include.h"


/*Cette fonction lit simplement toutes les entrées(grâce à SDL_PollEvent qui prend la variable (par adresse) event (de type SDL_Event qui contient tout les évenements) récentes (clavier, souris, etc.) de la file d'attente de SDL jusqu'à ce qu'il n'en reste plus. l'instant  quitter(ici SDL_QUIT)  est déclenché  lorsque nous fermons la fenêtre SDL en cliquant sur son gadget de fermeture.*/
 
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
