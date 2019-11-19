/**
 * \file main.c
 * \brief Fichier d'execution du projet sans nom
 */
#include <SDL2/SDL.h>
#include "library/headers/definitions.h"
#include "library/headers/initialisation.h"
#include "library/headers/data.h"
#include "library/headers/events.h"

int main(int argc, char* argv[])
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
    printf("oui");
    init_world(&world);
    printf("oui");
    
    SDL_Rect dest = {world.perso->x, world.perso->y, world.perso->w, world.perso->h};
    SDL_RenderCopy(pRenderer, pTexture, NULL, &dest);
    SDL_RenderPresent(pRenderer);
    
    
    //Boucle de jeu
    while(!world.gameover){

    	handle_events(&world, &event);
    	data_update(&world);

        dest.x = world.perso->x;
        dest.y = world.perso->y;
        printf("y : %f vy : %f try : %f\n", world.perso->y, world.perso->vy, world.perso->y+world.perso->h);

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
