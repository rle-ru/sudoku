#include "sudoku.h"
#include "solver.h"

void count_solver(int grid[9][9], int *count)
{
	int x, y;
	if (find_empty_cell(grid, &y, &x) == 0)
	{
		(*count)++;
		return ;
	}
	for (int i = 1; i <= 9 && *count < 2; i++)
	{
		if (is_valid(grid, x, y, i))
		{
			grid[y][x] = i;
			count_solver(grid, count);
			grid[y][x] = 0;
		}
	}
}