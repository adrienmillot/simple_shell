#include "shell.h"

/**
 * _changeToAnyDirectory - change to any directory
 *
 * @prmData: data structure
 * @prmCurrentDirectory: current directory path
 */
void _changeToAnyDirectory(appData_t *prmData, char *prmCurrentDirectory)
{
	struct stat st;
	char *newDirectory;

	newDirectory = prmData->arguments[1];

	if (stat(newDirectory, &st) == 0)
	{
		chdir(newDirectory);
		/* set old path environment variable */
		_setenv("OLDPWD", prmCurrentDirectory, 1);
	}
	else
		perror(newDirectory);
}
