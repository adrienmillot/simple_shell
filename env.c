#include "shell.h"

/**
 * _getenv - get envioronment variable
 *
 * @prmEnvironmentName: environment variable name
 *
 * Return: environment variable value
 */
char *_getenv(char *prmEnvironmentName)
{
	int cLoop = 0;

	while (environ[cLoop] != NULL)
	{
		if (_strstr(environ[cLoop], prmEnvironmentName, 1) != NULL)
		{
			return (environ[cLoop]);
		}
		cLoop++;
	}

	return (NULL);
}

/**
 * _env - print environement variable
 *
 * @prmData: data structure
 */
void _env(data_t *prmData __attribute__((unused)))
{
	int cLoop = 0;

	while (environ[cLoop])
	{
		_puts(environ[cLoop]);
		_putchar('\n');
		cLoop++;
	}
}
