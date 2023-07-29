#include "sudoku.h"
#include "display.h"
#include "init.h"
#include "solver.h"

void init_sudoku(t_sudoku *sudoku)
{
	int i;
	int j;

	for (i = 0; i < 9; i++)
	{
		sudoku->range[i] = i + 1;
		for (j = 0; j < 9; j++)
		{
			sudoku->grid[i][j] = 0;
			sudoku->gridClone[i][j] = 0;
			for (int k = 0; k < 9; k++)
				sudoku->megaGrid[i][j][k] = 0;
		}
		sudoku->gridPos[i] = i * CELL_SIZE + i + 1 + (i > 2 ? 2 : 0) + (i > 5 ? 2 : 0);
	}
	for (i = 0; i < 9; i++)
	{
		j = rand() % 9;
		int temp = sudoku->range[i];
		sudoku->range[i] = sudoku->range[j];
		sudoku->range[j] = temp;
	}
}

void init_new_game(t_sudoku *sudoku, int difficulty)
{
	init_sudoku(sudoku);
	solver(sudoku);
	remove_numbers(sudoku, difficulty);
	fill_candidates(sudoku, sudoku->grid);
	sudoku->clickedNumber = 0;
	sudoku->shiftHeld = 0;
	sudoku->clickedCellX = -1;
	sudoku->clickedCellY = -1;
}