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
	char *buffer = NULL, **argv = NULL;

	(void) argv;

	do {
		/* Ignore interactive signal */
		signal(SIGINT, ctrlC);

		/* Display prompt */
		write(STDIN_FILENO, PROMPT, 2);

		/* Catch user command*/
		buffer = _getline();

		/* Split arguments*/
		argv = _strtow(buffer, SEPARATORS);

		if (argv == NULL || argv[0] == NULL)
		{
			free(buffer);
			_freeDoublePointer(argv);
			continue;
		}
		else if (_isBuildIn(argv[0], argv, buffer) != 0)
			perror("Custom action to execute !\n");
		else
			_execCmd(argv);

		if (buffer != NULL && isatty(STDIN_FILENO))
			free(buffer);
		if (argv != NULL && isatty(STDIN_FILENO))
			_freeDoublePointer(argv);
	} while (buffer != NULL);

	if (buffer != NULL && isatty(STDIN_FILENO))
		free(buffer);
	if (argv != NULL && isatty(STDIN_FILENO))
		_freeDoublePointer(argv);

	return (EXIT_SUCCESS);
}
