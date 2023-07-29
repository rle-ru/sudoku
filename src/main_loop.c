#include <SDL2/SDL.h>

#include "sudoku.h"
#include "display.h"
#include "game.h"
#include "solver.h"

#include <stdio.h>
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
			else if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				sudoku->clickedCellX = sudoku->selectedCellX;
				sudoku->clickedCellY = sudoku->selectedCellY;
				if (sudoku->grid[sudoku->clickedCellY][sudoku->clickedCellX] != 0)
					sudoku->clickedNumber = sudoku->grid[sudoku->clickedCellY][sudoku->clickedCellX];
			}
			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					quit = 1;
				else if (event.key.keysym.sym >= SDLK_1 && event.key.keysym.sym <= SDLK_9)
					handle_key_press(sudoku, event.key.keysym.sym - SDLK_0);
				else if (event.key.keysym.sym >= 1073741913 && event.key.keysym.sym <= 1073741921)
					handle_key_press(sudoku, event.key.keysym.sym - 1073741912);
				else if (event.key.keysym.sym == SDLK_LSHIFT || event.key.keysym.sym == SDLK_RSHIFT)
					sudoku->shiftHeld = 1;
				else if (event.key.keysym.sym == 127 || event.key.keysym.sym == SDLK_BACKSPACE)
				{
					int tmp = sudoku->clickedNumber;
					sudoku->grid[sudoku->clickedCellY][sudoku->clickedCellX] = 0;
					for (int a = 0; a < 9; a++)
					{
						sudoku->megaGrid[a][sudoku->clickedCellX][tmp - 1] = is_valid(sudoku->grid, sudoku->clickedCellX, a, tmp);
						sudoku->megaGrid[sudoku->clickedCellY][a][tmp - 1] = is_valid(sudoku->grid, a, sudoku->clickedCellY, tmp);
					}
				}
				else if ((event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.scancode == SDL_SCANCODE_D))
				{
					if (sudoku->clickedCellX < 8 && sudoku->clickedCellX >= 0)
					{
						sudoku->clickedCellX++;
						if (sudoku->grid[sudoku->clickedCellY][sudoku->clickedCellX] != 0)
							sudoku->clickedNumber = sudoku->grid[sudoku->clickedCellY][sudoku->clickedCellX];
					}
				}
				else if ((event.key.keysym.sym == SDLK_LEFT || event.key.keysym.scancode == SDL_SCANCODE_A))
				{
					if (sudoku->clickedCellX > 0 && sudoku->clickedCellX <= 8)
					{
						sudoku->clickedCellX--;
						if (sudoku->grid[sudoku->clickedCellY][sudoku->clickedCellX] != 0)
							sudoku->clickedNumber = sudoku->grid[sudoku->clickedCellY][sudoku->clickedCellX];
					}
				}
				else if ((event.key.keysym.sym == SDLK_UP || event.key.keysym.scancode == SDL_SCANCODE_W))
				{
					if (sudoku->clickedCellY > 0 && sudoku->clickedCellY <= 8)
					{
						sudoku->clickedCellY--;
						if (sudoku->grid[sudoku->clickedCellY][sudoku->clickedCellX] != 0)
							sudoku->clickedNumber = sudoku->grid[sudoku->clickedCellY][sudoku->clickedCellX];
					}
				}
				else if ((event.key.keysym.sym == SDLK_DOWN || event.key.keysym.scancode == SDL_SCANCODE_S))
				{
					if (sudoku->clickedCellY < 8 && sudoku->clickedCellY >= 0)
					{
						sudoku->clickedCellY++;
						if (sudoku->grid[sudoku->clickedCellY][sudoku->clickedCellX] != 0)
							sudoku->clickedNumber = sudoku->grid[sudoku->clickedCellY][sudoku->clickedCellX];
					}
				}
				// else if (event.key.keysym.sym == SDLK_SPACE)
				// {
				// 	solver(sudoku);
				// }
				// else if (event.key.keysym.sym == SDLK_RETURN)
				// {
				// 	init_new_game(sudoku, 0);
				// }
				// else if (event.key.keysym.sym == SDLK_RETURN)
				// 	init_new_game(sudoku, 0
				else
				{
					printf("Key pressed: %d\n", event.key.keysym.sym);
				}
			}
			else if (event.type == SDL_KEYUP)
			{
				if (event.key.keysym.sym == SDLK_LSHIFT || event.key.keysym.sym == SDLK_RSHIFT)
					sudoku->shiftHeld = 0;
			}
		}
		SDL_RenderClear(sudoku->renderer);
		draw_grid(sudoku);
		SDL_RenderPresent(sudoku->renderer);
	}
	return 0;
}