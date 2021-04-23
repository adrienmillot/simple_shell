#include "shell.h"

/**
 * _generateAbsolutePath - Generate an absolute path from environment variable
 *
 * @prmPath: path environment variable
 * @prmCommandName: command name
 *
 * Return: absolute path
 */
char *_generateAbsolutePath(char *prmPath, char *prmCommandName)
{
	char *tmp, *path, *absolutePath, lastCharacter;
	int pathValueSize;

	path = _strdup(prmPath);
	pathValueSize = _strlen(path);
	lastCharacter = path[pathValueSize - 1];

	if (lastCharacter != '/')
	{
		tmp = path;
		path = _strconcat(tmp, "/");
		free(tmp);
	}

	tmp = "";
	tmp = _strconcat(tmp, path);
	absolutePath = _strconcat(tmp, prmCommandName);
	free(tmp);
	free(path);

	return (absolutePath);
}
