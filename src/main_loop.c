#include <SDL2/SDL.h>

#include "sudoku.h"

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
		}

		SDL_RenderClear(sudoku->renderer);
		draw_grid(sudoku);
		SDL_RenderPresent(sudoku->renderer);
	}
	return 0;
}