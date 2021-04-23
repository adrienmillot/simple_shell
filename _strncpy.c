#include "shell.h"

/**
 * _strncpy - copies a string
 *
 * @prmDest: char pointer
 * @prmSrc: char pointer
 * @prmLimit: number of character
 *
 * Return: string
 */
char *_strncpy(char *prmDest, char *prmSrc, int prmLimit)
{
	int length, size_s;

	size_s = _strlen(prmSrc);

	for (length = 0; length < prmLimit; length++)
	{
		prmDest[length] = (length <= size_s) ? prmSrc[length] : '\0';
	}

	return (prmDest);
}
