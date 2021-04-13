#include "shell.h"

/**
 * _strtok - parse a string
 *
 * @prmString: string
 * @prmSeparators: separators
 * @prmSavePtr: rest of the string
 *
 * Return: first token of the string
 */
char *_strtok(char *prmString, char *prmSeparators, char **prmSavePtr)
{
	char *end = NULL;

	if (prmString == NULL)
		prmString = *prmSavePtr;

	/* if any string is done */
	if (*prmString == '\0')
	{
		*prmSavePtr = prmString;
		return (NULL);
	}

	/* if first character is a separator return an empty character */
	if (_inArray(prmString[0], prmSeparators) == 1)
	{
		*prmSavePtr = prmString + 1;
		return ("");
	}

	prmString += _strspn(prmString, prmSeparators);

	if (*prmString == '\0')
	{
		*prmSavePtr = prmString;
		return (NULL);
	}

	end = prmString + _strcspn(prmString, prmSeparators);

	if (*end == '\0')
	{
		*prmSavePtr = end;
		return (prmString);
	}

	*end = '\0';
	*prmSavePtr = end + 1;
	return (prmString);
}
