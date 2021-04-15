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
	environment_t *pathList;
	char *absolutePath;
	struct stat st;

	pathList = _parsingPathEnvironment(prmData);

	if (pathList == NULL)
		return (NULL);

	if (
		prmData->commandName[0] == '.' &&
		prmData->commandName[1] == '/' &&
		stat(prmData->commandName, &st) == 0
	)
		return (prmData->commandName);

	while (pathList != NULL)
	{
		absolutePath = _generateAbsolutePath(pathList, prmData->commandName);

		/* Check if absolute path exist */
		if (stat(absolutePath, &st) == 0)
		{
			_freeEnvList(pathList);
			return (absolutePath);
		}
		free(absolutePath);
		pathList = pathList->next;
	}
	_freeEnvList(pathList);

	/* Try to find the command */
	if (stat(prmData->commandName, &st) == 0)
	{
		return (prmData->commandName);
	}
	else
		perror(prmData->commandName);

	return (NULL);
}
