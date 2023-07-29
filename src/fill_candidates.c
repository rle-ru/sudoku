#include "sudoku.h"
#include "solver.h"

void fill_candidates(t_sudoku *sudoku, int grid[9][9])
{
	for (int y = 0; y < 9; y++)
		for (int x = 0; x < 9; x++)
		{
			if (grid[y][x] == 0)
			{
				for (int n = 0; n < 9; n++)
					sudoku->megaGrid[y][x][n] = is_valid(grid, x, y, n + 1);
			}
		}
}