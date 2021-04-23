#include "shell.h"

/**
 * _changeDirectory - change current directory
 *
 * @prmData: data structure
 */
void _changeDirectory(appData_t *prmData)
{
	char currentDirectory[500];

	getcwd(currentDirectory, 500);

	if (prmData == NULL)
		return;

	if (
		!prmData->arguments[1] ||
		_strcmp(prmData->arguments[1], "~") == 0 ||
		_strcmp(prmData->arguments[1], "~/") == 0
	)
		_changeToHomeDirectory(prmData, currentDirectory);
	/* Old path */
	else if (_strcmp(prmData->arguments[1], "-") == 0)
		_changeToPreviousDirectory(prmData, currentDirectory);
	else
		_changeToAnyDirectory(prmData, currentDirectory);
}
