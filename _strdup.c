#include "shell.h"

/**
 * _strdup - a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 *
 * @prmString: char pointer to copy
 *
 * Return: a new char pointer
 */
char *_strdup(char *prmString)
{
	char *string;
	int cLoop;

	if (prmString == NULL)
		return (NULL);

	string = malloc(sizeof(char) * (_strlen(prmString) + 1));

	if (string == NULL)
		return (NULL);

	for (cLoop = 0; cLoop < _strlen(prmString) + 1; cLoop++)
		string[cLoop] = prmString[cLoop];

	return (string);
}
