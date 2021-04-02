#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * _parsingArguments - split argument's string to array
 *
 * @prmParametersLine: argument's string
 * @prmArgv: argument's array
 */
void _parsingArguments(char *prmParametersLine, char *prmArgv[])
{
	char *strToken, *separators;
	int i = 0;

	separators = " \n";
	strToken = strtok(prmParametersLine, separators);

	while (strToken != NULL && _strcmp(strToken, "\n") != 0)
	{
		prmArgv[i] = strToken;
		strToken = strtok(NULL, separators);
		i++;
	}
	prmArgv[i] = NULL;
}

/**
 * _isBuildIn - check custom command
 *
 * @prmCommandName: command name
 *
 * Return: true if custom command
 */
int _isBuildIn(char *prmCommandName)
{
	if (_strcmp(prmCommandName, "cd") == 0)
		return (1);
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

	if ((child_pid = fork()) == 0)
		if (execve(prmArguments[0], prmArguments, NULL) == -1)
			perror("Error:");
	wait(NULL);
}
