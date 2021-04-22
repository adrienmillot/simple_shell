
#include "shell.h"

/**
 * _addEnvNodeEnd - add a new node
 *
 * @prmHeadNode: first node
 * @prmGlobal: global environment value
 *
 * Return: last element
 */
environment_t *_addEnvNodeEnd(
	environment_t **prmHeadNode,
	char *prmGlobal
) {
	environment_t *new, *last;

	if (prmHeadNode == NULL)
		return (NULL);

	new = _createEnvNode(prmGlobal);
	if (new == NULL)
		return (NULL);

	if (*prmHeadNode == NULL)
		*prmHeadNode = new;
	else
	{
		last = _getLastEnvNode(*prmHeadNode);
		if (last == NULL)
		{
			free(new);
			return (NULL);
		}
		last->next = new;
	}

	return (new);
}
