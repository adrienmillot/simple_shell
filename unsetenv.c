#include "shell.h"

/**
 * _unsetEnvironmentVariable - unset environment variable
 *
 * @prmData: data's structure
 */
void _unsetEnvironmentVariable(data_t *prmData)
{
	if (prmData == NULL)
		return;

	if (prmData->arguments == NULL)
		return;

	if (prmData->arguments[1] == NULL)
		return;

	_unsetenv(prmData->arguments[1]);
}
