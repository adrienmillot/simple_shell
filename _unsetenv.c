#include "shell.h"

/**
 * _unsetenv - unset environment variable
 *
 * @prmData: data structure
 * @prmName: environment name
 */
void _unsetenv(appData_t *prmData, char *prmName)
{
	_deleteEnvNode(prmData->env, prmName);
}
