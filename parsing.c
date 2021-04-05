#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shell.h"

/**
 * _parsingString - split string to array
 *
 * @prmString: argument's string
 * @prmSeparator: separators
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
	environment_t *environmentList;
	int sizeEnv;

	environmentList = NULL;
	environmentVariable = _getenv(prmEnvironmentName);

	sizeEnv = _strlen(environmentVariable);
	tmpEnv = malloc(sizeof(char) * sizeEnv + 1);
	if (tmpEnv == NULL)
		return (NULL);
	tmpEnv = _strcpy(tmpEnv, environmentVariable);

	strToken = strtok(tmpEnv, "=");

	if (strToken == NULL)
		return (NULL);

	name = strToken;

	while (strToken != NULL)
	{
		if (strToken != name)
		{
			_addNodeEnd(&environmentList, name, strToken);
		}
		strToken = strtok(NULL, ":");
	}
	free(tmpEnv);

	return (environmentList);
}

/**
 * _strtok - split a string
 *
 * @prmString:
 * @prmSeparators:
 *
 * Return: First occurence
 */
/*char *_strtok_r(char *str, const char *delim, char **saveptr)
{
	int cLoop = 0, cLoop2 = 0;
	char *token = "";

	if (prmString == NULL && prmSavePtr == NULL)
		return (NULL);

	if (prmString != NULL)
	{
		while (prmString[cLoop] != '\0')
		{
			while(prmSeparators[cLoop2] != '\0')
			{
				if (prmString[cLoop] == prmSeparators[cLoop2])
				{
					_strncat(token, prmString, cLoop);

					return (token);
				}
				cLoop2++;
			}
			cLoop++;
		}
	}
}*/
