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

	if (
		code != 1 && code != 2 && code != 127 && code != 132 && code != 133 &&
		code != 134 && code != 136 && code != 137 && code != 138 && code != 139 &&
		code != 158 && code != 152 && code != 159 && code != 153
	)
	{
		_errorHandler(prmData, 106);
		return;
	}

	_freeAppData(prmData);
	_freeEnvList(prmData->env);
	prmData->env = NULL;
	free(prmData);
	exit(code);
}
