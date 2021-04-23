#include "shell.h"

/**
 * _listEnvLen - length of a linked list
 *
 * @prmHead: first node
 *
 * Return: length
 */
int _listEnvLen(environment_t *prmHead)
{
	if (prmHead == NULL)
		return (0);
	if (prmHead->next == NULL)
		return (1);
	else
		return (_listEnvLen(prmHead->next) + 1);
}
