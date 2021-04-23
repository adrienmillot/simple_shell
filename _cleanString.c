#include "shell.h"

/**
 * _cleanString - erase begin spaces and ending spaces from string
 *
 * @prmString: string to clean
 *
 * Return: clean string
 */
char *_cleanString(char *prmString)
{
	int cLoopStart = 0, cLoopEnd = 0, size = 0;
	char *string;

	if (prmString == NULL)
		return (NULL);

	size = _strlen(prmString);

	while (_inArray(prmString[cLoopStart], " ") == 1)
		cLoopStart++;

	cLoopEnd = size - 1;
	while (_inArray(prmString[cLoopEnd], " ") == 1)
		cLoopEnd--;
	cLoopEnd = size - 1 - cLoopEnd;

	string = _calloc(sizeof(char), size - cLoopStart - cLoopEnd + 1);
	_strncpy(string, (prmString + cLoopStart), size - cLoopStart - cLoopEnd);
	string[size - cLoopStart - cLoopEnd] = '\0';

	/**prmString = *string;*/
	prmString = _realloc(
		prmString,
		size,
		sizeof(char) * (size - cLoopStart - cLoopEnd + 1)
	);
	_strcpy(prmString, string);
	prmString[size - cLoopStart - cLoopEnd] = '\0';
	free(string);
	return (prmString);
}
