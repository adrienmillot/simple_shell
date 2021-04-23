#include "shell.h"

/**
 * _createEnvNode - create a new node
 *
 * @prmGlobal: global environment value
 *
 * Return: new element
 */
environment_t *_createEnvNode(char *prmGlobal)
{
	environment_t *new;

	if (prmGlobal == NULL)
		return (NULL);

	new = malloc(sizeof(environment_t));
	if (new == NULL)
		return (NULL);

	new->name = _getenvname(prmGlobal);
	new->value = _getenvvalue(prmGlobal);
	new->global = _strdup(prmGlobal);
	new->next = NULL;

	return (new);
}
