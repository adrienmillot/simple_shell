#include "shell.h"

/**
 * _setEnvironmentVariable - set environment variable
 *
 * @prmData: data's structure
 */
void _setEnvironmentVariable(data_t *prmData)
{
	if (prmData == NULL)
		return;

	if (prmData->arguments == NULL)
		return;

	if (prmData->arguments[1] == NULL && prmData->arguments[2] == NULL)
		return;

	_setenv(prmData->arguments[1], prmData->arguments[2], 1);
}
