#include "shell.h"

/**
 * _unsetenvHelp - print help for unsetenv command
 */
void _unsetenvHelp()
{
	_puts("unsetenv: unsetenv [VARIABLE]\n");
	_puts("    Initializes a new environment variable, or ");
	_puts("    modifies an existing one.\n\n");
	_puts("    VARIABLE must not have the character '='.\n");
	_puts("    If no arguments are given, setenv prints the current ");
	_puts("    environment.\n");
}

/**
 * _exitHelp - print help for exit command
 */
void _exitHelp()
{
	_puts("exit: exit [n]\n");
	_puts("    Exit the shell.\n\n");
	_puts("    Exits the shell with a status of N.  ");
	_puts("    If N is omitted, the exit status\n");
	_puts("    is that of the last command executed.\n");
}

/**
 * _helpHelp - print help for help command
 */
void _helpHelp()
{
	_puts("help: help [BUILTIN ...]\n");
	_puts("    Display information about builtin commands.\n\n");
	_puts("    Displays brief summaries of builtin commands.  If BUILTIN is\n");
	_puts("    specified, gives detailed help on all commands ");
	_puts("    matching BUILTIN,\n");
	_puts("    otherwise the list of help topics is printed.\n\n");
	_puts("    Arguments:\n");
	_puts("      BUILTIN   Builtin specifying a help topic\n\n");
	_puts("    Exit Status:\n");
	_puts("    Returns success unless PATTERN is not found or an invalid ");
	_puts("    option is given.\n");
}
