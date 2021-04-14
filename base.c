#include "shell.h"

/**
 * _which - get path value of a command
 *
 * @prmCommandName: command name
 *
 * Return: absolute path of a command
 */
char *_which(char *prmCommandName)
{
	char *absolutePath = "";
	struct stat st;
	environment_t *paths, *tmpPaths;
	/*int pathValueSize;*/

	if (prmCommandName == NULL)
		return (NULL);

	paths = _parsingEnvironment("PATH");

	if (paths == NULL)
		return (NULL);

	tmpPaths = paths;

	if (prmCommandName[0] == '.' && prmCommandName[1] == '/' && stat(prmCommandName, &st) == 0)
		return (prmCommandName);

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
	{
		return (prmCommandName);
	}
	else
		perror(prmCommandName);

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
