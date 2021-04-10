#include <stdlib.h>
#include <stdio.h>

/**
 * _freeDoublePointer - free memory of a double pointer
 *
 * @prmPtr: double pointer
 */
void _freeDoublePointer(char **prmPtr)
{
	int cLoop = 0;

	if (prmPtr == NULL)
		return;

	while (prmPtr[cLoop] != NULL)
	{
		free(prmPtr[cLoop]);
		cLoop++;
	}

	free(prmPtr);
}
