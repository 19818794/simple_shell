#include "main.h"

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

/**
 * _strstr - searches a given substring in the main string.
 * @line: the main string.
 * @str: the substring to be searched for.
 *
 * Return: a pointer to the first occurrence of the given substring in the main
 * string if operator found, otherwise NULL.
 */
char *_strstr(char *line, char *str)
{
	char *ptr_line, *ptr_operator, *l, *o;

	/* Empty operator, return the line directly */
	if (*str == '\0')
		return (line);
	ptr_line = _strdup(line);
	ptr_operator = _strdup(str);
	while (*ptr_line != '\0')
	{
		if (*ptr_line == *ptr_operator)
		{
			l = ptr_line;
			o = ptr_operator;
			/* Check if the rest of the line matches the operator*/
			while (*l == *o && *o != '\0')
			{
				l++;
				o++;
			}
			/* Operator found */
			if (*o == '\0')
				return (ptr_line);
		}
		ptr_line++;
	}
	/* Free the duplicated operator memory */
	free(ptr_operator);
	/* Operator not found */
	return (NULL);
}

/**
 * _ptrlen - calculates the length of pointer of a pointer.
 * @ptr: pointer of a pointer.
 *
 * Return: The length of the pointer.
 */
int _ptrlen(char **ptr)
{
	int len_ptr = 0;

	while (ptr[len_ptr] != NULL)
		len_ptr++;

	return (len_ptr);
}
