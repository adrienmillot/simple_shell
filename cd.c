#include "shell.h"

/**
 * _changeDirectory - change current directory
 *
 * @prmData: data structure
 */
void _changeDirectory(data_t *prmData)
{
	char currentDirectory[500];

	getcwd(currentDirectory, 500);

	if (prmData == NULL)
		return;

	/* Old path */
	if (_strcmp(prmData->arguments[1], "-") == 0)
	{
		_changeToPreviousDirectory(currentDirectory);
	}
	else if (
		_strcmp(prmData->arguments[1], "~") == 0 ||
		_strcmp(prmData->arguments[1], "~/") == 0
	)
	{
		_changeToHomeDirectory(currentDirectory);
	}
	else
	{
		_changeToAnyDirectory(prmData, currentDirectory);
	}
}

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

/**
 * _changeToHomeDirectory - change to home directory
 *
 * @prmCurrentDirectory: current directory path
 */
void _changeToHomeDirectory(char *prmCurrentDirectory)
{
	struct stat st;
	char *newDirectory;

	newDirectory = _getenvvalue("HOME");

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

/**
 * _changeToAnyDirectory - change to any directory
 *
 * @prmData: data structure
 * @prmCurrentDirectory: current directory path
 */
void _changeToAnyDirectory(data_t *prmData, char *prmCurrentDirectory)
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

