#include "shell.h"

/**
 * _strtok - 
 *
 * @prmString:
 * @prmSeparators:
 * @prmSavePtr:
 *
 * Return:
 */
char *_strtok(char *prmString, char *prmSeparators, char **prmSavePtr)
{
	char *end = NULL;

	if (prmString == NULL)
		prmString = *prmSavePtr;

	if (*prmString == '\0')
	{
		*prmSavePtr = prmString;
		return (NULL);
	}

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

	end = prmString + strcspn(prmString, prmSeparators);

	if (*end == '\0')
	{
		*prmSavePtr = end;
		return (prmString);
	}

	*end = '\0';
	*prmSavePtr = end + 1;
	return (prmString);
}
