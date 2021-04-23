#include "shell.h"

/**
 * _parsingPathEnvironment - split environment variable
 *
 * @prmData: data structure
 *
 * Return: string array
 */
char **_parsingPathEnvironment(appData_t *prmData)
{
	char **paths;
	environment_t *pathEnvNode;

	pathEnvNode = _getenv(prmData->env, "PATH");
	paths = _strtow(pathEnvNode->value, PATH_SEPARATOR, NULL);

	return (paths);
}
