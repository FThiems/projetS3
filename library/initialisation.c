/**
 * \file initialisation.c
 * \brief fonctions d'initialisation des données
 */

#include "headers/initialisation.h"

void init_world(world_t* world, SDL_Renderer* screen){
	world->gameover = false;
	world->perso = init_perso();
	SDL_Surface* image_perso = SDL_LoadBMP("ressources/bitmaps/redsqr.bmp");
	world->texture_perso = SDL_CreateTextureFromSurface(screen, image_perso);
  SDL_FreeSurface(image_perso);
	init_dest(world);
}

sqr_t* init_perso(){
	sqr_t* cube = calloc(1,sizeof(sqr_t));
	cube->h = 50;
  cube->w = 50;
  cube->x = F_WIDTH/2 - cube->w/2;
  cube->y = F_HEIGHT/2 - cube->h/2;
  cube->vx = 0.0;
  cube->vy = 2.0;
  return cube;
}

SDL_Rect init_dest(world_t* world){
	SDL_Rect dest = {world->perso->x, world->perso->y, world->perso->w, world->perso->h};
	world->dest = dest;
}

SDL_Renderer* init_sdl(){
	if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }

  SDL_Window *window = SDL_CreateWindow("Da game",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  F_WIDTH,
                                                                  F_HEIGHT,
                                                                  SDL_WINDOW_SHOWN);
    
  SDL_Renderer *pRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);

	return pRenderer;
}