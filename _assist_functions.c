#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free.
 * @ptr: a pointer to the memory previously allocated with a call to malloc.
 * @old_size: the size, in bytes, of the allocated space for ptr.
 * @new_size: the new size, in bytes of the new memory block.
 *
 * Return: a pointer, or NULL if it fails.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	/* If new size is 0 and ptr is not NULL, free memory and return NULL */
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	/* If ptr is NULL, allocate memory of new size and return pointer */
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	/* If new size is equal to old size, return ptr */
	if (new_size == old_size)
		return (ptr);
	/*
	 * If ptr is not NULL and new_size is not equal to 0 or old_size,
	 * allocate new memory of new size.
	 */
	ptr = malloc(new_size);

	return (ptr);
}

/**
 * _strcat - concatenates two strings.
 * @dest: the first string.
 * @src: the second string.
 *
 * Return: a pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	/* Find the end of dest */
	while (*ptr != '\0')
		ptr++;
	/* Copy the characters from src to dest */
	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	/* Add the null terminator to the end of the resulting string */
	*ptr = '\0';

	return (dest);
}
