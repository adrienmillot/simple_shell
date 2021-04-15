#include "shell.h"

/**
 * _parsingPathEnvironment - split environment variable
 *
 * Return: linked list
 */
environment_t *_parsingPathEnvironment()
{
	char *environmentValue, **pathEnvironment, **paths;
	environment_t *pathList, *new;
	int cLoop = 0;

	environmentValue = _getenv("PATH");
	pathEnvironment = _strtow(environmentValue, ENV_SEPARATOR, NULL);
	paths = _strtow(pathEnvironment[1], PATH_SEPARATOR, NULL);
	while (paths[cLoop] != NULL)
	{
		new = _addEnvNodeEnd(&pathList, environmentValue);

		if (new == NULL)
		{
			_freeEnvList(pathList);
			_freeCharDoublePointer(paths);
			_freeCharDoublePointer(pathEnvironment);
			return (NULL);
		}

		cLoop++;
	}
	_freeCharDoublePointer(pathEnvironment);
	_freeCharDoublePointer(paths);

	return (pathList);
}
