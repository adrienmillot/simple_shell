#include "shell.h"

void _errorHandler(appData_t *prmData, int messageCode)
{
	int i = 0;

	errorMessage_t errors[] = {
		{00, "Error unknown"},
		{100, "Error reading from Prompt - Zero tokens"},
		{101, "No such file or directory"},
		{102, "FATAL ERROR: UNABLE TO CREATE CHILD PROCESS"},
		{103, "command not found"},
		{104, "FATAL ERROR: NO MEMORY AVAILABLE."},
		{105, "FATAL ERROR: UNABLE TO CREATE CMD LIST"},
		{106, "Illegal number"},
		{999, ""} /* Error Array end condition*/
	};

	_puts(prmData->programName);
	_puts(": ");
	_puts("1");
	_puts(": ");
	_puts(prmData->commandName);
	_puts(": ");
	while (i < 9)
	{
		if (messageCode == (errors + i)->code)
		{
			_puts((errors + i)->msg);
			_puts(": ");
			_puts(prmData->arguments[1]);
		}
		i++;
	}
	_puts("\n");
}
