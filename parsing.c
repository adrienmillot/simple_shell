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
	char *strToken, **savePtr;
	int i = 0;

	savePtr = malloc(sizeof(char *) * 100);

	/*strToken = strtok(prmString, prmSeparator);*/
	strToken = _strtok(prmString, prmSeparator, savePtr);

	if (strToken == NULL)
		return;

	while (strToken != NULL && _strcmp(strToken, "\n") != 0)
	{
		prmArgv[i] = strToken;
		/*strToken = strtok(NULL, prmSeparator);*/
		strToken = _strtok(NULL, prmSeparator, savePtr);

		if (strToken == NULL)
		{
			prmArgv[i + 1] = NULL;
			return;
		}
		i++;
	}
	prmArgv[i] = NULL;
	free(strToken);
	_freeDoublePointer(savePtr);
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
	char *name, *strToken, *environmentVariable, *tmpEnv, *savePtr;
	environment_t *environmentList, *new;

	environmentList = NULL;
	environmentVariable = _getenv(prmEnvironmentName);
	tmpEnv = _strdup(environmentVariable);
	strToken = _strtok(tmpEnv, ENV_SEPARATOR, &savePtr);

	if (strToken == NULL)
		return (NULL);

	name = tmpEnv;
	if (tmpEnv != NULL)

	while (strToken != NULL)
	{
		if (_strcmp(strToken, "") == 0)
		{
			strToken = ".";
			continue;
		}
		if (strToken != name)
		{
			new = _addNodeEnd(&environmentList, name, strToken);

			if (new == NULL)
			{
				_freeList(environmentList);
				free(strToken);
				free(tmpEnv);
				return (NULL);
			}
		}
		/*strToken = strtok(NULL, PATH_SEPARATOR);*/
		strToken = _strtok(NULL, PATH_SEPARATOR, &savePtr);
	}
	free(tmpEnv);

	return (environmentList);
}
