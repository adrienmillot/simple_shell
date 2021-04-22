#include "shell.h"

/**
 * _getLastEnvNode - get last node
 *
 * @prmHeadNode: first node
 *
 * Return: last element
 */
environment_t *_getLastEnvNode(environment_t *prmHeadNode)
{
	environment_t *head, *next;

	head = prmHeadNode;

	if (head == NULL)
		return (NULL);

	next = head->next;

	if (next == NULL)
		return (head);
	else
		return (_getLastEnvNode(next));
}
