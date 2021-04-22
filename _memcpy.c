#include "shell.h"

/**
 * _memcpy - copies n bytes from memory area src to memory area dest
 *
 * @prmDest: pointer to memory area
 * @prmSrc: pointer to src memory area
 * @prmLimit: number ot bytes to fill
 *
 * Return: pointer to dest
 */
char *_memcpy(char *prmDest, char *prmSrc, unsigned int prmLimit)
{
	unsigned int cLoop;

	for (cLoop = 0; cLoop < prmLimit; cLoop++)
	{
		prmDest[cLoop] = prmSrc[cLoop];
	}

	return (prmDest);
}
