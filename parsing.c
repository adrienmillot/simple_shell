#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shell.h"

/**
 * _parsingString - split string to array
 *
 * @prmString: argument's string
 * @prmSeparator: separators
 * @prmArgv: argument's array
 */
void _parsingString(char *prmString, char *prmSeparator, char *prmArgv[])
{
	char *strToken;
	int i = 0;

	strToken = strtok(prmString, prmSeparator);

	if (strToken == NULL)
		return;

	while (strToken != NULL && _strcmp(strToken, "\n") != 0)
	{
		prmArgv[i] = strToken;
		strToken = strtok(NULL, prmSeparator);

		if (strToken == NULL)
		{
			prmArgv[i + 1] = NULL;
			return;
		}
		i++;
	}
	prmArgv[i] = NULL;
	free(strToken);
}

/**
 * _parsingArguments - split argument's string to array
 *
 * @prmParametersLine: argument's string
 * @prmArgv: argument's array
 */
void _parsingArguments(char *prmParametersLine, char *prmArgv[])
{
	if (prmParametersLine == NULL || prmArgv == NULL)
		return;

	_parsingString(prmParametersLine, SEPARATORS, prmArgv);
}

/**
 * _parsingEnvironment - split environment variable
 *
 * @prmEnvironmentName: environment name
 *
 * Return: linked list
 */
environment_t *_parsingEnvironment(char *prmEnvironmentName)
{
	char *name, *strToken, *environmentVariable, *tmpEnv;
	environment_t *environmentList, *new;
	int sizeEnv;

	environmentList = NULL;
	environmentVariable = _getenv(prmEnvironmentName);

	sizeEnv = _strlen(environmentVariable);
	tmpEnv = malloc(sizeof(char) * sizeEnv + 1);
	if (tmpEnv == NULL)
		return (NULL);
	tmpEnv = _strcpy(tmpEnv, environmentVariable);

	strToken = strtok(tmpEnv, "=");
	(void) strToken;

	if (strToken == NULL)
		return (NULL);

	name = strToken;
	(void) name;

	while (strToken != NULL)
	{
		if (strToken != name)
		{
			new = _addNodeEnd(&environmentList, name, strToken);

			if (new == NULL)
			{
				_freeList(environmentList);
				free(tmpEnv);
				return (NULL);
			}
		}
		strToken = strtok(NULL, ":");
	}
	free(tmpEnv);

	return (environmentList);
}
