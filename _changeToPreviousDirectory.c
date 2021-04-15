#include "shell.h"

/**
 * _changeToPreviousDirectory - change to previous directory
 *
 * @prmCurrentDirectory: current directory path
 */
void _changeToPreviousDirectory(char *prmCurrentDirectory)
{
	struct stat st;
	char *newDirectory;

	newDirectory = _getenvvalue("OLDPWD");

	if (stat(newDirectory, &st) == 0)
	{
		chdir(newDirectory);
		/* set old path environment variable */
		_setenv("OLDPWD", prmCurrentDirectory, 1);
		free(newDirectory);
	}
	else
	{
		free(newDirectory);
		perror(newDirectory);
	}
}
