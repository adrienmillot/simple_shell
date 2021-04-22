#include "shell.h"

/**
 * _unsetenvHelp - print help for unsetenv command
 */
void _unsetenvHelp(void)
{
	_puts("unsetenv: unsetenv [VARIABLE]\n");
	_puts("    Initializes a new environment variable, or ");
	_puts("    modifies an existing one.\n\n");
	_puts("    VARIABLE must not have the character '='.\n");
	_puts("    If no arguments are given, setenv prints the current ");
	_puts("    environment.\n");
}
