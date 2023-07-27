#ifndef INIT_H
#define INIT_H

#include "sudoku.h"

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
**	Initializes a new game.
*/
void init_new_game(t_sudoku *sudoku, int difficulty);

#endif