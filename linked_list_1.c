#include "shell.h"

/**
 * _createNode - create a new node
 *
 * @prmName: name
 * @prmValue: value
 *
 * Return: new element
 */
environment_t *_createNode(char *prmName, char *prmValue)
{
	environment_t *new;

	if (prmName == NULL)
		return (NULL);

	new = malloc(sizeof(environment_t));
	if (new == NULL)
		return (NULL);

	new->name = _strdup(prmName);
	new->value = _strdup(prmValue);
	new->next = NULL;

	return (new);
}

/**
 * _getLastNode - get last node
 *
 * @prmHeadNode: first node
 *
 * Return: last element
 */
environment_t *_getLastNode(environment_t *prmHeadNode)
{
	environment_t *head, *next;

	head = prmHeadNode;

	if (head == NULL)
		return (NULL);

	next = head->next;

	if (next == NULL)
		return (head);
	else
		return (_getLastNode(next));
}

/**
 * _addNodeEnd - add a new node
 *
 * @prmHeadNode: first element
 * @prmName: name
 * @prmValue: value
 *
 * Return: last element
 */
environment_t *_addNodeEnd(
	environment_t **prmHeadNode,
	char *prmName,
	char *prmValue
) {
	environment_t *new, *last;

	if (prmHeadNode == NULL)
		return (NULL);

	new = _createNode(prmName, prmValue);
	if (new == NULL)
		return (NULL);

	if (*prmHeadNode == NULL)
		*prmHeadNode = new;
	else
	{
		last = _getLastNode(*prmHeadNode);
		if (last == NULL)
		{
			free(new);
			return (NULL);
		}
		last->next = new;
	}

	return (new);
}

/**
 * _freeList - free a struct linked list
 *
 * @prmHeadNode: first element
 *
 * Return: frees a list_t list
 */
void _freeList(environment_t *prmHeadNode)
{
	if (prmHeadNode == NULL)
		return;
	_freeList(prmHeadNode->next);
	free(prmHeadNode->name);
	free(prmHeadNode->value);
	free(prmHeadNode);
}
