/**
 * \file main.c
 * \brief Fichier d'execution du projet Ikaruga 2
 */
#include <SDL2/SDL.h>
#include "ressources/headers/definitions.h"

int main(int argc, char* args[])
{
    //Initialisation
	if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("Ikaruga 2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  F_WIDTH,
                                                                  F_HEIGHT,
                                                                  SDL_WINDOW_SHOWN);
    SDL_Surface *sqr = SDL_LoadBMP("ressources/bitmaps/redsqr.bmp");
    SDL_Renderer *pRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRenderer, sqr);
    SDL_Event *event = malloc(sizeof(SDL_Event));
    world_t world;
    sqr_t *cube = calloc(1, sizeof(sqr_t*));

    cube->h = 50;
    cube->w = 50;
    cube->x = F_WIDTH/2 - cube->w/2;
    cube->y = F_HEIGHT/2 - cube->h/2;
    cube->vx = 0.0;
    cube->vy = 1.0;

    world.gameover = true;
    world.perso = cube;
    world.blocs = calloc(0, sizeof(bloc_t));
    printf("oui\n");
    //Boucle de jeu
    while(world.gameover){

    	//events
    
    	while( SDL_PollEvent( event ) ) 
    	{
        	//Fermeture de la fenêtre
        	if( event->type == SDL_QUIT ) 
        	{
            	//Close
            	world.gameover = false;
        	}
	        
	        //loop delay
    		if( event->type == SDLK_LEFT ){
        		world.perso->x -= 10;
    		}
    		if( event->type == SDLK_LEFT ){
        		world.perso->x += 10;
    		}
    	}

    	//data

    	//graphics


    	SDL_Delay(100);
    }

    SDL_Quit();

    //Nettoyage
}
