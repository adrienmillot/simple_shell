#include "shell.h"

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
		prmPaths->value = _strconcat(tmp, "/");
		free(tmp);
	}

	tmp = "";
	tmp = _strconcat(tmp, prmPaths->value);
	absolutePath = _strconcat(tmp, prmCommandName);
	free(tmp);

	return (absolutePath);
}
