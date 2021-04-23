#include "shell.h"

/**
 * _strcat - concatenates two string
 *
 * @prmDest: char pointer
 * @prmSrc: char pointer
 *
 * Return: string
 */
char *_strcat(char *prmDest, char *prmSrc)
{
	int length, d_size, s_size;

	d_size = _strlen(prmDest);
	s_size = _strlen(prmSrc);

	for (length = 0; length < s_size; length++)
	{
		prmDest[d_size + length] = prmSrc[length];
	}

	return (prmDest);
}
