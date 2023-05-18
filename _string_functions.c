#include "main.h"

/**
 * _strlen - returns the length of a string.
 * @s: the string to check.
 *
 * Return: length of a string.
 */
int _strlen(char *s)
{
	int length = 0;

	/* Count the length until null terminator is reached */
	while (*s)
	{
		length++;
		s++;
	}

	return (length);
}

/**
 * _strcpy - copies the string pointed to by src, including the terminating
 * null byte (\0), to the buffer pointed to by dest.
 * @src: the string to copy.
 * @dest: the string to paste.
 *
 * Return: a pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	/* If src is invalid, return dest */
	if (src == NULL)
		return (dest);
	/* Copy characters from src to dest until null terminator is reached */
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	/* Add null terminator to dest */
	*(dest + i) = '\0';

	return (dest);
}

/**
 * _strdup - duplicates a string.
 * @line: the string to be duplicated.
 *
 * Return: a pointer to the new duplicated string,
 * otherwise NULL if it fails.
 */
char *_strdup(char *line)
{
	size_t length;
	char *new_line;

	/* Check for invalid argument */
	if (line == NULL)
		return (NULL);
	/*Calculate the length of input string, including the null terminator*/
	length = _strlen(line) + 1;
	/* Allocate memory for the new string */
	new_line = malloc(length);
	if (new_line == NULL)
		return (NULL);
	/* Copy the input string to the new string using @_strcpy function */
	_strcpy(new_line, line);

	return (new_line);
}

/**
 * _strcmp - compares two strings.
 * @s1: the first string.
 * @s2: the second string.
 *
 * Return: an integer <0 if s1 less than s2,
 * an integer =0 if s1 match s2,
 * an ineteger >0 if s1 greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	/* Loop through the two strings character by character if are equal */
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	/*
	 * If the strings match up to this point, return 0,
	 * otherwise if the characters at the current position of s1 and s2 are
	 * different, return the difference between them.
	 */

	return (*s1 - *s2);
}
