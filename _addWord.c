#include "shell.h"

/**
 * _addWord - add a word to an array
 *
 * @prmWord: word to add
 * @prmIndex: current index
 * @prmArray: array
 */
void _addWord(char *prmWord, int *prmIndex, char **prmArray)
{
	prmWord = _cleanString(prmWord);
	prmArray[*prmIndex] = _strdup(prmWord);
	free(prmWord);
	*prmIndex += 1;
}
