#include "shell.h"

/**
 * _isNumber - check if string is a number
 *
 * @s: string to verify
 *
 * Return: 1 if string is a number.
 */
int _isNumber(char *s)
{
	if (*s == '\0')
	{
		return (1);
	}
	if (!_isdigit(*s))
	{
		return (0);
	}
	else
	{
		return (_isNumber(s + 1));
	}
}
