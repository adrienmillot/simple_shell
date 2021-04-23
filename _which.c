#include "shell.h"

/**
 * _which - return absolute path of a command
 *
 * @prmData: app data structure
 *
 * Return: absolute path
 */
char *_which(appData_t *prmData)
{
	char **pathList, *absolutePath;
	struct stat st;
	int cLoop = 0;

	if (
		prmData->commandName[0] == '.' &&
		prmData->commandName[1] == '/' &&
		stat(prmData->commandName, &st) == 0
	)
		return (prmData->commandName);

	pathList = _parsingPathEnvironment(prmData);

	if (pathList == NULL)
		return (NULL);

	while (pathList[cLoop] != NULL)
	{
		absolutePath = _generateAbsolutePath(pathList[cLoop], prmData->commandName);

		/* Check if absolute path exist */
		if (stat(absolutePath, &st) == 0)
		{
			_freeCharDoublePointer(pathList);
			return (absolutePath);
		}
		free(absolutePath);
		cLoop++;
	}
	_freeCharDoublePointer(pathList);

	/* Try to find the command */
	if (stat(prmData->commandName, &st) == 0)
	{
		return (prmData->commandName);
	}
	else
		_errorHandler(prmData, 101);

	return (NULL);
}
