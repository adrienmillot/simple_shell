
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
 * @prmEnvironmentName: environment variable name
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
 * @prmCommandName: command name
 *
 * Return: absolute path of a command
 */
char *_which(char *prmCommandName)
{
	char *absolutePath = ""/*, lastCharacter, *tmpAbsolutePath*/;
	struct stat st;
	environment_t *paths, *tmpPaths;
	/*int pathValueSize;*/

	if (prmCommandName == NULL)
		exit(EXIT_FAILURE);

	paths = _parsingEnvironment("PATH");

	if (paths == NULL)
		return (NULL);

	tmpPaths = paths;

	while (tmpPaths != NULL)
	{
		absolutePath = _generateAbsolutePath(tmpPaths, prmCommandName);

		/* Check if absolute path exist */
		if (stat(absolutePath, &st) == 0)
		{
			_freeList(paths);
			return (absolutePath);
		}
		free(absolutePath);
		tmpPaths = tmpPaths->next;
	}
	_freeList(paths);

	/* Try to find the command */
	if (stat(prmCommandName, &st) == 0)
		return (prmCommandName);

	return (NULL);
}

/**
 * _generateAbsolutePath - Generate an absolute path from environment variable
 *
 * @prmPaths: path environment variable
 * @prmCommandName: command name
 *
 * Return: absolute path
 */
char *_generateAbsolutePath(environment_t *prmPaths, char *prmCommandName)
{
	char *tmp, *absolutePath, lastCharacter;
	int pathValueSize;

	pathValueSize = _strlen(prmPaths->value);
	lastCharacter = prmPaths->value[pathValueSize - 1];

	if (lastCharacter != '/')
	{
		tmp = prmPaths->value;
		prmPaths->value = _str_concat(tmp, "/");
		free(tmp);
	}

	tmp = "";
	tmp = _str_concat(tmp, prmPaths->value);
	absolutePath = _str_concat(tmp, prmCommandName);
	free(tmp);

	return (absolutePath);
}
