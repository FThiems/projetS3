/**
 * \file main.c
 * \brief Fichier d'execution du projet sans nom
 */
#include "library/headers/initialisation.h"
#include "library/headers/data.h"
#include "library/headers/events.h"
#include "library/headers/graphics.h"

int main(int argc, char* argv[])
{
    //Initialisation
    SDL_Renderer *screen = init_sdl();

    SDL_Event event;
    world_t world;
    init_world(&world, screen);
    init_graphics(&world, screen);
    
    //Boucle de jeu
    while(!world.gameover){

    	handle_events(&world, &event);
    	data_update(&world);
        refresh_graphics(&world, screen);
    	SDL_Delay(10);
        
    }

    SDL_Quit();

    //Nettoyage
}
