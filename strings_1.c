#include "shell.h"

/**
 * _strspn - gets the length of a prefix substring.
 *
 * @s: string to search
 * @accept: characters to accept
 *
 * Return: a pointer to the first occurrence of the character c
 *         in the string s, or NULL if the character is not found
 */
unsigned int _strspn(char *s, char *accept)
{
	int sLoop, aLoop;

	for (sLoop = 0; s[sLoop] != '\0'; sLoop++)
	{
		for (aLoop = 0; accept[aLoop] != s[sLoop]; aLoop++)
		{
			if ('\0' == accept[aLoop])
			{
				return (sLoop);
			}
		}
	}

	return (sLoop);
}

/**
 * _strchr - locates a character in a string.
 *
 * @s: string where to search
 * @c: character to search
 *
 * Return: A pointer to the first occurence of c
 */
char *_strchr(char *s, char c)
{
	int cLoop = 0;

	while (s[cLoop] >= '\0')
	{
		if (s[cLoop] == c)
			return ((s + cLoop));
		cLoop++;
	}

	return (NULL);
}

/**
 * _strncat - concatenates two string
 *
 * @dest: char pointer
 * @src: char pointer
 * @n: number of character
 *
 * Return: string
 */
char *_strncat(char *dest, char *src, int n)
{
	int length, d_size;

	d_size = _strlen(dest);

	for (length = 0; length < n; length++)
	{
		dest[d_size + length] = src[length];
	}

	return (dest);
}

/**
 * _strcpy - copies the string pointed to by src,
 *               including the terminating null byte (\0),
 *               to the buffer pointed to by dest
 *
 * @dest: char pointer
 * @src: char pointer
 *
 * Return: char*
 */
char *_strcpy(char *dest, char *src)
{
	int cLoop, size = _strlen(src);

	for (cLoop = 0; cLoop < size; cLoop++)
	{
		dest[cLoop] = src[cLoop];
	}

	dest[size] = '\0';

	return (dest);
}

/**
 * _inArray - Search a character in an array
 *
 * @c: character to search
 * @s: character array where to search
 *
 * Return: true if success
 */
int _inArray(char c, char *s)
{
	int cLoop;

	for (cLoop = 0; s[cLoop] != '\0'; cLoop++)
	{
		if (s[cLoop] == c)
		{
			return (1);
		}
	}

	return (0);
}
