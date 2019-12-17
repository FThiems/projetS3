/**
 * \file data.h
 * \brief Headers des fonctions de data.c
 */

#ifndef DATA 
#define DATA

#include "definitions.h"

/**
 * \brief Prend en charge la modification des données
 * \param world ensemble des données du monde
*/
void data_update(world_t* world);

/**
 * \brief fonction outdated
 * \param world ensemble des données du monde
*/
void limit_scroll(world_t* world);

/**
 * \brief modifie la position du personnage
 * \param world ensemble des données du monde
*/
void perso_update(world_t* world);

/**
 * \brief test la collision entre le personnage et les blocs qui l'entourent
 * \param world ensemble des données du monde
 * \param perso hitbox du personnage
 * \return 1 si pas de collision 0 si collision
*/
int testCollision(world_t* world, SDL_Rect perso);

/**
 * \brief tente de déplacer le personnage
 * \param world ensemble des données du monde
 * \return 0 si il n'y a pas de collision, 1 sinon
*/
int essai_deplacement_perso(world_t* world);

/**
 * \brief tente de déplacer le personnage pixel par pixel pour le coller à un bloc
 * \param world ensemble des données du monde
 * \param vx vitesse en X
 * \param vy vitesse en Y
 * \return 0 si il n'y a pas de collision, 1 sinon
*/
int essai_deplacement_pixel_perfect(world_t* world, double vx, double vy);

/**
 * \brief libere la mémoire allouée 
 * \param world ensemble des données du monde
 * \param screen surface de rendu de la fenêtre
*/
void liberer_memoire(world_t* world, SDL_Renderer* screen);

/**
 * \brief déplace le personnage pixel par pixel pour le coller à un bloc
 * \param world ensemble des données du monde
*/
void approcher_mur(world_t* world);

/**
 * \brief mets à jour les vitesses du personnage
 * \param pointeur sur le personnage de jeu
*/
void update_speeds(sqr_t* perso);

/**
 * \brief déplace le scroll de façon automatique
 * \param world ensemble des données du monde
*/
void auto_scroll(world_t* world);

/**
 * \brief change les tiles 2 et 4
 * \param world ensemble des données du monde
 */
void change_tiles(world_t* world);

#endif