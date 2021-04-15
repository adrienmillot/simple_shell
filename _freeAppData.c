#include "shell.h"

/**
 * _freeAppData - free all pointer of the appllication
 *
 * @prmData: data structure
 */
void _freeAppData(appData_t *prmData)
{
	if (prmData == NULL)
		return;

	_freeCharDoublePointer(prmData->arguments);
	prmData->arguments = NULL;
	free(prmData->buffer);
	prmData->buffer = NULL;
	free(prmData->commandName);
	prmData->commandName = NULL;
	_freeCharDoublePointer(prmData->history);
	prmData->history = NULL;
	free(prmData);
	prmData = NULL;
}
