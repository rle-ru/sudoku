#ifndef SUDOKU_H
#define SUDOKU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define CELL_SIZE 50
#define CELL_MARGIN 5
#define GRID_SIZE ((CELL_SIZE * 9) + 8 + 4)
#define FONT_SIZE (CELL_SIZE - CELL_MARGIN * 2)
#define WINDOW_WIDTH (GRID_SIZE)
#define WINDOW_HEIGHT (GRID_SIZE)

typedef struct s_sudoku
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *gridTexture;
	SDL_Texture *cellTextures[9];

	int range[9];
	int grid[9][9];
	int gridClone[9][9];
	int megaGrid[9][9][9];
} t_sudoku;

/*
**	Initializes SDL, TTF and creates the window and renderer.
*/
void initGraphics(t_sudoku *sudoku);

/*
** Destroys the window and renderer, and quits SDL and TTF.
*/
void quitGraphics(t_sudoku *sudoku);

/*
**	Initializes the sudoku grid.
*/
void init_sudoku(t_sudoku *sudoku);

/*
**	main game loop.
*/
int main_loop(t_sudoku *sudoku);

/*
**	Draws the sudoku grid.
*/
void draw_grid(t_sudoku *sudoku);

/*
**	finds the next empty cell in the grid.
*/
int find_empty_cell(int grid[9][9], int *row, int *col);

/*
**	Checks if a number is valid in a given cell.
*/
int is_valid(int grid[9][9], int row, int col, int num);

/*
**	Backtracking algorithm to solve the sudoku.
*/
int solver(t_sudoku *sudoku);

#endif