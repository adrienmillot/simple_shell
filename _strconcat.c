#include "shell.h"

/**
 * _strconcat - concatenates two strings.
 *
 * @prmString1: char pointer to concatenate
 * @prmString2: char pointer to concatenate
 *
 * Return: char pointer concatenated
 */
char *_strconcat(char *prmString1, char *prmString2)
{
	char *s;
	int cLoop1, cLoop2, size;

	if (prmString1 == NULL)
		prmString1 = "\0";

	if (prmString2 == NULL)
		prmString2 = "\0";

	size = _strlen(prmString1) + _strlen(prmString2);
	s = malloc(sizeof(char) * (size + 1));

	if (s == NULL)
		return (NULL);

	for (cLoop1 = 0; prmString1[cLoop1]; cLoop1++)
		s[cLoop1] = prmString1[cLoop1];

	for (cLoop2 = 0; prmString2[cLoop2]; cLoop1++, cLoop2++)
		s[cLoop1] = prmString2[cLoop2];

	s[cLoop1] = '\0';

	return (s);
}
