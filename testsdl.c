/**
 * \file testsdl.c
 * \brief Fichier de test pour apprendre la sdl 2
 */

#include <SDL2/SDL.h>

#include <stdio.h>

#define F_HEIGTH 720
#define F_WIDTH 1300


int main(int argc, char* args[])
{
    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }

    {
        /* Création de la fenêtre */
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Fenêtre de jeu",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  1300,
                                                                  720,
                                                                  SDL_WINDOW_SHOWN);

        if( pWindow )
        {
            SDL_Surface *sqr = SDL_LoadBMP("ressources/bitmaps/redsqr.bmp");

            if (sqr)
            {
                SDL_Renderer *pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);

                if (pRenderer)
                {
                    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRenderer, sqr);

                    if (pTexture)
                    {
                        //Première frame
                        SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
                        SDL_RenderClear(pRenderer);
                        SDL_Rect dest = {F_WIDTH/2 - sqr->w/2, F_HEIGTH/2 - sqr->h/2, sqr->w, sqr->h};
                        SDL_RenderCopy(pRenderer, pTexture, NULL, &dest);
                        SDL_RenderPresent(pRenderer);
                        SDL_Delay(3000);

                        //Deuxième frame
                        dest.x = 0;
                        dest.y = 0;
                        SDL_SetRenderDrawColor(pRenderer, 255, 255, 0, 255);
                        SDL_RenderClear(pRenderer);
                        SDL_RenderCopy(pRenderer, pTexture, NULL, &dest);

                        SDL_DestroyTexture(pTexture);
                        SDL_RenderPresent(pRenderer);
                        SDL_Delay(3000);
                    }
                    else
                    {
                        printf("Erreur dans la creation de la texture : %s \n", SDL_GetError());
                    }

                    SDL_DestroyRenderer(pRenderer);
                    SDL_RenderPresent(pRenderer);
                    SDL_Delay(3000);
                }
                else
                {
                    printf("Erreur dans la creation du rendu : %s\n", SDL_GetError());
                }

                SDL_FreeSurface(sqr);
                SDL_RenderPresent(pRenderer);
                SDL_Delay(3000);
            }
            else
            {
                printf("Erreur dans le chargement du sprite : %s \n", SDL_GetError());
            }

            SDL_DestroyWindow(pWindow);
        }
        else
        {
            fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        }
    }

    SDL_Quit();

    return 0;
}
