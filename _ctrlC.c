#include "shell.h"

/**
 * _ctrlC - control c managment
 *
 * @prmSignal: signal value
 */
void _ctrlC(int prmSignal __attribute__((unused)))
{
	_puts("\n");
	_prompt();
}
