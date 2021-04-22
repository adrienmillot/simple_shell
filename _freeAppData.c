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

	if (prmData->arguments != NULL)
		_freeCharDoublePointer(prmData->arguments);
	prmData->arguments = NULL;
	if (prmData->buffer != NULL)
		free(prmData->buffer);
	prmData->buffer = NULL;
	if (prmData->commandName != NULL)
		free(prmData->commandName);
	prmData->commandName = NULL;
	if (prmData->commandList != NULL)
		_freeCharDoublePointer(prmData->commandList);
	prmData->commandList = NULL;
	if (prmData->history != NULL)
		_freeCharDoublePointer(prmData->history);
	prmData->history = NULL;
	/*if (prmData->env != NULL)
		_freeEnvList(prmData->env);
	prmData->env = NULL;*/
	/*if (prmData != NULL)
		free(prmData);
	prmData = NULL;*/
}
