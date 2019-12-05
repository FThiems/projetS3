/**
 * \file data.c
 * \brief Fonctions liées aux données du monde
 */

#include"headers/data.h"

void data_update(world_t* world){
        perso_update(world);
        limit_scroll(world);
}

void perso_update(world_t* world){
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
        world->perso->y = F_HEIGHT-P_HEIGHT+1;
    }
    //printf("yes\n");

    world->dest.x = world->perso->x;
    world->dest.y = world->perso->y;
}

void limit_scroll(world_t* world){
    //Limitations du scrolling manuel
        if (world->map->xfenscroll<0)
            world->map->xfenscroll=0;
        if (world->map->yfenscroll<0)
            world->map->yfenscroll=0;
        if (world->map->xfenscroll>world->map->nbtilesX_monde * TILE_WIDTH - F_WIDTH - 1)
            world->map->xfenscroll=world->map->nbtilesX_monde * TILE_WIDTH - F_WIDTH - 1;
        if (world->map->yfenscroll>world->map->nbtilesY_monde * TILE_HEIGHT - F_HEIGHT - 1)
            world->map->yfenscroll=world->map->nbtilesY_monde * TILE_HEIGHT - F_HEIGHT - 1;
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