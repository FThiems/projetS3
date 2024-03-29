/**
 * \file events.c
 * \brief Fonctions liées aux evenements et à leur gestion 
 */

#include "headers/events.h"

void handle_events(world_t* world, SDL_Event* event){

    //events
	while( SDL_PollEvent( event ) ) 
	{
    	//Fermeture de la fenêtre
        if( event->type == SDL_QUIT ) 
    	{
        	//Close
        	world->gameover = true;
    	}
        if( event->type == SDL_KEYUP && event->key.keysym.sym == SDLK_x){
            change_tiles(world);
        }
    }
    move_perso(world);
    move_scrolling(world);
}

void move_perso(world_t* world){
    const Uint8* keystates;
    SDL_PumpEvents();

    keystates = SDL_GetKeyboardState(NULL);

    if(keystates[SDL_SCANCODE_LEFT]){
        world->perso->vx -= 3;
        // printf("left\n");
    }
    if(keystates[SDL_SCANCODE_RIGHT]){
        world->perso->vx += 3;
        // printf("rigth\n");
    }
    if(world->perso->peutSauter){
        if(keystates[SDL_SCANCODE_SPACE]){

            world->perso->vy = -5;
            world->perso->peutSauter = false;
        }
    }
}

void move_scrolling(world_t* world){
    const Uint8* keystates;
    SDL_PumpEvents();

    keystates = SDL_GetKeyboardState(NULL);

    if(keystates[SDL_SCANCODE_S]){
        world->map->yfenscroll += 3;
    }
    if(keystates[SDL_SCANCODE_W]){
        world->map->yfenscroll -= 3;
    }
}


