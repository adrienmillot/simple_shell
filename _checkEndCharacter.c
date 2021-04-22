#include "shell.h"

/**
 * _checkEndCharacter - check if a string have an end of file character
 *
 * @prmString: string
 *
 * Return: 0 if failed
 *         1 if success
 */
int _checkEndCharacter(char *prmString)
{
	if (prmString == NULL)
		return (0);

	int cLoop = 0;

	while (!prmString[cLoop])
		cLoop++;

	return (prmString[cLoop] == '\0');
}
