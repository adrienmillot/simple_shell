#include "shell.h"

/**
 * _freeDoublePointer - free memory of a double pointer
 *
 * @prmPtr: double pointer
 */
void _freeDoublePointer(char **prmPtr)
{
	int cLoop = 0;

	if (prmPtr == NULL)
		return;

	while (prmPtr[cLoop] != NULL)
	{
		free(prmPtr[cLoop]);
		cLoop++;
	}

	free(prmPtr);
}

/**
 * _freeData - free all pointer of the appllication
 *
 * @prmData: data structure
 */
void _freeData(data_t *prmData)
{
	if (prmData == NULL)
		return;

	if (prmData->buffer != NULL)
		free(prmData->buffer);
	if (prmData->arguments != NULL)
		_freeDoublePointer(prmData->arguments);
	free(prmData);
}

/**
 * _memcpy - copies n bytes from memory area src to memory area dest
 *
 * @dest: pointer to memory area
 * @src: pointer to src memory area
 * @n: number ot bytes to fill
 *
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int cLoop;

	for (cLoop = 0; cLoop < n; cLoop++)
	{
		dest[cLoop] = src[cLoop];
	}

	return (dest);
}

/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ptr: source pointer
 * @old_size: in pointer size
 * @new_size: out pointer size
 *
 * Return: reallocated pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *s = ptr;

	if (ptr == NULL)
	{
		return (malloc(new_size));
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	s = malloc(new_size);

	if (s == NULL)
	{
		return (NULL);
	}

	s = _memcpy(s, ptr, old_size);
	free(ptr);

	return (s);
}

/**
 * _calloc - allocates memory for an array
 *
 * @nmemb: character number
 * @size: size of one case
 *
 * Return: allocate memory an initialize it
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *s;

	if (nmemb == 0 || size == 0)
		return (NULL);

	s = malloc(size * nmemb);

	if (s == NULL)
		return (NULL);

	s = _memset(s, 0, nmemb * size);

	return (s);
}
