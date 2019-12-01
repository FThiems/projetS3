/**
 * \file graphics.c
 * \brief Fonctions liées à la gestion des graphismes
 */

#include"headers/graphics.h"

void refresh_graphics(world_t* world, SDL_Renderer* screen){
	SDL_RenderClear(screen);
	afficher_carte(world->map, screen);
    SDL_RenderCopy(screen, world->texture_perso, NULL, &world->dest);
    SDL_RenderPresent(screen);

}

void init_graphics(world_t* world, SDL_Renderer* screen){

}

void afficher_carte(map_t* m, SDL_Renderer* screen){
	// SDL_Rect Rect_dest = {0,0,TILE_WIDTH,TILE_HEIGHT};
	// SDL_Rect Rect_src = {0,0, TILE_WIDTH, TILE_HEIGHT};
	// SDL_RenderCopy(screen, m->tileset, &Rect_src, &Rect_dest);
	int i,j;
	SDL_Rect Rect_dest = {0,0,TILE_WIDTH,TILE_HEIGHT};
	int numtile;
	for(j=0;j<m->nbtilesY_monde;j++)
	{
		for(i=0;i<m->nbtilesX_monde;i++)
		{
			Rect_dest.x = i*TILE_WIDTH;
			Rect_dest.y = j*TILE_HEIGHT;
			numtile = m->tabNum[i][j];
			SDL_RenderCopy(screen,m->tileset,&(m->tabTile[numtile].rect),&Rect_dest);
			SDL_Rect tmp = m->tabTile[numtile].rect;
		}
	}
}