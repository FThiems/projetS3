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

    // SDL_Surface* p = SDL_LoadBMP("ressources/bitmaps/Cube1_Upwell.bmp");
    // SDL_Texture* test = SDL_CreateTextureFromSurface(screen, p);
    // SDL_FreeSurface(p);
    // SDL_Rect dest = {0,0,50,50};
    // SDL_RenderCopy(screen, test, NULL, &dest);
    // SDL_RenderPresent(screen);

    
    //Boucle de jeu
    while(!world.gameover){

    	handle_events(&world, &event);
    	data_update(&world);
        // printf("%f\n", world.perso->vy);
        refresh_graphics(&world, screen);
    	SDL_Delay(10);
        
    }
    liberer_memoire(&world, screen);
    SDL_Quit();
}
