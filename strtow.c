#include "shell.h"

/**
 * _characterNumber - returns character number
 *
 * @prmString: char pointer
 * @prmSeparators: separators
 *
 * Return: Size of the string
 */
int _characterNumber(char *prmString, char *prmSeparators)
{
	if (*prmString != '\0')
	{
		if (_inArray(*prmString, prmSeparators) == 1)
			return (_characterNumber(prmString + 1, prmSeparators) + 1);
		else
			return (_characterNumber(prmString + 1, prmSeparators));
	}
	else
		return (0);
}

/**
 * _wordNumber - returns word number
 *
 * @prmString: char pointer
 * @prmSeparators: separators
 *
 * Return: Word number
 */
int _wordNumber(char *prmString, char *prmSeparators)
{
	int cLoop = 0, count = 0;

	while (prmString[cLoop] != '\0')
	{
		if (
			_inArray(prmString[cLoop], prmSeparators) != 1 &&
			_inArray(prmString[cLoop + 1], prmSeparators) == 1
		)
			count++;
		cLoop++;
	}

	return (count);
}

/**
 * _getWord - returns word
 *
 * @prmGlobal: char pointer
 * @prmOffset: start of the word
 * @prmSize: length of the word
 *
 * Return: Word number
 */

char *_getWord(char *prmGlobal, int prmOffset, int prmSize)
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
		if (_inArray(prmString[cLoop], prmSeparators) != 1)
			wordSize++;
		else
			if (wordSize > 0)
			{
				word = _getWord(prmString, cLoop - wordSize, wordSize);
				words[cLoop1] = _strdup(word);
				wordSize = 0;
				cLoop1++;
				free(word);
			}
	}
	words[cLoop1] = 0;

	return (words);
}
