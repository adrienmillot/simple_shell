#include "shell.h"

int main(void)
{
	char *buffer = NULL, **arguments;

	do {
		signal(SIGINT, _ctrlC);
		_prompt();

		buffer = _getline();

		arguments = _strtow(buffer, SEPARATORS, ESCAPE_SEPARATOR);

		free(buffer);
		_freeCharDoublePointer(arguments);
	} while (1);
	return (EXIT_SUCCESS);
}
