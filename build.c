#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * _isBuildIn - check custom command
 *
 * @prmCommandName: command name
 * @prmArguments: argument's array
 * @prmBuffer: buffer
 *
 * Return: true if custom command
 */
int _isBuildIn(char *prmCommandName, char **prmArguments, char *prmBuffer)
{
	int code = EXIT_SUCCESS, cLoop = 0;

	if (_strcmp(prmCommandName, "exit") == 0)
	{
		if (prmArguments[1] != NULL)
			code = _atoi(prmArguments[1]);
		free(prmBuffer);
		_freeDoublePointer(prmArguments);
		exit(code);
	}
	else if (_strcmp(prmCommandName, "env") == 0)
	{
		while(environ[cLoop])
		{
			_puts(environ[cLoop]);
			_putchar('\n');
			cLoop++;
		}
	}
	return (code);
}

/**
 * _execCmd - Execute a command
 *
 * @prmArguments: argument's array
 */
void _execCmd(char *prmArguments[])
{
	pid_t child_pid;
	char *command;
	int status;

	if (prmArguments == NULL || prmArguments[0] == NULL)
		return;

	/* Get the absolute path of the command */
	command = _which(prmArguments[0]);

	if (command != NULL)
	{
		if (prmArguments[0] != command)
			free(prmArguments[0]);
		prmArguments[0] = command;
	}
	else
	{
		return;
	}

	/* Create a child */
	child_pid = fork();
	if (child_pid == 0)
	{
		/* Execute command*/
		if (execve(prmArguments[0], prmArguments, environ) == -1)
			perror(prmArguments[0]);
		return;
	}
	else
		waitpid(child_pid, &status, WUNTRACED);
}
