#include "shell.h"

/**
 * _helpHelp - print help for help command
 */
void _helpHelp(void)
{
	_puts("help: help [-dms] [pattern ...]\n");
	_puts("    Display information about builtin commands.\n\n");
	_puts("    Displays brief summaries of builtin commands.  If PATTERN is\n");
	_puts("    specified, gives detailed help on all commands ");
	_puts("    matching PATTERN,\n");
	_puts("    otherwise the list of help topics is printed.\n\n");
	_puts("    Options:\n");
	_puts("      -d        output short description for each topic\n");
	_puts("      -m        display usage in pseudo-manpage format\n");
	_puts("      -s        output only a short usage synopsis for each topic m");
	_puts("atching\n        PATTERN\n\n");
	_puts("    Arguments:\n");
	_puts("      PATTERN   Pattern specifying a help topic\n\n");
	_puts("    Exit Status:\n");
	_puts("    Returns success unless PATTERN is not found or an invalid ");
	_puts("    option is given.\n");
}
