#include"../include/include.h"


/*La fonction initSDL Initialise  la SDL , Crée et renvoie une fenêtre et un rendu */

application initSDL(void)
{
/*-------------------------------------------------------------------------------------------------*/
//Initialisation des variables de la structure application 

	application app ;

	app.texture = NULL ;

	app.image = NULL ;

	app.fenetre = NULL ;

	app.rendu = NULL ;
//
	int renduFlags, fenetreFlags ;

	renduFlags = SDL_RENDERER_ACCELERATED;

	fenetreFlags = 0;
/*-------------------------------------------------------------------------------------------------*/
/*SDL_Init initialise la bibliothèque SDL et prend en paramètre un ou plusieurs sous systèmes (Flags) . Ici , il prend en paramètre SDL_INIT_VIDEO qui charge le système vidéo (affichage) + événements*/


	if (SDL_Init(SDL_INIT_VIDEO) != 0)//  renvoie  un autre nombre que 0 si l'initialisation n'a pas marché.
	{
		 SDL_ErrorQuit(" initialisation de la SDL\n") ;//Gestion d'erreur 
	}
	
/*-------------------------------------------------------------------------------------------------*/
/*La fonction SDL_CreateWindow Crée une fenêtre avec la position les dimensions et les drapeaux (Flags) spécifiés qu'on stocke dans la variable app.fenetre */ 

	app.fenetre = SDL_CreateWindow("RUMMIKUB", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, largeur_ecran, hauteur_ecran, fenetreFlags);/*Les paramètres : le titre de la fenêtre (ici RUMMIKUB) codé en UTF-8 , ensuite , la position en x ,  et la position en y de la fenêtre représenté ici par le flag SDL_WINDOWPOS_CENTERED qui va centrer la fenêtre, puis la largeur et la hauteur de la fenêtre et enfin le 0 pour rendre la fenêtre visible .*/

        if  (app.fenetre == NULL)//Renvoie NULL si la fenetre n'a pas été créé .
	{
		 SDL_ErrorQuit("création de la fenêtre\n") ;//Gestion d'erreur 
	}

	/*SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");*/

/*-------------------------------------------------------------------------------------------------*/
/* La fonction SDL_CreateRenderer crée un contexte de rendu 2D pour une fenêtre.Qu'on stocke dans app.rendu  */
 
	app.rendu = SDL_CreateRenderer(app.fenetre, -1, renduFlags);/*les paramètres :la fenêtre où le rendu est affiché, -1 pour initialiser le premier supportant les flags demandés,et le flag SDL_RENDERER_ACCELERATED qui utilise  le moteur de rendu  l'accélération matérielle*/



	if (app.rendu == NULL)//Renvoie NULL s'il y a eu une erreur
	{
		SDL_ErrorQuit("création du rendu  \n") ;//Gestion d'erreur 
	}
								    
	
	return app ;
	
}

/*SDL_ErrorQuit affiche un massage d'erreur , puis fait appel à la fonction SDL_GetError pour spécifier l'erreur , ensuite appel la fonction SDL_Quit pour quitter la SDL et enfin renvoie -1 et quitte le programme , cette fonction permet gerer les erreurs d'initialisation */

int SDL_ErrorQuit(const char *message)
{
        printf("ERREUR : %s ...>>> %s \n" ,message, SDL_GetError()) ; // Gestion d'erreur 
        SDL_Quit() ;
        return ( -1 ) ; //Quitte le programme

}

application implemente_rummikub(void){
		// Implentation du Rummikub 
	application app = dessin_tuile(app,14);//  on pioche 14 tuile au debut de la partie 

	presentScene(app) ; //le jeu est lancé 

	SDL_Delay(16) ;/* Cette attente sert à limiter notre boucle à environ 62 images par seconde et empêche également l'application de tourner à plein régime et de consommer beaucoup trop de temps du CPU.*/
	input() ; //la fenêtre du jeu est lancé
	destroySDL(app);
}	
//Rediger par Nylls Gersan BOUTOTO
