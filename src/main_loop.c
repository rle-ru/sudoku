#include <SDL2/SDL.h>

#include "sudoku.h"
#include "display.h"
#include "game.h"

int main_loop(t_sudoku *sudoku)
{
	SDL_Event event;
	int quit = 0;

	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				quit = 1;
			else if (event.type == SDL_MOUSEMOTION)
			{
				int x, y;
				SDL_GetMouseState(&x, &y);
				for (int i = 0; i < 9; i++)
				{
					if (x > sudoku->gridPos[i] && x < sudoku->gridPos[i] + CELL_SIZE)
					{
						sudoku->selectedCellX = i;
					}
					if (y > sudoku->gridPos[i] && y < sudoku->gridPos[i] + CELL_SIZE)
					{
						sudoku->selectedCellY = i;
					}
				}
			}
			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					quit = 1;
				else if (event.key.keysym.sym >= SDLK_1 && event.key.keysym.sym <= SDLK_9)
					handle_key_press(sudoku, event.key.keysym.sym - SDLK_0);
			}
		}
		SDL_RenderClear(sudoku->renderer);
		draw_grid(sudoku);
		SDL_RenderPresent(sudoku->renderer);
	}
	return 0;
}