#include "shell.h"

/**
 * _isBuildIn - check custom command
 *
 * @prmCommand: command
 *
 * Return: pointer function
 */
void (*_isBuildIn(char *prmCommand))(data_t *)
{
	int i = 0;

	customCommand_t fp[] = {
		{"cd", _changeDirectory},
		{"env", _env},
		{"setenv", _setEnvironmentVariable},
		{"unsetenv", _unsetEnvironmentVariable},
		{"exit", _exitStatus},
		{"help", _help}
	};

	while (i < 6)
	{
		if (_strcmp(prmCommand, (fp + i)->command) == 0)
			return ((fp + i)->func);
		i++;
	}

	return (NULL);
}

/**
 * _setData - initialize data structure
 *
 * @prmCommand: command name
 * @prmArguments: argument's list
 * @prmBuffer: buffer
 *
 * Return: data structure
 */
data_t *_setData(char *prmCommand, char **prmArguments, char *prmBuffer)
{
	data_t *data;

	data = malloc(sizeof(data_t));

	if (prmCommand != NULL)
		data->command = prmCommand;
	if (prmArguments != NULL)
		data->arguments = prmArguments;
	if (prmBuffer != NULL)
		data->buffer = prmBuffer;

	return (data);
}

/**
 * _execCmd - Execute a command
 *
 * @prmArguments: argument's array
 */
void _execCmd(char *prmArguments[])
{
	pid_t child_pid;
	char *command;
	int status;

	if (prmArguments == NULL || prmArguments[0] == NULL)
		return;

	/* Get the absolute path of the command */
	command = _which(prmArguments[0]);

	if (command != NULL)
	{
		if (prmArguments[0] != command)
			free(prmArguments[0]);
		prmArguments[0] = command;
	}
	else
	{
		return;
	}

	/* Create a child */
	child_pid = fork();
	if (child_pid == 0)
	{
		/* Execute command*/
		if (execve(prmArguments[0], prmArguments, environ) == -1)
			perror(prmArguments[0]);
		return;
	}
	else
		waitpid(child_pid, &status, WUNTRACED);
}
