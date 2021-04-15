#include "shell.h"

/**
 * _strlen - return string length
 *
 * @prmStr: string
 *
 * Return: string length
 */
int _strlen(char *prmStr)
{
	if (prmStr == NULL)
		return (0);
	return (_strlen(prmStr + 1) + 1);
}
