#include "shell.h"

/**
 * _env - print environement variable
 *
 * @prmData: data structure
 */
void _env(appData_t *prmData)
{
	_printenv(prmData->env);
}
