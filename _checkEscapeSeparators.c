#include "shell.h"

/**
 * _checkEscapeSeparators - check if character corresponds to one of escape
 *                          separators
 *
 * @prmChar: character to compare
 * @prmEscapeSeparators: list a separators
 *
 * Return: 0 if failed
 *         1 if success
 */
int _checkEscapeSeparators(char prmChar, char *prmEscapeSeparators)
{
	if (prmEscapeSeparators == NULL)
		return (0);

	return (_inArray(prmChar, prmEscapeSeparators));
}
