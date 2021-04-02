#include <stdlib.h>
#include <string.h>

/**
 * _strlen - returns the length of a string
 *
 * @s: char pointer
 *
 * Return: Size of the string
 */
int _strlen(char *s)
{
	int size = 0;

	while (*s != '\0')
	{
		size++;
		s++;
	}

	return (size);
}

/**
 * _strcat - concatenates two string
 *
 * @dest: char pointer
 * @src: char pointer
 *
 * Return: string
 */
char *_strcat(char *dest, char *src)
{
	int length, d_size, s_size;

	d_size = _strlen(dest);
	s_size = _strlen(src);

	for (length = 0; length < s_size; length++)
	{
		dest[d_size + length] = src[length];
	}

	return (dest);
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
 * _parsingString - split string to array
 *
 * @prmString: argument's string
 * @prmSeparator: separators
 */
void _parsingString(char *prmString, char *prmSeparator, char *argv[])
{
	char *strToken;
	int i = 0;

	strToken = strtok(prmString, prmSeparator);

	while (strToken != NULL && _strcmp(strToken, "\n") != 0)
	{
		argv[i] = strToken;
		strToken = strtok(NULL, prmSeparator);
		i++;
	}
	argv[i] = NULL;
}
