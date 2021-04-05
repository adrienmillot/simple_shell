#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"

/**
 * ctrlC - control c managment
 *
 * @prmSignal: signal value
 */
void ctrlC(int prmSignal)
{
	if (prmSignal == SIGINT)
	{
		write(STDIN_FILENO, "\n", 1);
		write(STDIN_FILENO, PROMPT, 2);
	}
}

/**
 * main - main executable
 *
 * @prmArgc:
 * @prmArgv:
 * @prmEnv:
 *
 * Return: 0 if succeded
 */
int main()
{
	char *buffer = NULL, *argv[5];
	size_t bufferSize = 0;

	do {
		/* Ignore interactive signal */
		signal(SIGINT, ctrlC);

		/* Display prompt */
		write(STDIN_FILENO, PROMPT, 2);

		/* Catch user command*/
		if (getline(&buffer, &bufferSize, stdin) == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDIN_FILENO, "\n", 1);
			break;
		}

		if (_strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}

		/* Split arguments*/
		_parsingArguments(buffer, argv);

		if (argv == NULL || argv[0] == NULL)
			perror("Command not found !\n");
		else if (_isBuildIn(argv[0]) == 1)
			perror("Custom action to execute !\n");
		else
			_execCmd(argv);

	} while (buffer != NULL);

	free(buffer);

	return (EXIT_SUCCESS);
}
