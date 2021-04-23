#include "shell.h"

int main(int argc __attribute__((unused)), char **argv)
{
	appData_t *appData = NULL;
	int cLoop;
	void (*func)(appData_t *);

	appData = _initData(argv);

	do {
		signal(SIGINT, _ctrlC);
		_prompt();

		_getline(appData);

		appData->history = _strtow(appData->buffer, COMMAND_SEPARATOR, ESCAPE_SEPARATOR);

		if (appData->history == NULL)
		{
			_freeAppData(appData);
			free(appData);
			continue;
		}

		for (cLoop = 0; appData->history[cLoop] != NULL; cLoop++)
		{
			appData->arguments = _strtow(appData->history[cLoop], SEPARATORS, ESCAPE_SEPARATOR);

			if (appData->arguments == NULL)
			{
				_freeAppData(appData);
				_freeEnvList(appData->env);
				appData->env = NULL;
				free(appData);
				appData = NULL;
				break;
			}

			appData->commandName = _strdup(appData->arguments[0]);

			if (appData->commandName != NULL)
			{
				func = _getCustomFunction(appData->commandName);
				if (func != NULL)
					func(appData);
				else
					_execCommand(appData);
			}
			_freeCharDoublePointer(appData->arguments);
			appData->arguments = NULL;
			free(appData->commandName);
			appData->commandName = NULL;
		}

		_freeAppData(appData);
	} while (1);
	return (EXIT_SUCCESS);
}
