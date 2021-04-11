#include "shell.h"

/**
 * _help - manage command help
 *
 * @prmData: data structure
 */
void _help(data_t *prmData)
{
	if (prmData == NULL)
		return;
	if (prmData->command == NULL)
		return;
	if (
		prmData->arguments == NULL || 
		prmData->arguments[0] == NULL || 
		prmData->arguments[1] == NULL
	)
		return;
	if (_strcmp(prmData->arguments[1], "cd") == 0)
		_cdHelp();
	if (_strcmp(prmData->arguments[1], "env") == 0)
		_envHelp();
	if (_strcmp(prmData->arguments[1], "setenv") == 0)
		_setenvHelp();
	if (_strcmp(prmData->arguments[1], "unsetenv") == 0)
		_unsetenvHelp();
	if (_strcmp(prmData->arguments[1], "exit") == 0)
		_exitHelp();
	if (_strcmp(prmData->arguments[1], "help") == 0)
		_helpHelp();
	else
		_anyHelpFound(prmData->arguments[1]);
}

/**
 * _anyHelpFound - print help when any command found
 */
void _anyHelpFound(char *prmCommand)
{
	_puts("bash: help: Aucune rubrique d'aide ne correspond à \"");
	_puts(prmCommand);
	_puts("\". Essayez \"help help\", \"man -k ");
	_puts(prmCommand);
	_puts("\" ou \"info ");
	_puts(prmCommand);
	_puts("\".\n");
}

/**
 * _cdHelp - printf help for cd command
 */
void _cdHelp()
{
	_puts("cd: cd [DIRECTORY]\n");
	_puts("    Change the shell working directory.\n\n");
	_puts("    Change the current directory to DIR.  ");
	_puts("    The default DIR is the value of the\n");
	_puts("    HOME shell variable.\n\n");
	_puts("    Options:\n");
	_puts("    -  If a minus signed is used instead a directory, ");
	_puts("    cd will change to the\n");
	_puts("       previous used directory\n\n");
	_puts("    Each time cd runs successfuly, the env variable ");
	_puts("    PWD is updated\n\n");
	_puts("    Exit Status:\n");
	_puts("    Returns 1 if the directory is changed, and if $PWD is set ");
	_puts("    successfully when\n");
	_puts("    is used; -1 otherwise.\n");
}

/**
 * _envHelp - print help for env command
 */
void _envHelp()
{
	_puts("env: env\n");
	_puts("    prints the current environment.\n\n");
	_puts("    Has no options\n");
}

/**
 * _setenvHelp - print help for setenv command
 */
void _setenvHelp()
{
	_puts("setenv: setenv [VARIABLE] [VALUE]\n");
	_puts("    Initializes a new environment variable, ");
	_puts("    or modifies an existing one.\n\n");
	_puts("    VARIABLE must not have the character '='.\n");
	_puts("    If no arguments are given, setenv prints ");
	_puts("    the current environment.\n");
}
