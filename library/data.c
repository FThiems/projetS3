/**
 * \file data.c
 * \brief Fonctions liées aux données du monde
 */

#include"headers/data.h"

void data_update(world_t* world){
		//data
        if (world->perso->vy < 5){
            world->perso->vy += 0.05;
        }
        else{
            world->perso->vy = 5;
        }
        //printf("yes\n");
        //Si à la prochaine frame il rentre en collision alors on stoppe le deplacement
        if (world->perso->y+world->perso->h+world->perso->vy < F_HEIGHT){
            world->perso->y += world->perso->vy;
        }
        else{
            world->perso->y = F_HEIGHT-51;
        }
        //printf("yes\n");

        world->dest.x = world->perso->x;
        world->dest.y = world->perso->y;
        //printf("y : %f vy : %f try : %f\n", world->perso->y, world->perso->vy, world->perso->y+world->perso->h);
}

void liberer_memoire(world_t* world, SDL_Renderer* screen){
    /**
    liste à libérer :
    map
    screen
    sqr
    window
    les textures (tilseset...)
    */

}