#include "main.h"

/**
 * _print - prints a string.
 * @str: the string to be printed.
 *
 * Return: void.
 */
void _print(char *str)
{
	int i = 0;

	/* Loop through the string until the null character is reached */
	while (str[i] != '\0')
	{
		/* Print each character in the string */
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout.
 * @c: The character to be printed.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	/* Write a single character to standard output using the @write() */
	return (write(1, &c, 1));
}

/**
 * _perror - gets the status of a file.
 * @cmd: the file to be checked.
 *
 * Return: void.
 */
void _perror(char *cmd)
{
	struct stat st;
	char *ptr = int_to_str(cmd_counter);

	_print(shell_name);
	_print(": ");
	_print(ptr);
	_print(": ");
	_print(cmd);
	if (stat(cmd, &st) != 0)
		_print(": not found\n");
	else
		_print(": found\n");
}

/**
 * _snprint - concatenate s1, followed by an equals sign ('='),
 * followed by a portion of s2, into the ptr array.
 * @ptr: a pointer to a character array.
 * @size: the size allocated for ptr array.
 * @s1: the first string.
 * @s2: the second string.
 *
 * Return: void.
 */
void _snprint(char *ptr, int size, char *s1, char *s2)
{
	int i = 0, j = 0;

	while (i < _strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '=';
	i++;
	while (i < size && j < _strlen(s2))
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
}
