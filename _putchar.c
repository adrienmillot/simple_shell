#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 *
 * @prmChar: The character to print
 *
 * Return: number of printed char
 */
int _putchar(char prmChar)
{
	return (write(STDIN_FILENO, &prmChar, 1));
}
