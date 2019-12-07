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
    //Déplacement du perso
    //deplacement_perso(world->perso);
    essai_deplacement_perso(world);
    world->perso->vx = 0;
}

void essai_deplacement_perso(world_t* world){
    //Next frame
    sqr_t* alias = calloc(1, sizeof(sqr_t));
    alias = world->perso;
    alias->dest.x += world->perso->vx;
    alias->dest.y += world->perso->vy;
    SDL_Rect test = {0,0,0,0};
    //TODO testCollision pour les blocs autour du perso
    if(testCollision(test, world->perso) == 0){
        deplacement_perso(world->perso);
    }
}

void deplacement_perso(sqr_t* perso){
    if (perso->vy < 5){
        perso->vy += 0.05;
    }
    else{
        perso->vy = 5;
    }
    //printf("yes\n");
    //Si à la prochaine frame il rentre en collision alors on stoppe le deplacement
    if (perso->dest.y+perso->dest.h+perso->vy < F_HEIGHT){
        perso->dest.y += perso->vy;
    }
    else{
        perso->dest.y = F_HEIGHT-P_HEIGHT+1;
    }
    //printf("yes\n");
}

int testCollision(SDL_Rect mur, sqr_t* perso){
    //Test de collision AABB
    if((mur.x >= perso->dest.x + perso->dest.w) || (mur.x + mur.w <= perso->dest.x) 
    || (mur.y >= perso->dest.y + perso->dest.h) || (mur.y + mur.h <= perso->dest.y)){
        return 0;
    }  
    return 1;
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