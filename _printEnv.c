#include "shell.h"

/**
 * _printenv - print environment variables
 */
void _printenv(environment_t *prmEnviron)
{
	if (prmEnviron == NULL)
		return;

	_puts(prmEnviron->name);
	_puts("=");
	_puts(prmEnviron->value);
	_puts("\n");
	_printenv(prmEnviron->next);
}
