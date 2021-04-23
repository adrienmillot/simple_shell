#include "shell.h"

/**
 * _calloc - allocates memory for an array
 *
 * @prmNumber: character number
 * @prmSize: size of one case
 *
 * Return: allocate memory an initialize it
 */
void *_calloc(unsigned int prmNumber, unsigned int prmSize)
{
	void *ptr;

	if (prmNumber == 0 || prmSize == 0)
		return (NULL);

	ptr = malloc(prmSize * prmNumber);

	if (ptr == NULL)
		return (NULL);

	ptr = _memset(ptr, 0, prmNumber * prmSize);

	return (ptr);
}
