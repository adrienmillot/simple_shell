#include "shell.h"

/**
 * _setenvHelp - print help for setenv command
 */
void _setenvHelp(void)
{
	_puts("setenv: setenv [VARIABLE] [VALUE]\n");
	_puts("    Initializes a new environment variable, ");
	_puts("    or modifies an existing one.\n\n");
	_puts("    VARIABLE must not have the character '='.\n");
	_puts("    If no arguments are given, setenv prints ");
	_puts("    the current environment.\n");
}
