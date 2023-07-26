#ifndef SUDOKU_H
#define SUDOKU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct s_sudoku
{

	int grid[9][9];
	int gridClone[9][9];
} t_sudoku;

#endif