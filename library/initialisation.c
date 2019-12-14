/**
 * \file initialisation.c
 * \brief fonctions d'initialisation des données
 */

#include "headers/initialisation.h"

void init_world(world_t* world, SDL_Renderer* screen){
	world->gameover = false;
	world->perso = init_perso();
	SDL_Surface* image_perso = SDL_LoadBMP("ressources/bitmaps/redsqr2.bmp");
	world->texture_perso = SDL_CreateTextureFromSurface(screen, image_perso);
  SDL_FreeSurface(image_perso);
  world->map = charger_map(world, screen);
}

sqr_t* init_perso(){
	sqr_t* cube = calloc(1,sizeof(sqr_t));
	cube->h = P_HEIGHT;
  cube->w = P_WIDTH;
  SDL_Rect dest = {F_WIDTH/2 - cube->w/2, F_HEIGHT - (P_HEIGHT +1)*2, cube->w, cube->h};
  cube->dest = dest;
  cube->vx = 0.0;
  cube->vy = 2.0;
  cube->peutSauter = true;
  return cube;
}

SDL_Renderer* init_sdl(){
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
    
  SDL_Renderer *pRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);

	return pRenderer;
}

map_t* charger_map(world_t* world, SDL_Renderer* screen){

  FILE* F = fopen("level.txt", "r");
  map_t* map = calloc(1, sizeof(map_t));

  if(!F){
    printf("fichier introuvable");
    SDL_Quit();
    exit(-1);
  }

  charger_tileset(F, map, screen);
  charger_level(F, map);
  fclose(F);
  map->xfenscroll = 0;
  map->yfenscroll = map->nbtilesY_monde*TILE_HEIGHT - F_HEIGHT;
  return map;
}

void charger_tileset(FILE* F, map_t* m, SDL_Renderer* screen){

  int numtile,i,j;
  char buf[1000]; //stocke l'info du fichier
  char buf2[1000]; 
  fscanf(F,"%s",buf); // #tileset
  fscanf(F,"%s",buf); // nom du fichier

  SDL_Surface* tmp = SDL_LoadBMP(TILESHEET_NAME);
  if (tmp==NULL)
  {
    printf("Image introuvable !! \n");
    SDL_Quit();
    exit(-1);
  }
  m->tileset = SDL_CreateTextureFromSurface(screen, tmp);
  SDL_FreeSurface(tmp);

  fscanf(F,"%d %d",&m->nbtilesX,&m->nbtilesY);
  // printf(" %d %d\n",m->nbtilesX, m->nbtilesY);
  //Pas utile dans ce cas où on code les dimensions en dur
  // Uint32 format;
  // int access = 0;
  // int largeur = 0;
  // int hauteur = 0;

  // SDL_QueryTexture(m->tileset,&format, &access, &largeur, &hauteur);

  m->tabTile = malloc(m->nbtilesX*m->nbtilesY*sizeof(tile_t));
  for(j=0,numtile=0;j<m->nbtilesY;j++)
  {
    for(i=0;i<m->nbtilesX;i++,numtile++)
    {
      m->tabTile[numtile].rect.w = TILE_WIDTH;
      m->tabTile[numtile].rect.h = TILE_HEIGHT;
      m->tabTile[numtile].rect.x = i*TILE_WIDTH;
      m->tabTile[numtile].rect.y = j*TILE_HEIGHT;
      fscanf(F,"%s %s",buf,buf2);
      m->tabTile[numtile].typeTile = 1;
      if (strcmp(buf2,"plein")==0)
        m->tabTile[numtile].typeTile = 0;
    }
  }
  // for(i = 0; i < m->nbtilesX*m->nbtilesY; i++){
  //   printf("rectx : %d recty : %d rectw : %d recth : %d\n",m->tabTile[i].rect.x,m->tabTile[i].rect.y,m->tabTile[i].rect.w,m->tabTile[i].rect.h);
  // }
  // for(i = 0; i < m->nbtilesX*m->nbtilesY; i++){
  //   printf("%d\n", m->tabTile[i].typeTile);
  // }
}

void charger_level(FILE* F,map_t* m)
{
  int i,j;
  char buf[1000];  // stocke l'info du fichier
  fscanf(F,"%s",buf); // #level
  fscanf(F,"%d %d",&m->nbtilesX_monde,&m->nbtilesY_monde);
  m->tabNum = malloc(m->nbtilesX_monde*sizeof(int*));

  for(i=0;i<m->nbtilesX_monde;i++){
    m->tabNum[i] = malloc(m->nbtilesY_monde*sizeof(int));
  }

  for(j=0;j<m->nbtilesY_monde;j++)
  {
    for(i=0;i<m->nbtilesX_monde;i++)
    {
      int tmp;
      fscanf(F,"%d",&tmp);
      if (tmp>=m->nbtilesX*m->nbtilesY)
      {
        printf("level tile hors limite\n");
        SDL_Quit();
        exit(-1);
      }
      m->tabNum[i][j] = tmp;
    }
  }
  // for(i = 0; i < m->nbtilesX_monde; i++){
  //   for(j = 0; j < m->nbtilesY_monde; j++){
  //     printf("%d",m->tabNum[i][j]);
  //   }
  //   printf("\n");
  // }

}