#include "shell.h"

/**
 * _strtow - splits a string into words
 *
 * @prmString: char pointer
 * @prmSeparators: separators
 * @prmEscapeSeparators: escaping separators
 *
 * Return: word array
 */
char **_strtow(char *prmString, char *prmSeparators, char *prmEscapeSeparators)
{
	int cLoop = 0, cLoop1 = 0, size, wordSize = 0, word_number;
	char *word;
	char **words = NULL;

	size = _strlen(prmString);
	word_number = _wordNumber(prmString, prmSeparators);

	if (prmString == NULL || !prmString || word_number == 0)
		return (NULL);

	words = _calloc(sizeof(char *), (word_number + 1));

	if (words == NULL)
		return (NULL);

	for (cLoop = 0; cLoop < size && cLoop1 < word_number; cLoop++)
	{
		if (_inArray(prmString[cLoop], prmEscapeSeparators) == 1)
			break;
		if (
			_inArray(prmString[cLoop], prmSeparators) ||
			prmString[cLoop] == '\0'
		)
			wordSize++;
		else
			if (wordSize > 0)
			{
				word = _getword(prmString, cLoop - wordSize, wordSize);
				words[cLoop1] = _strdup(word);
				wordSize = 0;
				cLoop1++;
				free(word);
			}
	}
	words[cLoop1] = 0;

	return (words);
}
