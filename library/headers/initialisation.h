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

map_t* charger_map(world_t* world, SDL_Renderer* screen);

void charger_tileset(FILE* F, map_t* m, SDL_Renderer* screen);

void charger_level(FILE* F, map_t* m);

#endif