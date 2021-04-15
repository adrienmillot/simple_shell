#include "shell.h"

/**
 * _freeCharDoublePointer - free memory of a double pointer
 *
 * @prmPtr: double pointer
 */
void _freeCharDoublePointer(char **prmPtr)
{
	int cLoop = 0;

	while (prmPtr[cLoop] != NULL)
		free(prmPtr[cLoop++]);
	free(prmPtr);
}
