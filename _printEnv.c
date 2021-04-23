#include "shell.h"

/**
 * _printenv - print environment variables
 *
 * @prmEnviron: environment variable list
 */
void _printenv(environment_t *prmEnviron)
{
	if (prmEnviron == NULL)
		return;

	_puts(prmEnviron->name);
	_puts("=");
	if (prmEnviron->value != NULL)
		_puts(prmEnviron->value);
	_puts("\n");
	_printenv(prmEnviron->next);
}
