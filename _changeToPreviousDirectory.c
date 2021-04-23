#include "shell.h"

/**
 * _changeToPreviousDirectory - change to previous directory
 *
 * @prmData: data structure
 * @prmCurrentDirectory: current directory path
 */
void _changeToPreviousDirectory(appData_t *prmData, char *prmCurrentDirectory)
{
	environment_t *newDirectory;

	newDirectory = _getenv(prmData->env, "OLDPWD");

	if (access(newDirectory->value, R_OK | W_OK) == 0)
	{
		chdir(newDirectory->value);
		/* set old path environment variable */
		_setenv(prmData->env, "OLDPWD", prmCurrentDirectory, 1);
	}
	else
	{
		perror(newDirectory->value);
	}
}
