#ifndef GAME_H
#define GAME_H

#include "sudoku.h"

/*
**	draws the grid numbers.
*/
void draw_grid(t_sudoku *sudoku);

/*
**	main game loop.
*/
int main_loop(t_sudoku *sudoku);

/*
**	Handle 1-9 key presses.
*/
void handle_key_press(t_sudoku *sudoku, int key);

#endif