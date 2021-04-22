#include "shell.h"

/**
 * _initData - init data structure
 *
 * Return: data structure
 */
appData_t *_initData(void)
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
	_initEnvData(appData);

	return (appData);
}
