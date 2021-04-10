#include "shell.h"

/**
 * _freeDoublePointer - free memory of a double pointer
 *
 * @prmPtr: double pointer
 */
void _freeDoublePointer(char **prmPtr)
{
	int cLoop = 0;

	if (prmPtr == NULL)
		return;

	while (prmPtr[cLoop] != NULL)
	{
		free(prmPtr[cLoop]);
		cLoop++;
	}

	free(prmPtr);
}

/**
 * _freeData - free all pointer of the appllication
 *
 * @prmData: data structure
 */
void _freeData(data_t *prmData)
{
	if (prmData == NULL)
		return;

	if (prmData->buffer != NULL)
		free(prmData->buffer);
	if (prmData->arguments != NULL)
		_freeDoublePointer(prmData->arguments);
	free(prmData);
}
