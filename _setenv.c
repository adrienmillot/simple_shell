#include "shell.h"

/**
 * _setenv - set environment value
 *
 * @prmEnviron: environment linked list
 * @prmName: environment name
 * @prmValue: environment value
 * @prmOverwrite: overwrite
 */
void _setenv(
	environment_t *prmEnviron,
	char *prmName,
	char *prmValue,
	int prmOverwrite
) {
	environment_t *envNode;
	char *tmp;

	if (prmName == NULL || prmValue == NULL)
		return;

	envNode = _getenv(prmEnviron, prmName);

	if (envNode == NULL)
	{
		tmp = _generateEnvGlobal(prmName, prmValue);
		_addEnvNodeEnd(&prmEnviron, tmp);
		free(tmp);
	}
	else if (prmOverwrite == 1)
	{
		free(envNode->value);
		envNode->value = _strdup(prmValue);
	}
}
