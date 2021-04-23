#include "shell.h"

/**
 * _freeEnvList - free a struct linked list
 *
 * @prmHeadNode: first element
 *
 * Return: frees a list_t list
 */
void _freeEnvList(environment_t *prmHeadNode)
{
	if (prmHeadNode == NULL)
		return;
	_freeEnvList(prmHeadNode->next);
	free(prmHeadNode->name);
	prmHeadNode->name = NULL;
	free(prmHeadNode->value);
	prmHeadNode->value = NULL;
	free(prmHeadNode->global);
	prmHeadNode->global = NULL;
	free(prmHeadNode);
}
