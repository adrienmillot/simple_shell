#include "shell.h"

/**
 * _changeDirectory - change current directory
 *
 * @prmData: data structure
 */
void _changeDirectory(data_t *prmData)
{
	char currentDirectory[500], *newDirectory;
	struct stat st;

	getcwd(currentDirectory, 500);

	if (prmData == NULL)
		return;

	/* Old path */
	if (_strcmp(prmData->arguments[1], "-") == 0)
	{
		newDirectory = _getenvvalue("OLDPWD");

		if (stat(newDirectory, &st) == 0)
		{
			chdir(newDirectory);
			/* set old path environment variable */
			_setenv("OLDPWD", currentDirectory, 1);
			free(newDirectory);
		}
		else
		{
			free(newDirectory);
			perror(newDirectory);
		}
	}
	else if (
		_strcmp(prmData->arguments[1], "~") == 0 ||
		_strcmp(prmData->arguments[1], "~/") == 0
	)
	{
		newDirectory = _getenvvalue("HOME");

		if (stat(newDirectory, &st) == 0)
		{
			chdir(newDirectory);
			/* set old path environment variable */
			_setenv("OLDPWD", currentDirectory, 1);
			free(newDirectory);
		}
		else
		{
			free(newDirectory);
			perror(newDirectory);
		}
	}
	else
	{
		newDirectory = prmData->arguments[1];

		if (stat(newDirectory, &st) == 0)
		{
			chdir(newDirectory);
			/* set old path environment variable */
			_setenv("OLDPWD", currentDirectory, 1);
		}
		else
			perror(newDirectory);
	}
}
