#include "shell.h"

/**
 * _exitHelp - print help for exit command
 */
void _exitHelp(void)
{
	_puts("exit: exit [n]\n");
	_puts("    Exit the shell.\n\n");
	_puts("    Exits the shell with a status of N.  ");
	_puts("    If N is omitted, the exit status\n");
	_puts("    is that of the last command executed.\n");
}
