#include "sudoku.h"
#include "solver.h"
#include "bool.h"
#include "game.h"

int solver(t_sudoku *sudoku)
{
	// SDL_RenderClear(sudoku->renderer);
	// draw_grid(sudoku);
	// SDL_RenderPresent(sudoku->renderer);

	int x, y;
	if (find_empty_cell(sudoku->grid, &y, &x) == FALSE)
		return TRUE;
	for (int n = 0; n < 9; n++)
	{
		if (is_valid(sudoku->grid, x, y, sudoku->range[n]) == TRUE)
		{
			sudoku->grid[y][x] = sudoku->range[n];
			if (solver(sudoku))
				return TRUE;
			sudoku->grid[y][x] = 0;
		}
	}
	return FALSE;
}