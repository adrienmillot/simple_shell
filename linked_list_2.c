#include "shell.h"

/**
 * get_nodeint_at_index - the nth node of a listint_t linked list
 *
 * @prmHead: first element
 * @prmIndex: element's number
 *
 * Return: a node
 */
environment_t *get_nodeint_at_index(
	environment_t *prmHead,
	unsigned int prmIndex
) {
	unsigned int cLoop = 0;

	while (prmHead != NULL)
	{
		if (prmIndex == cLoop)
			return (prmHead);
		prmHead = prmHead->next;
		cLoop++;
	}

	return (NULL);
}
