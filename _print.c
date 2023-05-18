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
 * _print_err - gets the status of a file.
 * @cmd: the file to be checked.
 *
 * Return: void.
 */
void _print_err(char *cmd)
{
	struct stat st;

	_print(shell_name);
	_print(": 1: ");
	_print(cmd);
	if (stat(cmd, &st) != 0)
		_print(": not found\n");
	else
		_print(": found\n");
}
