#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "sudoku.h"
#include "init.h"
#include "game.h"

int main(int ac, char **av)
{
	t_sudoku sudoku;

	srand(time(NULL));
	initGraphics(&sudoku);
	if (ac == 1)
	{
		av = av;
	}
	init_new_game(&sudoku, 15);
	int ret = main_loop(&sudoku);
	quitGraphics(&sudoku);

	return ret;
}

#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
#include <windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	hInst = hInst;
	hInstPrev = hInstPrev;
	cmdshow = cmdshow;

	int ac = 1;
	char **av = NULL;

	char exePath[MAX_PATH];
	GetModuleFileName(NULL, exePath, MAX_PATH);
	av = realloc(av, sizeof(char *) * (ac));
	av[0] = exePath;
	char *token = strtok(cmdline, " ");

	while (token != NULL)
	{
		av = realloc(av, sizeof(char *) * (ac + 1));
		av[ac] = token;
		ac++;
		token = strtok(NULL, " ");
	}

	int result = main(ac, av);

	free(av);
	fclose(stdout);
	FreeConsole();

	return result;
}

#endif