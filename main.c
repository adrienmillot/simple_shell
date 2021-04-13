#include "shell.h"

/**
 * ctrlC - control c managment
 *
 * @prmSignal: signal value
 */
void ctrlC(int prmSignal __attribute__((unused)))
{
	write(STDIN_FILENO, "\n", 1);
	write(STDIN_FILENO, PROMPT, 2);
}

/**
 * main - main executable
 *
 * Return: 0 if succeded
 */
int main(void)
{
	char *buffer = NULL, **argv = NULL, **argv_tmp = NULL;
	data_t *data;
	void (*func)(data_t *);
	int cLoop = 0;

	do {
		signal(SIGINT, ctrlC);
		write(STDIN_FILENO, PROMPT, 2);
		buffer = _getline();
		argv_tmp = _strtow(buffer, ";\n", NULL);
		if (argv_tmp == NULL || argv_tmp[0] == NULL)
		{
			_freeDoublePointer(argv_tmp);
			continue;
		}
		cLoop = 0;
		while (argv_tmp[cLoop] != NULL)
		{
			argv = _strtow(argv_tmp[cLoop], SEPARATORS, ESCAPE_SEPARATOR);
			if (argv == NULL || argv[0] == NULL)
			{
				free(argv_tmp[cLoop]);
				_freeDoublePointer(argv);
				continue;
			}
			data = _setData(argv[0], argv, argv_tmp[cLoop]);
			func = _isBuildIn(data->command);
			if (func != NULL)
				func(data);
			else
				_execCmd(argv);
			_freeData(data);
			cLoop++;
		}
		free(buffer);
	} while (1);
	_freeData(data);
	return (EXIT_SUCCESS);
}
