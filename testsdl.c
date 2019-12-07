/**
 * \file testsdl.c
 * \brief Fichier de test pour apprendre la sdl 2
 */

#include <SDL2/SDL.h>

#include <stdio.h>

#define F_HEIGHT 720
#define F_WIDTH 1300


int main(int argc, char* args[])
{
    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_Window *window = SDL_CreateWindow("Da game",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  F_WIDTH,
                                                                  F_HEIGHT,
                                                                  SDL_WINDOW_SHOWN);
    SDL_Delay(3000);
    SDL_Quit();

    return 0;
}
