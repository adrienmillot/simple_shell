#include <stdlib.h>
#include <stdio.h>
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

	if (prmName == NULL || prmValue == NULL)
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
environment_t *_addNodeEnd(environment_t **prmHeadNode, char *prmName, char *prmValue)
{
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
	free(prmHeadNode);
}

/**
 * _printLinkedList - prints all the elements of a list_t list
 *
 * @prmHeadNode: list to browse
 *
 * Return: size of the list
 */
size_t _printLinkedList(const environment_t *prmHeadNode)
{
	if (prmHeadNode == NULL)
		return (0);
	if (prmHeadNode->next == NULL)
	{
		printf("[%s] %s\n", prmHeadNode->name, prmHeadNode->value);
		return (1);
	}
	else
	{
		if (prmHeadNode->name == NULL && prmHeadNode->value == NULL)
			printf("[0] %s\n", "(nil)");
		else
			printf("[%s] %s\n", prmHeadNode->name, prmHeadNode->value);
		return (_printLinkedList(prmHeadNode->next) + 1);
	}
}
