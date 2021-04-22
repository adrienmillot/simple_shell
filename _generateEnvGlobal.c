#include "shell.h"

/**
 * _generateEnvGlobal - generate a global environment variable
 *                      from name and value
 *
 * @prmName: environment name
 * @prmValue: environment value
 *
 * Return: global environment variable
 */
char *_generateEnvGlobal(char *prmName, char *prmValue)
{
	char *tmp, *global;

	global = "";
	global = _strconcat(global, prmName);
	tmp = _strconcat(global, "=");
	free(global);
	global = _strconcat(tmp, prmValue);
	free(tmp);

	return (global);
}
