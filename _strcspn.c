#include "shell.h"

/**
 * _strcspn - gets the length of a prefix substring.
 *
 * @prmString: string to search
 * @prmDeny: characters to deny
 *
 * Return: a pointer to the first occurrence of the character c
 *         in the string s, or NULL if the character is not found
 */
unsigned int _strcspn(char *prmString, char *prmDeny)
{
	unsigned int sLoop, dLoop;

	for (dLoop = 0; prmDeny[dLoop] != '\0'; dLoop++)
	{
		for (sLoop = 0; prmDeny[dLoop] != prmString[sLoop]; sLoop++)
			if ('\0' == prmString[sLoop])
				return (sLoop);
	}

	return (sLoop);
}
