#include "sudoku.h"
#include "solver.h"

void handle_key_press(t_sudoku *sudoku, int key)
{
	if (sudoku->grid[sudoku->clickedCellY][sudoku->clickedCellX] == 0)
	{
		if (sudoku->shiftHeld == 1)
		{
			if (is_valid(sudoku->grid, sudoku->clickedCellX, sudoku->clickedCellY, key))
			{
				sudoku->megaGrid[sudoku->clickedCellY][sudoku->clickedCellX][key - 1] ^= 1;
			}
		}
		else
		{
			if (is_valid(sudoku->grid, sudoku->clickedCellX, sudoku->clickedCellY, key))
			{
				sudoku->grid[sudoku->clickedCellY][sudoku->clickedCellX] = key;
				sudoku->clickedNumber = key;
				for (int i = 0; i < 9; i++)
				{
					if (i != sudoku->clickedCellX)
					{
						sudoku->megaGrid[sudoku->clickedCellY][i][key - 1] = 0;
					}
					if (i != sudoku->clickedCellY)
					{
						sudoku->megaGrid[i][sudoku->clickedCellX][key - 1] = 0;
					}
				}
				int a = sudoku->clickedCellX / 3 * 3;
				int b = sudoku->clickedCellY / 3 * 3;
				for (int i = b; i < b + 3; i++)
				{
					for (int j = a; j < a + 3; j++)
					{
						if (i != sudoku->clickedCellY && j != sudoku->clickedCellX)
						{
							sudoku->megaGrid[i][j][key - 1] = 0;
						}
					}
				}
			}
		}
	}
}