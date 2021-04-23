#include "shell.h"

/**
 * _getenvname - return environment name
 *
 * @prmVariable: environment name
 *
 * Return: environment name
 */
char *_getenvname(char *prmVariable)
{
	char **tmp, *name;

	tmp = _strtow(prmVariable, ENV_SEPARATOR, NULL);

	if (tmp == NULL)
		return (NULL);

	name = _strdup(tmp[0]);
	_freeCharDoublePointer(tmp);
	tmp = NULL;

	return (name);
}
