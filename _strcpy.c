#include "shell.h"

/**
 * _strcpy - copies the string pointed to by src,
 *               including the terminating null byte (\0),
 *               to the buffer pointed to by dest
 *
 * @prmDest: char pointer
 * @prmSrc: char pointer
 *
 * Return: char*
 */
char *_strcpy(char *prmDest, char *prmSrc)
{
	int cLoop, size = _strlen(prmSrc);

	for (cLoop = 0; cLoop < size; cLoop++)
	{
		prmDest[cLoop] = prmSrc[cLoop];
	}

	prmDest[size] = '\0';

	return (prmDest);
}
