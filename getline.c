#include "shell.h"

/**
 * _getline - Return command line type by user
 *
 * Return: buffer
 */
char *_getline()
{
	char c = '\0', *buffer;
	int i = 0, rd, bufferSize = BUFFER_SIZE;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);

	while (c != '\n' && c != EOF)
	{
		rd = read(STDIN_FILENO, &c, 1);

		if (rd == 0)
		{
			c = EOF;
			write(STDIN_FILENO, "\n", 1);
			free(buffer);
			exit(EXIT_SUCCESS);
		}

		if (i >= bufferSize - 1)
		{
			buffer = _realloc(buffer, bufferSize, sizeof(char) * (i + 2));
			bufferSize = i + 2;
		}
		buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';

	return (buffer);
}
