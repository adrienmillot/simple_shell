#include "shell.h"

/**
 * _itoa - Convert an int to a string
 * @prmNumber: int to convert
 * Return: converted string
 */

char *_itoa(int prmNumber)
{
	char *s;
	int cLoop;
	long number;

	number = prmNumber;
	cLoop = _nbrLen(number);
	s = malloc(sizeof(char) * cLoop + 1);

	if (s == NULL)
	{
		return (NULL);
	}

	s[cLoop] = '\0';

	if (number == 0)
	{
		s = "0";
	}
	else if (number < 0)
	{
		s[0] = '-';
		number *= -1;
	}

	while (number)
	{
		s[--cLoop] = number % 10 + 48;
		number /= 10;
	}

	return (s);
}
