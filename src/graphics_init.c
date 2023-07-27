#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

#include "sudoku.h"
#include "display.h"

void init_grid_surface(t_sudoku *sudoku)
{
	SDL_Texture *grid = SDL_CreateTexture(sudoku->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WINDOW_WIDTH, WINDOW_HEIGHT);
	SDL_SetRenderTarget(sudoku->renderer, grid);

	SDL_SetRenderDrawColor(sudoku->renderer, 255, 255, 255, 255);
	SDL_RenderClear(sudoku->renderer);
	SDL_SetRenderDrawColor(sudoku->renderer, 0, 0, 0, 255);

	int j = 0;
	for (int i = 1; i < 9; i++)
	{
		if (i == 3 || i == 6)
		{
			for (int k = 0; k < 2; k++)
			{
				SDL_RenderDrawLine(sudoku->renderer, i * CELL_SIZE + i + j + k, 0, i * CELL_SIZE + i + j + k, WINDOW_HEIGHT);
				SDL_RenderDrawLine(sudoku->renderer, 0, i * CELL_SIZE + i + j + k, WINDOW_WIDTH, i * CELL_SIZE + i + j + k);
			}
			j += 2;
		}
		SDL_RenderDrawLine(sudoku->renderer, i * CELL_SIZE + i + j, 0, i * CELL_SIZE + i + j, WINDOW_HEIGHT);
		SDL_RenderDrawLine(sudoku->renderer, 0, i * CELL_SIZE + i + j, WINDOW_WIDTH, i * CELL_SIZE + i + j);
	}

	SDL_SetRenderTarget(sudoku->renderer, NULL);
	sudoku->gridTexture = grid;
}

void init_font(t_sudoku *sudoku)
{
	TTF_Font *font = TTF_OpenFont("./arial.ttf", FONT_SIZE);
	if (!font)
	{
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		exit(1);
	}

	SDL_Color color = {0, 0, 0, 255};
	for (int i = 0; i < 9; i++)
	{
		SDL_Surface *surface = TTF_RenderText_Solid(font, (char[]){i + 49, '\0'}, color);
		sudoku->cellTextures[i] = SDL_CreateTextureFromSurface(sudoku->renderer, surface);
		SDL_FreeSurface(surface);
	}
	TTF_Font *littleFont = TTF_OpenFont("./arial.ttf", LITTLE_FONT_SIZE);
	for (int i = 0; i < 9; i++)
	{
		SDL_Surface *surface = TTF_RenderText_Solid(littleFont, (char[]){i + 49, '\0'}, color);
		sudoku->littleCellTextures[i] = SDL_CreateTextureFromSurface(sudoku->renderer, surface);
		SDL_FreeSurface(surface);
	}

	TTF_CloseFont(font);
	TTF_CloseFont(littleFont);
}

void initGraphics(t_sudoku *sudoku)
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	sudoku->window = SDL_CreateWindow("Sudoku", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	sudoku->renderer = SDL_CreateRenderer(sudoku->window, -1, SDL_RENDERER_ACCELERATED);
	init_grid_surface(sudoku);
	init_font(sudoku);
}

void quitGraphics(t_sudoku *sudoku)
{
	SDL_DestroyRenderer(sudoku->renderer);
	SDL_DestroyWindow(sudoku->window);
	SDL_DestroyTexture(sudoku->gridTexture);
	TTF_Quit();
	SDL_Quit();
	for (int i = 0; i < 9; i++)
	{
		SDL_DestroyTexture(sudoku->cellTextures[i]);
		SDL_DestroyTexture(sudoku->littleCellTextures[i]);
	}
}