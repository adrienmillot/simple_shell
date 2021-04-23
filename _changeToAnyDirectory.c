#include "shell.h"

/**
 * _changeToAnyDirectory - change to any directory
 *
 * @prmData: data structure
 * @prmCurrentDirectory: current directory path
 */
void _changeToAnyDirectory(appData_t *prmData, char *prmCurrentDirectory)
{
	char *newDirectory;

	newDirectory = prmData->arguments[1];

	if (access(newDirectory, R_OK | W_OK) == 0)
	{
		chdir(newDirectory);
		/* set old path environment variable */
		_setenv(prmData->env, "OLDPWD", prmCurrentDirectory, 1);
	}
	else
		perror(newDirectory);
}
