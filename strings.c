#include "shell.h"

/**
 * _strlen - returns the length of a string
 *
 * @s: char pointer
 *
 * Return: Size of the string
 */
int _strlen(char *s)
{
	if (s == NULL || *s == '\0')
		return (0);
	return (_strlen(s + 1) + 1);
}

/**
 * _str_concat - concatenates two strings.
 *
 * @s1: char pointer to concatenate
 * @s2: char pointer to concatenate
 *
 * Return: char pointer concatenated
 */
char *_str_concat(char *s1, char *s2)
{
	char *s;
	int cLoop1, cLoop2, size;

	if (s1 == NULL)
		s1 = "\0";

	if (s2 == NULL)
		s2 = "\0";

	size = _strlen(s1) + _strlen(s2);
	s = malloc(sizeof(char) * (size + 1));

	if (s == NULL)
		return (NULL);

	for (cLoop1 = 0; s1[cLoop1]; cLoop1++)
		s[cLoop1] = s1[cLoop1];

	for (cLoop2 = 0; s2[cLoop2]; cLoop1++, cLoop2++)
		s[cLoop1] = s2[cLoop2];

	s[cLoop1] = '\0';

	return (s);
}

/**
 * _strcmp - compares two strings
 *
 * @s1: char pointer
 * @s2: char pointer
 *
 * Return: difference between ascii number
 */
int _strcmp(char *s1, char *s2)
{
	int length;

	for (length = 0; s1[length] != '\0'; length++)
	{
		if (s1[length] - s2[length] != 0)
			return (s1[length] - s2[length]);
	}

	return (0);
}

/**
 * _strstr - locates a substring.
 *
 * @haystack: string where to search
 * @needle: string to search
 * @prmBegin: force to start at begin if true
 *
 * Return: the address to first location
 */
char *_strstr(char *haystack, char *needle, int prmBegin)
{
	int haystackLoop = 0, needleLoop = 0, size = _strlen(needle);

	if (needle[0] == '\0')
	{
		return (haystack);
	}

	for (
		haystackLoop = 0, needleLoop = 0;
		(haystackLoop + needleLoop) < _strlen(haystack);
		needleLoop++
	)
	{
		if (needle[needleLoop] != haystack[haystackLoop + needleLoop])
		{
			if (prmBegin == 0)
			{
				haystackLoop += needleLoop;
				needleLoop = 0;
			}
			else
				return (NULL);
		}

		if (needleLoop == size - 1)
		{
			return (&haystack[haystackLoop]);
		}
	}

	return (NULL);
}

/**
 * _strdup - a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 *
 * @str: char pointer to copy
 *
 * Return: a new char pointer
 */
char *_strdup(char *str)
{
	char *s;
	int cLoop;

	if (str == NULL)
	{
		return (NULL);
	}

	s = malloc(sizeof(char) * (_strlen(str) + 1));

	if (s == NULL)
	{
		return (NULL);
	}

	for (cLoop = 0; cLoop < _strlen(str) + 1; cLoop++)
	{
		s[cLoop] = str[cLoop];
	}

	return (s);
}
