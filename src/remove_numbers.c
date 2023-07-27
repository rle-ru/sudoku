#include <stdlib.h>

#include "sudoku.h"
#include "solver.h"

void remove_numbers(t_sudoku *sudoku, int difficulty)
{
	for (int i = 0; i < 81; i++)
	{
		int x = rand() % 9;
		int y = rand() % 9;
		if (sudoku->grid[y][x] == 0)
		{
			i--;
			continue;
		}
		int tmp = sudoku->grid[y][x];
		sudoku->grid[y][x] = 0;

		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				sudoku->gridClone[i][j] = sudoku->grid[i][j];

		if (idiot_solver(sudoku, difficulty) == 0)
		{
			sudoku->grid[y][x] = tmp;
		}
	}
}