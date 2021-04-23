#include "shell.h"

/**
 * _unsetEnvironment - unset environment variable
 *
 * @prmData: data's structure
 */
void _unsetEnvironment(appData_t *prmData)
{
	if (prmData == NULL)
		return;

	if (prmData->arguments == NULL)
		return;

	if (prmData->arguments[1] == NULL)
		return;

	_unsetenv(prmData, prmData->arguments[1]);
}
