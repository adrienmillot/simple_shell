#include <stdlib.h>

/**
 * _freeDoublePointer - free memory of a double pointer
 *
 * @prmPtr: double pointer
 */
void _freeDoublePointer(char **prmPtr)
{
	if (prmPtr == NULL)
		return;

	while (*prmPtr != NULL)
	{
		free(*prmPtr);
		prmPtr++;
	}

	if (*prmPtr == NULL)
		free(*prmPtr);
	free(prmPtr);
}
