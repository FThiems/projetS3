/**
 * \file events.h
 * \brief Headers des fonctions de events.c
 */

#ifndef EVENTS 
#define EVENTS

#include "definitions.h"

void handle_events(world_t* world, SDL_Event* event);

void move_perso(world_t* world);

void move_scrolling(world_t* world);

#endif