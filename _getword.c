#include "shell.h"

/**
 * _getword - returns word
 *
 * @prmGlobal: char pointer
 * @prmOffset: start of the word
 * @prmSize: length of the word
 *
 * Return: Word number
 */
char *_getword(char *prmGlobal, int prmOffset, int prmSize)
{
	char *word;
	int cLoop;

	word = malloc(sizeof(char) * prmSize + 1);

	if (word == NULL)
		return (NULL);

	for (cLoop = 0; cLoop < (prmSize); cLoop++)
		word[cLoop] = prmGlobal[prmOffset + cLoop];

	word[cLoop] = '\0';

	return (word);
}
