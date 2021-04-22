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
	int cLoop = 0, cLoop1 = 0, wordSize = 0, word_number = 0, size = 0;
	char *word = NULL, **words = NULL, character;

	if (prmString == NULL)
		return (NULL);

	size = _strlen(prmString);
	word_number = _wordNumber(prmString, prmSeparators);

	if (prmString == NULL || !prmString || word_number == 0)
		return (NULL);

	words = _calloc(sizeof(char *), (word_number + 1));

	if (words == NULL)
		return (NULL);

	for (cLoop = 0; cLoop <= size && cLoop1 < word_number; cLoop++)
	{
		character = prmString[cLoop];
		if (_checkEscapeSeparators(character, prmEscapeSeparators))
			break;
		if (!_checkSeparators(character, prmSeparators))
			wordSize++;
		else
			if (wordSize > 0)
			{
				word = _getword(prmString, cLoop - wordSize, wordSize);
				_addWord(word, &cLoop1, words);
				wordSize = 0;
			}
	}
	words[cLoop1] = NULL;

	return (words);
}
