#include "shell.h"

/**
 * _initData - init data structure
 *
 * Return: data structure
 */
appData_t *_initData(char **prmArgv)
{
	appData_t *appData;

	appData = malloc(sizeof(appData_t) * 1);

	if (appData == NULL)
		return (NULL);

	appData->arguments = NULL;
	appData->buffer = NULL;
	appData->commandName = NULL;
	appData->commandList = NULL;
	appData->history = NULL;
	appData->env = NULL;
	appData->programName = (prmArgv[0] != NULL) ? prmArgv[0] : NULL;
	_initEnvData(appData);

	return (appData);
}
