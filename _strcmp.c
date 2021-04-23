#include "shell.h"

/**
 * _strcmp - compares two strings
 *
 * @prmString1: char pointer
 * @prmString2: char pointer
 *
 * Return: difference between ascii number
 */
int _strcmp(char *prmString1, char *prmString2)
{
	int length;

	for (length = 0; prmString1[length] != '\0'; length++)
	{
		if (prmString1[length] - prmString2[length] != 0)
			return (prmString1[length] - prmString2[length]);
	}

	return (0);
}
