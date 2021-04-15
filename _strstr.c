#include "shell.h"

/**
 * _strstr - locates a substring.
 *
 * @prmHaystack: string where to search
 * @prmNeedle: string to search
 * @prmBegin: force to start at begin if true
 *
 * Return: the address to first location
 */
char *_strstr(char *prmHaystack, char *prmNeedle, int prmBegin)
{
	int haystackLoop = 0, needleLoop = 0, size = _strlen(prmNeedle);

	if (prmNeedle[0] == '\0')
	{
		return (prmHaystack);
	}

	for (
		haystackLoop = 0, needleLoop = 0;
		(haystackLoop + needleLoop) < _strlen(prmHaystack);
		needleLoop++
	)
	{
		if (prmNeedle[needleLoop] != prmHaystack[haystackLoop + needleLoop])
		{
			if (prmBegin == 0)
			{
				haystackLoop += needleLoop;
				needleLoop = 0;
			}
			else
				return (NULL);
		}

		if (needleLoop == size - 1)
		{
			return (&prmHaystack[haystackLoop]);
		}
	}

	return (NULL);
}
