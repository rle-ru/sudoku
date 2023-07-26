#include <windows.h>
#include <stdio.h>

#include "sudoku.h"

int main(int ac, char **av)
{
	if (ac == 1)
	{
		printf("Welcome to %s!\n", av[0]);
	}
	return 0;
}

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