#include "shell.h"

/**
 * _checkSeparators - check if a character correspond to one of separators or
 *                    EOF character
 *
 * @prmChar: character to compare
 * @prmSeparators: list of separators:
 *
 * Return: 0 if failed
 *         1 if success
 */
int _checkSeparators(char prmChar, char *prmSeparators)
{
	if (prmSeparators == NULL)
		return (0);

	return (
		_inArray(prmChar, prmSeparators) == 1 ||
		prmChar == '\0'
	);
}
