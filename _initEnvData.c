#include "shell.h"

/**
 * _initEnvData - init environment linked list
 *
 * @prmData: data structre
 */
void _initEnvData(appData_t *prmData)
{
	int cLoop = 0;
	environment_t *new;

	if (prmData == NULL)
		return;

	while (environ[cLoop] != NULL)
	{
		new = _addEnvNodeEnd(&prmData->env, environ[cLoop]);

		if (new == NULL)
		{
			free(prmData->env);
			prmData->env = NULL;
			return;
		}

		cLoop++;
	}
}
