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
	char *buffer = NULL, **argv = NULL;
	data_t *data;
	void (*func)(data_t *);

	do {
		/* Ignore interactive signal */
		signal(SIGINT, ctrlC);

		/* Display prompt */
		write(STDIN_FILENO, PROMPT, 2);

		/* Catch user command */
		buffer = _getline();

		/* Split arguments */
		argv = _strtow(buffer, SEPARATORS, ESCAPE_SEPARATOR);

		if (argv == NULL || argv[0] == NULL)
		{
			free(buffer);
			_freeDoublePointer(argv);
			continue;
		}
		data = _setData(argv[0], argv, buffer);
		func = _isBuildIn(data->command);
		if (func != NULL)
			func(data);
		else
			_execCmd(argv);

		_freeData(data);
	} while (1);

	_freeData(data);

	return (EXIT_SUCCESS);
}
