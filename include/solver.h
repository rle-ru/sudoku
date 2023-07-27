#ifndef SOLVER_H
#define SOLVER_H

#include "sudoku.h"

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

/*
** Solves the sudoku with human logic.
*/
int idiot_solver(t_sudoku *sudoku, int difficulty);

/*
** Removes numbers from the grid to create a new game.
*/	
void remove_numbers(t_sudoku *sudoku, int difficulty);

/*
**	Fills the candidates array with the possible numbers for each cell.
*/
void fill_candidates(t_sudoku *sudoku, int grid[9][9]);

#endif