/**
 * \file data.c
 * \brief Fonctions liées aux données du monde
 */
//Macro récupérant le signe de X
#define SIGNE(X) (((X)==0)?(0):(((X)<0)?(-1):(1)))

#include"headers/data.h"

void data_update(world_t* world){
        perso_update(world);
        // printf("dest.y : %d\n", world->perso->dest.y);
        // printf("yfenscroll 1: %d\n", world->map->yfenscroll);
        // if((world->perso->dest.y <= 355 && world->map->yfenscroll <= 1099)
        //     || (world->perso->dest.y <= 360 && world->map->yfenscroll >= 0)){
        //     auto_scroll(world);
        // }
        auto_scroll(world);
        // limit_scroll(world);
}

void perso_update(world_t* world){
    //Déplacement du perso
    //deplacement_perso(world->perso);
    if(essai_deplacement_perso(world) == 1){
        approcher_mur(world);
    }
    update_speeds(world->perso);
}

void update_speeds(sqr_t* perso){
    //Vitesse de chute
    if (perso->vy < 5){
        perso->vy += 0.09;
    }
    else{
        perso->vy = 5;
    }
    perso->vx = 0;
}

int essai_deplacement_perso(world_t* world){
    //Next frame
    SDL_Rect alias;
    SDL_Rect prev;
    // printf("1. perso : x = %d, y = %d\n",world->perso->dest.x, world->perso->dest.y);
    alias = world->perso->dest;
    alias.x += world->perso->vx;
    alias.y += world->perso->vy;
    // printf("2. perso : x = %d, y = %d\n",world->perso->dest.x, world->perso->dest.y);
    // SDL_Rect test = {0,0,0,0};
    //TODO testCollision pour les blocs autour du perso
    if(testCollision(world->map, alias) == 1){
        // printf("0\n");
        prev = world->perso->dest;
        world->perso->dest = alias;
        //On vérifie une deuxième fois à cause du scroll
        if(testCollision(world->map, world->perso->dest) == 0){
            world->perso->dest = prev;
            return 0;
        }
    }
    // printf("1\n");
    return 1;
}

// void deplacement_perso(sqr_t* perso){
//     //printf("yes\n");
//     //Si à la prochaine frame il rentre en collision avec le sol alors on stoppe le deplacement
//     if (perso->dest.y+perso->dest.h+perso->vy < F_HEIGHT){
//         perso->dest.y += perso->vy;
//     }
//     else{
//         perso->dest.y = F_HEIGHT-P_HEIGHT+1;
//     }
//     //printf("yes\n");
//     //Déplacement du personnage
//     perso->dest.x += perso->vx;
//     perso->dest.y += perso->vy;
// }

void approcher_mur(world_t* world){
    int i;  
    for(i=0;i<abs(world->perso->vx);i++){
            if(essai_deplacement_pixel_perfect(world, SIGNE(world->perso->vx), 0) == 1){
                break;
            }
    }
    for(i=0;i<abs(world->perso->vy);i++){
            if(essai_deplacement_pixel_perfect(world, 0, SIGNE(world->perso->vy)) == 1){
                break;
            }          
    }
}

int essai_deplacement_pixel_perfect(world_t* world, double vx, double vy){
    //Next frame
    SDL_Rect alias;
    SDL_Rect prev;
    // printf("1. perso : x = %d, y = %d\n",world->perso->dest.x, world->perso->dest.y);
    alias = world->perso->dest;
    alias.x += vx;
    alias.y += vy;
    // printf("2. perso : x = %d, y = %d\n",world->perso->dest.x, world->perso->dest.y);
    SDL_Rect test = {0,0,0,0};
    //TODO testCollision pour les blocs autour du perso
    int resTest = testCollision(world->map, alias);
    // printf("%d\n", resTest);
    if(resTest == 1){
        prev = world->perso->dest;
        world->perso->dest = alias;
        //On vérifie une deuxième fois à cause du scroll
        if(testCollision(world->map, world->perso->dest) == 0){
            world->perso->dest = prev;
            return 0;
        }
    }
    return 1;
}

int testCollision(map_t* m, SDL_Rect perso){
    // printf("test collision\n");
    int xmin,xmax,ymin,ymax,i,j,indicetile;
    xmin = perso.x / TILE_WIDTH;
    ymin = (perso.y + m->yfenscroll) / TILE_HEIGHT;
    xmax = (perso.x + perso.w -1) / TILE_WIDTH;
    ymax = ((perso.y + perso.h -1) + m->yfenscroll) / TILE_HEIGHT; 
    // printf("xin:%d ymin:%d xmax:%d ymax:%d\n",xmin, ymin, xmax, ymax);
    //Test de collision AABB
    if (xmin<0 || ymin<0 || xmax>=m->nbtilesX_monde || ymax>=m->nbtilesY_monde)
        return 0;
    // printf("2eme\n");
    for(i=xmin;i<=xmax;i++){

        for(j=ymin;j<=ymax;j++){

            indicetile = m->tabNum[i][j];
            // printf("type : %d\n",m->tabTile[indicetile].typeTile);
            if (m->tabTile[indicetile].typeTile == 0){
                // printf("Collision ! \n");
                return 0;
            }

        }
    }
    return 1;
}

void limit_scroll(world_t* world){
    //Limitations du scrolling
        if (world->map->yfenscroll<0){
            world->map->yfenscroll=0;
        }
        if (world->map->yfenscroll>world->map->nbtilesY_monde * TILE_HEIGHT - F_HEIGHT - 1){
            world->map->yfenscroll=world->map->nbtilesY_monde * TILE_HEIGHT - F_HEIGHT - 1;
        }
}

void auto_scroll(world_t* world){
    int yp;
    yp = world->perso->dest.y + TILE_HEIGHT/2 + world->map->yfenscroll;
    // printf("yp : %d\n",yp);
    // printf("dest.y : %d\n", world->perso->dest.y);
    // printf("yfenscroll 1: %d\n", world->map->yfenscroll);
    world->map->yfenscroll = yp - (F_HEIGHT/2);
    world->perso->dest.y = F_HEIGHT/2 - TILE_HEIGHT/2;
    // printf("yfenscroll 2: %d\n", world->map->yfenscroll);
   
    // printf("vy : %f\n", world->perso->vy);

    // world->map->yfenscroll += world->perso->vy;

    // int maxH, minH;
    // maxH = F_HEIGHT/2 + world->map->nbtilesY_monde*TILE_WIDTH;
    // minH = F_HEIGHT/2;
    // if(yp >= minH || yp <= maxH){
    //      world->perso->dest.y = 350;
    // }
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