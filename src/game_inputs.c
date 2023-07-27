#include "sudoku.h"
#include "solver.h"

void enter_number(t_sudoku *sudoku, int number)
{
	if (sudoku->grid[sudoku->selectedCellY][sudoku->selectedCellX] == 0)
	{
		if (is_valid(sudoku->grid, sudoku->selectedCellX, sudoku->selectedCellY, number))
			sudoku->grid[sudoku->selectedCellY][sudoku->selectedCellX] = number;
	}
}

void handle_key_press(t_sudoku *sudoku, int key)
{
	if (key >= 0 && key <= 9)
	{
		enter_number(sudoku, key);
	}
}