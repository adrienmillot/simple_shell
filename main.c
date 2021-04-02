#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"

/**
 * main - main executable
 *
 * Return: 0 if succeded
 */
int main(int prmArgc __attribute__((unused)), char *prmArgv[] __attribute__((unused)), char *prmEnv[] __attribute__((unused)))
{
	char *buffer = NULL, *argv[5];
	size_t bufferSize = 0;
	int endOfFile;

	do {
		/* Ignore interactive signal */
		signal(SIGINT, SIG_IGN);

		/* Display prompt */
		write(1, "$ ", 2);

		/* Catch user command*/
		endOfFile = getline(&buffer, &bufferSize, stdin);

		/* Split arguments*/
		_parsingArguments(buffer, argv);

		if (argv[0] == NULL)
			perror("Command not found !\n");
		else if (_isBuildIn(argv[0]) == 1)
			perror("Custom action to execute !\n");
		else
			_execCmd(argv);

	} while (buffer != NULL && endOfFile != -1);

	free(buffer);
	printf("exit success !\n");

	return (EXIT_SUCCESS);
}
