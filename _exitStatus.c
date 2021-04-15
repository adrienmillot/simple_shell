#include "shell.h"

/**
 * _exitStatus - exit status
 *
 * @prmData: data structure
 */
void _exitStatus(appData_t *prmData)
{
	int code = EXIT_SUCCESS;

	if (prmData == NULL)
		return;

	if (prmData->arguments != NULL)
		code = _atoi(prmData->arguments[1]);

	_freeAppData(prmData);
	exit(code);
}
