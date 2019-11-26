/**
 * \file definitions.h
 * \brief Constantes, structures et includes
 */

#ifndef DEFINITIONS_FILE
#define DEFINITIONS_FILE 

/////////////// IMPORTS //////////////////////

#include <stdbool.h>
#include <SDL2/SDL.h>

//Taille de la fenêtre de jeu
#define F_HEIGHT 750
#define F_WIDTH 1100

//Taille du personnage
#define P_HEIGHT 50
#define P_WIDTH 50

//Taille des blocs du jeu
#define B_HEIGHT 50
#define B_WIDTH 50

//Valeur de la friction
#define FRICT_Y 0

/////////////// STRUCTURES ///////////////////

/**
 * \brief Structure de notre personnage
 */
struct sqr_s
{
	double x, y; /*!< Coordonnées du cube */
	double vx, vy; /*!< Vitesses du cube */
	int w, h; /*!< Hauteur et largeur du cube */
	bool peutSauter; /*!< Vrai si le perso peut sauter, sinon faux */
};
typedef struct sqr_s sqr_t;

/**
 * \brief structure des blocs du jeu
 */
struct bloc_s
{
	double x, y; /*!< Coordonnées du bloc */
	bool estVisible; /*!< Vrai si le bloc est visible, sinon faux */
};
typedef struct bloc_s bloc_t;

/**
 * \brief Structure du monde de jeu
 */
struct world_s
{
	//fin de jeu
	bool gameover;/*!< Variable de fin de jeu */

	//elements du jeu
	sqr_t* perso; /*!< Pointeur sur le personnage de jeu */
	map_t* map; /*!< Pointeur sur la structure qui représente la carte de jeu */

	//elements sdl
	SDL_Rect dest; /*!< SDL_Rect destination du sprite de notre perso */

	//textures du jeu
	SDL_Texture* texture_perso; /*!< Texture du personnage */
	SDL_Texture* tileset; /*!< Texture du monde */
};
typedef struct world_s world_t;

struct map_s
{
	//representation de la map du jeu
	int nbtilesX, nbtilesY;/*!< Nombre de tiles en X et en Y (X*Y total) de la carte de jeu*/
	tile_t** tabTile;/*! */
};
typedef struct map_s map_t;

struct tile_s
{
	SDL_Rect rect;/*!< SDl_Rect source de chaque tile */
	int typeTile;/*!< Type de chaque tile : 0 pour un mur, 1 pour un element traversable */
};
typedef struct tile_s tile_t;

#endif
