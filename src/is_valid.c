#include "sudoku.h"

int is_valid(int grid[9][9], int x, int y, int n)
{
	for (int i = 0; i < 9; i++)
	{
		if (grid[y][i] == n || grid[i][x] == n)
			return 0;
	}
	int x0 = (x / 3) * 3;
	int y0 = (y / 3) * 3;
	for (int i = y0; i < y0 + 3; i++)
	{
		for (int j = x0; j < x0 + 3; j++)
		{
			if (grid[i][j] == n)
				return 0;
		}
	}
	return 1;
}