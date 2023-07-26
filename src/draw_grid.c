#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "sudoku.h"

void draw_grid(t_sudoku *sudoku)
{
	SDL_RenderCopy(sudoku->renderer, sudoku->gridTexture, NULL, NULL);
	int iprime = 0;
	for (int i = 0; i < 9; i++)
	{
		if (i == 3 || i == 6)
		{
			iprime += 2;
		}
		int jprime = 0;
		for (int j = 0; j < 9; j++)
		{
			if (j == 3 || j == 6)
			{
				jprime += 2;
			}
			if (j == sudoku->selectedCellX && i == sudoku->selectedCellY)
			{
				SDL_Rect rect = {sudoku->gridPos[j], sudoku->gridPos[i], CELL_SIZE, CELL_SIZE};
				SDL_SetRenderDrawColor(sudoku->renderer, 255, 0, 0, 255);
				SDL_RenderFillRect(sudoku->renderer, &rect);
				SDL_SetRenderDrawColor(sudoku->renderer, 0, 0, 0, 255);
			}
			if (sudoku->grid[i][j] != 0)
			{
				SDL_Rect rect = {sudoku->gridPos[j] + CELL_MARGIN, sudoku->gridPos[i] + CELL_MARGIN, FONT_SIZE, FONT_SIZE};
				SDL_RenderCopy(sudoku->renderer, sudoku->cellTextures[sudoku->grid[i][j] - 1], NULL, &rect);
			}
		}
	}
}