#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "sudoku.h"
#include "display.h"

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
			if (j == sudoku->clickedCellX && i == sudoku->clickedCellY)
			{
				SDL_Rect rect = {sudoku->gridPos[j], sudoku->gridPos[i], CELL_SIZE, CELL_SIZE};
				SDL_SetRenderDrawColor(sudoku->renderer, 255, 0, 0, 255);
				SDL_RenderFillRect(sudoku->renderer, &rect);
			}
			else if (sudoku->grid[i][j] == sudoku->clickedNumber && sudoku->clickedNumber)
			{
				SDL_Rect rect = {sudoku->gridPos[j], sudoku->gridPos[i], CELL_SIZE, CELL_SIZE};
				SDL_SetRenderDrawColor(sudoku->renderer, 0, 155, 0, 255);
				SDL_RenderFillRect(sudoku->renderer, &rect);
			}
			else if (sudoku->megaGrid[i][j][sudoku->clickedNumber - 1] && sudoku->clickedNumber != 0 && !sudoku->grid[i][j])
			{
				SDL_Rect rect = {sudoku->gridPos[j], sudoku->gridPos[i], CELL_SIZE, CELL_SIZE};
				SDL_SetRenderDrawColor(sudoku->renderer, 0, 255, 0, 255);
				SDL_RenderFillRect(sudoku->renderer, &rect);

			}
			if (sudoku->grid[i][j] != 0)
			{
				SDL_Rect rect = {sudoku->gridPos[j] + CELL_MARGIN, sudoku->gridPos[i] + CELL_MARGIN, FONT_SIZE, FONT_SIZE};
				SDL_RenderCopy(sudoku->renderer, sudoku->cellTextures[sudoku->grid[i][j] - 1], NULL, &rect);
			}
			else
			{
				for (int k = 0; k < 9; k++)
				{
					if (sudoku->megaGrid[i][j][k] == 0)
						continue;
					int startx = sudoku->gridPos[j] + (LITTLE_FONT_SIZE * (k % 3)) + CELL_MARGIN;
					int starty = sudoku->gridPos[i] + (LITTLE_FONT_SIZE * (k / 3)) + CELL_MARGIN;
					SDL_Rect rect = {startx, starty, LITTLE_FONT_SIZE, LITTLE_FONT_SIZE};
					SDL_RenderCopy(sudoku->renderer, sudoku->littleCellTextures[k], NULL, &rect);
				}
			}
		}
	}
}