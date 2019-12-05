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

void liberer_memoire(world_t* world, SDL_Renderer* screen);

#endif