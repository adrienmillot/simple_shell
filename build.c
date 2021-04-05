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
 *
 * Return: true if custom command
 */
int _isBuildIn(char *prmCommandName)
{
	if (_strcmp(prmCommandName, "exit") == 0)
		exit(EXIT_SUCCESS);
	return (0);
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
		prmArguments[0] = command;

	/* Create a child */
	child_pid = fork();
	if (child_pid == 0)
	{
		/* Execute command*/
		if (execve(prmArguments[0], prmArguments, environ) == -1)
			perror(prmArguments[0]);
		exit(0);
	}
	else
		waitpid(child_pid, &status, WUNTRACED);
	free(command);
}
