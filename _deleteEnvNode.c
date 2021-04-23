#include "shell.h"

/**
 * _deleteEnvNode - delete an environment variable
 *
 * @prmHead: first node
 * @prmName: name
 *
 * Return: error code
 */
int _deleteEnvNode(environment_t *prmHead, char *prmName)
{
	environment_t *beforeNode, *afterNode, *currentNode, *firstNode;
	unsigned int length, currentIndex;

	firstNode = prmHead;
	currentIndex = _getEnvIndex(prmHead, prmName);

	if (firstNode == NULL)
		return (-1);

	length = _listEnvLen(firstNode);

	if (length == 0 || currentIndex > (unsigned int) length - 1)
		return (-1);

	if (currentIndex == 0)
	{
		prmHead = prmHead->next;
		free(firstNode);
		return (1);
	}

	beforeNode = _getEnvNodeAtIndex(firstNode, currentIndex - 1);
	if (currentIndex == length - 1)
		afterNode = NULL;
	else
		afterNode = _getEnvNodeAtIndex(firstNode, currentIndex + 1);

	currentNode = _getEnvNodeAtIndex(firstNode, currentIndex);
	beforeNode->next = afterNode;
	free(currentNode->name);
	currentNode->name = NULL;
	free(currentNode->value);
	currentNode->value = NULL;
	free(currentNode->global);
	currentNode->global = NULL;
	free(currentNode);
	currentNode = NULL;

	return (1);
}
