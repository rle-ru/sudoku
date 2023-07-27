#include "sudoku.h"
#include "solver.h"

int naked_single(t_sudoku *sudoku, int grid[9][9])
{
	int running = 0;
	for (int y = 0; y < 9; y++)
		for (int x = 0; x < 9; x++)
			if (grid[y][x] == 0)
			{
				int count = 0;
				int value = 0;
				for (int i = 0; i < 9; i++)
					if (sudoku->megaGrid[y][x][i])
					{
						count++;
						value = i + 1;
					}
				if (count == 1)
				{
					grid[y][x] = value;
					running = 1;
				}
			}
	return running;
}

int hidden_single(t_sudoku *sudoku, int grid[9][9])
{
	int running = 0;
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (grid[y][x] == 0)
			{
				for (int n = 0; n < 9; n++)
				{
					if (sudoku->megaGrid[y][x][n])
					{
						int count = 0;
						for (int i = 0; i < 9; i++)
						{
							if (sudoku->megaGrid[y][i][n] || sudoku->megaGrid[i][x][n])
								count++;
						}
						if (count == 1)
						{
							grid[y][x] = n + 1;
							running = 1;
						}
					}
				}
			}
		}
	}
	return running;
}

void fill_candidates(t_sudoku *sudoku, int grid[9][9])
{
	for (int y = 0; y < 9; y++)
		for (int x = 0; x < 9; x++)
			if (grid[y][x] == 0)
			{
				for (int i = 0; i < 9; i++)
					sudoku->megaGrid[y][x][i] = is_valid(grid, x, y, i + 1);
			}
			else
				for (int i = 0; i < 9; i++)
					sudoku->megaGrid[y][x][i] = 0;
}

int idiot_solver(t_sudoku *sudoku, int difficulty)
{
	int x, y;
	int running = 1;
	int segments = 1;

	fill_candidates(sudoku, sudoku->gridClone);
	while (running || segments)
	{
		running = 0;
		segments = 0;
		if (difficulty > 0)
			running += naked_single(sudoku, sudoku->gridClone);
		if (difficulty > 1)
			running += hidden_single(sudoku, sudoku->gridClone);
		// if (difficulty > 2)
		// 	segments += naked_pair(sudoku);
		// if (difficulty > 3)
		// 	segments += hidden_pair(sudoku);
		// if (difficulty > 4)
		// 	segments += naked_triple(sudoku);
		// if (difficulty > 5)
		// 	segments += hidden_triple(sudoku);
		// if (difficulty > 6)
		// 	segments += naked_quad(sudoku);
		// if (difficulty > 7)
		// 	segments += hidden_quad(sudoku);
		// if (difficulty > 8)
		// 	segments += x_wing(sudoku);

		// if (!running)
		// fill_candidates(sudoku, sudoku->gridClone);
	}
	return !find_empty_cell(sudoku->gridClone, &y, &x);
}