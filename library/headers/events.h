/**
 * \file events.h
 * \brief Headers des fonctions de events.c
 */

#ifndef EVENTS 
#define EVENTS

#include "definitions.h"

/**
 * \brief fonction qui prend en charges les evenements
 * \param world ensemble des données du monde
 * \param event evenement 
 */
void handle_events(world_t* world, SDL_Event* event);

/**
 * \brief modifie la vitesse du personnage 
 * \param world ensemble des données du monde
 */
void move_perso(world_t* world);

/**
 * \brief modifie la vitesse du scrolling 
 * \param
 */
void move_scrolling(world_t* world);

#endif