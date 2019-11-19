/**
 * \file initialisation.c
 * \brief fonctions d'initialisation des données
 */

#include <SDL2/SDL.h>
#include "headers/definitions.h"
#include "headers/initialisation.h"

void init_world(world_t *world){
	world->gameover = false;
	world->perso = init_perso();
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