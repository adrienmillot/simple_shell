#include "shell.h"

/**
 * _help - manage command help
 *
 * @prmData: data structure
 */
void _help(appData_t *prmData)
{
	if (prmData == NULL)
		return;
	if (prmData->commandName == NULL)
		return;
	if (
		prmData->arguments == NULL ||
		prmData->arguments[0] == NULL ||
		prmData->arguments[1] == NULL
	)
		return;
	if (_strcmp(prmData->arguments[1], "cd") == 0)
		_cdHelp();
	else if (_strcmp(prmData->arguments[1], "env") == 0)
		_envHelp();
	else if (_strcmp(prmData->arguments[1], "setenv") == 0)
		_setenvHelp();
	else if (_strcmp(prmData->arguments[1], "unsetenv") == 0)
		_unsetenvHelp();
	else if (_strcmp(prmData->arguments[1], "exit") == 0)
		_exitHelp();
	else if (_strcmp(prmData->arguments[1], "help") == 0)
		_helpHelp();
	else
		_defaultHelp(prmData->arguments[1]);
}
