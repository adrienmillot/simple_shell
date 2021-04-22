#include "shell.h"

/**
 * _getenvvalue - return environment value
 *
 * @prmVariable: environment name
 *
 * Return: environment value
 */
char *_getenvvalue(char *prmVariable)
{
	char **tmp, *name;

	tmp = _strtow(prmVariable, ENV_SEPARATOR, NULL);

	if (tmp == NULL)
		return (NULL);

	name = _strdup(tmp[1]);
	_freeCharDoublePointer(tmp);
	tmp = NULL;

	return (name);
}
