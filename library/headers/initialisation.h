/**
 * \file initialisation.h
 * \brief headers des fonctions d'initialisation des données
 */

#ifndef INIT 
#define INIT

#include "definitions.h"

/**
 * \brief Initialise les données du monde
 * \param world ensemble des données du monde
 * \param screen Surface de rendu de la fenêtre
 */
void init_world(world_t* world, SDL_Renderer* screen);

/**
 * \brief Initialise les données du personnage
 * \return un pointeur sur la structure du personnage
 */
sqr_t* init_perso();

/**
 * \brief inintialise la sdl (fenetre, rendu)
 * \return un pointeur sur une surface de rendu
 */
SDL_Renderer* init_sdl();

/**
 * \brief charge les données de la carte dans une structure
 * \param world ensemble des données du monde
 * \param screen Surface de rendu de la fenêtre
 * \return un pointeur sur une structure map
 */
map_t* charger_map(world_t* world, SDL_Renderer* screen);

/**
 * \brief crée un tableau correspondant aux différentes tiles de la bitmap
 * \param F fichier de modification des tiles
 * \param map ensemble des données liées à la carte du monde
 * \param screen Surface de rendu de la fenêtre
 */
void charger_tileset(FILE* F, map_t* m, SDL_Renderer* screen);

/**
 * \brief crée un tableau correspondant aux différentes tiles de notre monde 
 * \param F fichier de modification des tiles
 * \param map ensemble des données liées à la carte du monde 
 */
void charger_level(FILE* F, map_t* m);

#endif