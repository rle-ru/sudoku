#include "sudoku.h"

int solver(t_sudoku *sudoku)
{
	SDL_RenderClear(sudoku->renderer);
	draw_grid(sudoku);
	SDL_RenderPresent(sudoku->renderer);

	int x, y;
	if (!find_empty_cell(sudoku->grid, &y, &x))
		return 1;
	for (int n = 0; n < 9; n++)
	{
		if (is_valid(sudoku->grid, x, y, sudoku->range[n]))
		{
			sudoku->grid[y][x] = sudoku->range[n];
			if (solver(sudoku))
				return 1;
			sudoku->grid[y][x] = 0;
		}
	}
	return 0;
}