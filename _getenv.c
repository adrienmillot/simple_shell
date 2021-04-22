#include "shell.h"

/**
 * _getenv - get environment variable
 *
 * @prmEnviron: first node
 * @prmName: environment variable name
 *
 * Return: environment variable node
 */
environment_t *_getenv(environment_t *prmEnviron, char *prmName)
{
	if (prmEnviron == NULL)
		return (NULL);

	if (_strcmp(prmEnviron->name, prmName) == 0)
		return (prmEnviron);

	return (_getenv(prmEnviron->next, prmName));
}
