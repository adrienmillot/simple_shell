#include "shell.h"

/**
 * _exitStatus - exit status
 *
 * @prmData: data structure
 */
void _exitStatus(data_t *prmData)
{
	int code = EXIT_SUCCESS;

	if (prmData == NULL)
		return;

	if (prmData->arguments != NULL)
		code = _atoi(prmData->arguments[1]);

	_freeData(prmData);
	exit(code);
}
