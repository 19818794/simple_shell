#include "main.h"

/**
 * _read_line - reads a line from standard input.
 *
 * Return: the input line.
 */
char *_read_line(void)
{
	char *line = NULL;
	size_t size = BUFFER_SIZE;
	ssize_t length;

	/* Read input from standard input */
	length = _getline_(&line, &size, stdin);
	/*
	 * print error message if getline() failed or error occurred while
	 * reading from stdin
	 */
	if (length == -1 && ferror(stdin))
	{
		free(line);
		_print("Error: getline()\n");
		exit(EXIT_FAILURE);
		return (NULL);
	}
	/*Check for end of input to handle the end of file condition (Ctrl+D)*/
	if (feof(stdin))
	{
		_print("\n");
		exit(0);
	}
	/* Replace newline character with null terminator */
	line[length - 1] = '\0';

	return (line);
}
