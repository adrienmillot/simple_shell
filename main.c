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
void ctrlC(int prmSignal __attribute__((unused)))
{
		write(STDIN_FILENO, "\n", 1);
		write(STDIN_FILENO, PROMPT, 2);
}

/**
 * main - main executable
 *
 * Return: 0 if succeded
 */
int main(void)
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

		/* Split arguments*/
		_parsingArguments(buffer, argv);

		if (argv == NULL || argv[0] == NULL)
			continue;
		else if (_isBuildIn(argv[0]) == 1)
			perror("Custom action to execute !\n");
		else
			_execCmd(argv);

	} while (buffer != NULL);

	if (buffer != NULL && isatty(STDIN_FILENO))
		free(buffer);

	return (EXIT_SUCCESS);
}
