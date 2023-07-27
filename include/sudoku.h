#ifndef SUDOKU_H
#define SUDOKU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct s_sudoku
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *gridTexture;
	SDL_Texture *cellTextures[9];
	SDL_Texture *littleCellTextures[9];
	int	gridPos[9];

	int range[9];
	int grid[9][9];
	int gridClone[9][9];
	int megaGrid[9][9][9];

	int selectedCellX;
	int selectedCellY;
} t_sudoku;

#endif