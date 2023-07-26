#include "sudoku.h"

int find_empty_cell(int grid[9][9], int *row, int *col)
{
	for (*row = 0; *row < 9; (*row)++)
	{
		for (*col = 0; *col < 9; (*col)++)
		{
			if (grid[*row][*col] == 0)
				return 1;
		}
	}
	return 0;
}