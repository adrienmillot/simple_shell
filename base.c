#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

/**
 * _getenv - get envioronment variable
 *
 * @prmEnvironment: environment variable name
 *
 * Return: environment variable value
 */
char *_getenv(char *prmEnvironmentName)
{
	int cLoop = 0;

	while (environ[cLoop] != NULL)
	{
		if (_strstr(environ[cLoop], prmEnvironmentName, 1) != NULL)
		{
			return (environ[cLoop]);
		}
		cLoop++;
	}

	return (NULL);
}

/**
 * _which - get path value of a command
 *
 * @prmCommandName:
 *
 * Return:
 */
char *_which(char *prmCommandName)
{
	char *absolutePath = "";
	struct stat st;
	environment_t *paths;
	char lastCharacter;
	int pathValueSize;

	if (prmCommandName == NULL)
		exit(EXIT_FAILURE);

	/* Try to find the command */
	if (stat(prmCommandName, &st) != 0)
	{
		paths = _parsingEnvironment("PATH");

		if (paths == NULL)
			return (NULL);

		while (paths != NULL)
		{
			if (paths->value == NULL)
				return (NULL);
			pathValueSize = _strlen(paths->value);
			lastCharacter = paths->value[pathValueSize - 1];
			
			if (lastCharacter != '/')
				paths->value = _str_concat(paths->value, "/");

			absolutePath = "";
			absolutePath = _str_concat(absolutePath, paths->value);
			absolutePath = _str_concat(absolutePath, prmCommandName);

			if (stat(absolutePath, &st) == 0)
			{
				return (absolutePath);
			}
			free(absolutePath);
			paths = paths->next;
		}
		_freeList(paths);
	}
	else
	{
		return (prmCommandName);
	}

	return (NULL);
}
