#include "shell.h"

/**
 * _memset - fills the first n bytes of the memory area pointed to by s
 *           with the constant byte b
 *
 * @s: pointer to memory area
 * @b: constant
 * @n: number ot bytes to fill
 *
 * Return: write n bytes of value b
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int cLoop;

	for (cLoop = 0; cLoop < n; cLoop++)
	{
		s[cLoop] = b;
	}

	return (s);
}
