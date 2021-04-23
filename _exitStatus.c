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

	if (code < 0 || (prmData->arguments[1] != NULL && !_isNumber(prmData->arguments[1])))
	{
		_errorHandler(prmData, 106);
		code = 2;
	}

	_freeAppData(prmData);
	_freeEnvList(prmData->env);
	prmData->env = NULL;
	free(prmData);
	exit(code);
}
