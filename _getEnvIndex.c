#include "shell.h"

/**
 * _getEnvIndex - return index of an environment variable
 *
 * @prmHead: first node
 * @prmName: name
 *
 * Return: index
 */
int _getEnvIndex(environment_t *prmHead, char *prmName)
{
	if (prmHead == NULL || _strcmp(prmHead->name, prmName) == 0)
		return (0);
	else
		return (_getEnvIndex(prmHead->next, prmName) + 1);
}
