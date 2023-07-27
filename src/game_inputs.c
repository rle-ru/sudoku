#include "sudoku.h"
#include "solver.h"

void handle_key_press(t_sudoku *sudoku, int key)
{
	if (sudoku->grid[sudoku->selectedCellY][sudoku->selectedCellX] == 0)
	{
		if (is_valid(sudoku->grid, sudoku->selectedCellX, sudoku->selectedCellY, key))
			sudoku->grid[sudoku->selectedCellY][sudoku->selectedCellX] = key;
	}
	fill_candidates(sudoku, sudoku->grid);
}