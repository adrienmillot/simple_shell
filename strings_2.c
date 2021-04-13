#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 *
 * @c: The character to print
 *
 * Return: number of printed char
 */
int _putchar(char c)
{
	return (write(STDIN_FILENO, &c, 1));
}

/**
 * _puts - write all char from string to stdout
 *
 * @str: string to print
 *
 * Return: number of printed char
 */
int _puts(char *str)
{
	int i = 0, sum = 0;

	while (str[i])
	{
		sum += _putchar(str[i]);
		i++;
	}
	return (sum);
}

/**
 * _strcspn - gets the length of a prefix substring.
 *
 * @prmString: string to search
 * @prmDeny: characters to deny
 *
 * Return: a pointer to the first occurrence of the character c
 *         in the string s, or NULL if the character is not found
 */
unsigned int _strcspn(char *prmString, char *prmDeny)
{
	unsigned int sLoop, dLoop;

	for (dLoop = 0; prmDeny[dLoop] != '\0'; dLoop++)
	{
		for (sLoop = 0; prmDeny[dLoop] != prmString[sLoop]; sLoop++)
		{
			if ('\0' == prmString[sLoop])
			{
				return (sLoop);
			}
		}
	}

	return (sLoop);
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
