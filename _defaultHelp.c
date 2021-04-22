#include "shell.h"

/**
 * _defaultHelp - print help when any command found
 *
 * @prmCommand: command name
 */
void _defaultHelp(char *prmCommand)
{
	_puts("bash: help: Aucune rubrique d'aide ne correspond à \"");
	_puts(prmCommand);
	_puts("\". Essayez \"help help\", \"man -k ");
	_puts(prmCommand);
	_puts("\" ou \"info ");
	_puts(prmCommand);
	_puts("\".\n");
}
