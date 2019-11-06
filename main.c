/**
 * \file main.c
 * \brief Fichier d'execution du projet sans nom
 */
#include <SDL2/SDL.h>
#include "library/headers/definitions.h"

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
    
    SDL_Event event;
    world_t world;
    sqr_t *cube = calloc(1, sizeof(sqr_t*));

    cube->h = 50;
    cube->w = 50;
    cube->x = F_WIDTH/2 - cube->w/2;
    cube->y = F_HEIGHT/2 - cube->h/2;
    cube->vx = 0.0;
    cube->vy = 2.0;

    world.gameover = true;
    world.perso = cube;
    
    SDL_Rect dest = {cube->x, cube->y, cube->w, cube->h};
    SDL_RenderCopy(pRenderer, pTexture, NULL, &dest);
    SDL_RenderPresent(pRenderer);

    const Uint8* keystates;
    
    
    //Boucle de jeu
    while(world.gameover){

    	//events
    
    	while( SDL_PollEvent( &event ) ) 
    	{
        	//Fermeture de la fenêtre
        	if( event.type == SDL_QUIT ) 
        	{
            	//Close
            	world.gameover = false;
        	}
        }

        SDL_PumpEvents();

        keystates = SDL_GetKeyboardState(NULL);

        if(keystates[SDL_SCANCODE_LEFT]){
            world.perso->x -= 3;
        }
        if(keystates[SDL_SCANCODE_RIGHT]){
            world.perso->x += 3;
        }
	    if(keystates[SDL_SCANCODE_SPACE]){
            world.perso->vy = -5;
        }
	    //     //loop delay
    	// 	if( event.key.keysym.sym  == SDLK_LEFT ){
     //    		world.perso->x -= 10;
    	// 	}
    	// 	if( event.key.keysym.sym  == SDLK_RIGHT ){
     //    		world.perso->x += 10;
    	// 	}
    	// 	if( event.key.keysym.sym == SDLK_SPACE ){
     //            world.perso->vy = -7;
     //        }
    	// }
     //    //printf("yes\n");
    	//data
    	dest.x = world.perso->x;
        if (world.perso->vy < 5){
            world.perso->vy += 0.05;
        }
        //printf("yes\n");
        world.perso->y += world.perso->vy;
        if (world.perso->y+world.perso->h < F_HEIGHT){
            dest.y = world.perso->y;
        }
        //printf("yes\n");

    	//graphics
        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
        SDL_RenderClear(pRenderer);
        SDL_RenderCopy(pRenderer, pTexture, NULL, &dest);
        SDL_RenderPresent(pRenderer);


    	SDL_Delay(10);
        
    }

    SDL_Quit();

    //Nettoyage
}
