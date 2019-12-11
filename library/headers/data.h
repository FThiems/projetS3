/**
 * \file data.h
 * \brief Headers des fonctions de data.c
 */

#ifndef DATA 
#define DATA

#include "definitions.h"

void data_update(world_t* world);

void limit_scroll(world_t* world);

void perso_update(world_t* world);

void deplacement_perso(sqr_t* perso);

int testCollision(map_t* m, SDL_Rect perso);

int essai_deplacement_perso(world_t* world);

int essai_deplacement_pixel_perfect(world_t* world, double vx, double vy);

void liberer_memoire(world_t* world, SDL_Renderer* screen);

void approcher_mur(world_t* world);

void update_speeds(sqr_t* perso);

void auto_scroll(world_t* world);

#endif