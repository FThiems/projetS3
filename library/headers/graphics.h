/**
 * \file graphics.h
 * \brief Headers des fonctions de graphics.c
 */

#ifndef GRAPHICS 
#define GRAPHICS

#include "definitions.h"

/**
 * \brief Mets les graphismes à jour à chaque tour de jeu
 * \param world ensemble des données du monde
 * \param screen Surface de rendu de la fenêtre
 */
void refresh_graphics(world_t* world, SDL_Renderer* screen);

/**
 * \brief Affiche sur la surface de rendu les tiles de la carte
 * \param map ensemble des données liées à la carte du monde 
 * \param screen Surface de rendu de la fenêtre
 */
void afficher_carte(map_t* m, SDL_Renderer* screen);

/**
 * \brief Affiche l'écran de fin
 * \param world ensemble des données du monde
 * \param screen Surface de rendu de la fenêtre
 */ 
void afficher_ecran_de_fin(world_t* world, SDL_Renderer* screen);

#endif