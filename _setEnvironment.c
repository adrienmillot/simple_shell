#include "shell.h"

/**
 * _setEnvironment - set environment variable
 *
 * @prmData: data's structure
 */
void _setEnvironment(appData_t *prmData)
{
	if (prmData == NULL)
		return;

	if (prmData->arguments == NULL)
		return;

	if (prmData->arguments[1] == NULL || prmData->arguments[2] == NULL)
		return;

	_setenv(prmData->env, prmData->arguments[1], prmData->arguments[2], 1);
}
