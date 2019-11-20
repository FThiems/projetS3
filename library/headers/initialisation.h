/**
 * \file initialisation.h
 * \brief headers des fonctions d'initialisation des données
 */

#ifndef INIT 
#define INIT

#include "definitions.h"

void init_world(world_t* world, SDL_Renderer* screen);

sqr_t* init_perso();

SDL_Rect init_dest(world_t* world);

SDL_Renderer* init_sdl();

#endif