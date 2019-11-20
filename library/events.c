/**
 * \file events.c
 * \brief Fonctions liées aux evenements et à leur gestion 
 */

#include "headers/events.h"

void handle_events(world_t* world, SDL_Event* event){

	    //events
    	const Uint8* keystates;
    	while( SDL_PollEvent( event ) ) 
    	{
        	//Fermeture de la fenêtre
        	if( event->type == SDL_QUIT ) 
        	{
            	//Close
            	world->gameover = true;
        	}
        }

        SDL_PumpEvents();

        keystates = SDL_GetKeyboardState(NULL);

        if(keystates[SDL_SCANCODE_LEFT]){
            world->perso->x -= 3;
        }
        if(keystates[SDL_SCANCODE_RIGHT]){
            world->perso->x += 3;
        }
	    if(keystates[SDL_SCANCODE_SPACE]){
            world->perso->vy = -5;
        }
	    //     //loop delay
    	// 	if( event.key.keysym.sym  == SDLK_LEFT ){
     //    		world.perso->x -= 10;
    	// 	}
    	// 	if( event.key.keysym.sym  == SDLK_RIGHT ){
     //    		world.perso->x += 10;
    	// 	}
    	// 	if( event.key.keysym.sym == SDLK_SPACE ){
     //            world.perso->vy = -7;
     //        }
    	// }
     //    //printf("yes\n");
}