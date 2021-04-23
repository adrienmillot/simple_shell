#include "shell.h"

/**
 * _execCommand - Execute a command
 *
 * @prmData: app data array
 */
void _execCommand(appData_t *prmData)
{
	pid_t child_pid;
	char *command;
	int status;

	if (prmData->commandName == NULL)
		return;

	/* Get the absolute path of the command */
	command = _which(prmData);

	if (command != NULL)
	{
		if (prmData->commandName != command)
			free(prmData->commandName);
		prmData->commandName = command;
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
		if (execve(prmData->commandName, prmData->arguments, NULL) == -1)
			_errorHandler(prmData, 103);
		return;
	}
	else if (child_pid == -1)
	{
		_errorHandler(prmData, 102);
	}
	else
		waitpid(child_pid, &status, WUNTRACED);
}
