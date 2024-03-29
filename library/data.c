/**
 * \file data.c
 * \brief Fonctions liées aux données du monde
 */
//Macro récupérant le signe de X
#define SIGNE(X) (((X)==0)?(0):(((X)<0)?(-1):(1)))

#include"headers/data.h"

void data_update(world_t* world){
        perso_update(world);

        auto_scroll(world);
        // limit_scroll(world);
        // printf("%d\n", world->perso->peutSauter);
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
    if(testCollision(world, alias) == 1){
        prev = world->perso->dest;
        world->perso->dest = alias;
        return 0;
    }
    // printf("1\n");
    world->perso->peutSauter = true;
    return 1;
}

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
    int resTest = testCollision(world, alias);
    // printf("%d\n", resTest);
    if(resTest == 1){
        prev = world->perso->dest;
        world->perso->dest = alias;
        return 0;
    }
    world->perso->peutSauter = true;
    return 1;
}

int testCollision(world_t* world, SDL_Rect perso){
    // printf("test collision\n");
    int xmin,xmax,ymin,ymax,i,j,indicetile;
    xmin = perso.x / TILE_WIDTH;
    ymin = (perso.y + world->map->yfenscroll) / TILE_HEIGHT;
    xmax = (perso.x + perso.w -1) / TILE_WIDTH;
    ymax = ((perso.y + perso.h -1) + world->map->yfenscroll) / TILE_HEIGHT; 
    //Test de collision AABB
    if (xmin<0 || ymin<0 || xmax>=world->map->nbtilesX_monde || ymax>=world->map->nbtilesY_monde)
        return 0;
    // printf("2eme\n");
    for(i=xmin;i<=xmax;i++){

        for(j=ymin;j<=ymax;j++){

            indicetile = world->map->tabNum[i][j];
            // printf("type : %d\n",map->tabTile[indicetile].typeTile);
            if (world->map->tabTile[indicetile].typeTile == 0){
                // printf("Collision ! \n");
                return 0;
            }
            if(world->map->tabTile[indicetile].typeTile == 2){
                world->gameover = true;
            }
        }
    }
    return 1;
}

void auto_scroll(world_t* world){
    int yp;
    yp = world->perso->dest.y + TILE_HEIGHT/2 + world->map->yfenscroll;
    world->map->yfenscroll = yp - (F_HEIGHT/2);
    world->perso->dest.y = F_HEIGHT/2 - TILE_HEIGHT/2;
}

void change_tiles(world_t* world){
    int i, j; 
    for(i = 0; i < world->map->nbtilesX_monde; i++){
        for(j = 0; j< world->map->nbtilesY_monde; j++){
            if(world->map->tabNum[i][j] == 2){
                world->map->tabNum[i][j] = 5;
            }
            else if(world->map->tabNum[i][j] == 5){
                world->map->tabNum[i][j] = 2;
            }
        }
    }
}

void liberer_memoire(world_t* world, SDL_Renderer* screen){
    int i;
    free(world->perso);
    SDL_DestroyRenderer(screen);
    SDL_DestroyTexture(world->texture_perso);
    SDL_DestroyTexture(world->map->tileset);
    free(world->map->tabTile);
    for(i = 0; i < world->map->nbtilesX_monde; i++){
        free(world->map->tabNum[i]);
    }
    free(world->map->tabNum);
    free(world->map);
}