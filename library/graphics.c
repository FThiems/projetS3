/**
 * \file graphics.c
 * \brief Fonctions liées à la gestion des graphismes
 */

#include"headers/graphics.h"

void refresh_graphics(world_t* world, SDL_Renderer* screen){
	SDL_RenderClear(screen);
	afficher_carte(world->map, screen);
	//Afficher le sprite simplement
    SDL_RenderCopy(screen, world->texture_perso, NULL, &world->perso->dest);
    SDL_RenderPresent(screen);

}

void init_graphics(world_t* world, SDL_Renderer* screen){

}

void afficher_carte(map_t* m, SDL_Renderer* screen){
	// SDL_Rect Rect_dest = {0,0,TILE_WIDTH, TILE_HEIGHT};
	// SDL_Rect Rect_src = {0,0, TILE_WIDTH, TILE_HEIGHT};
	// SDL_RenderCopy(screen, m->tileset, &Rect_src, &Rect_dest);
	int i,j;
	SDL_Rect Rect_dest = {0,0,TILE_WIDTH,TILE_HEIGHT};
	int numtile;
	//On définit les coordonnées de notre affichage
	int miniX, maxiX, miniY, maxiY;
	miniX = m->xfenscroll / TILE_WIDTH;
	miniY = m->yfenscroll / TILE_HEIGHT;
	maxiX = (m->xfenscroll + F_WIDTH)/TILE_WIDTH;
	maxiY = (m->yfenscroll + F_HEIGHT)/TILE_HEIGHT;
	for(i=miniX;i<=maxiX;i++){
		for(j=miniY;j<=maxiY;j++){
			Rect_dest.x = i*TILE_WIDTH;
			Rect_dest.y = j*TILE_HEIGHT - m->yfenscroll;
			//Si on oob on affiche le bloc bug
			if (i<0 || i>=m->nbtilesX_monde || j<0 || j>=m->nbtilesY_monde)
				numtile = 1;
			else
				numtile = m->tabNum[i][j];
			SDL_RenderCopy(screen,m->tileset,&(m->tabTile[numtile].rect),&Rect_dest);
		}
	}
}

