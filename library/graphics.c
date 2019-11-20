/**
 * \file graphics.c
 * \brief Fonctions liées à la gestion des graphismes
 */

#include"headers/graphics.h"

void refresh_graphics(world_t* world, SDL_Renderer* screen){

	SDL_RenderClear(screen);
    SDL_RenderCopy(screen, world->texture_perso, NULL, &world->dest);
    SDL_RenderPresent(screen);

}