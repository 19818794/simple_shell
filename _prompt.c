#include "main.h"

/**
 * _read_line - reads a line from standard input.
 *
 * Return: the input line.
 */
char *_read_line(void)
{
	char *line = NULL, *final_line;
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
	/* To handle comments (#) */
	final_line = _handle_comments(line);
	return (final_line);
}

/**
 * _read_stream - reads a line from stream.
 *
 * Return: the input line.
 */
char *_read_stream(void)
{
	char *line, *final_line;
	size_t size = BUFFER_SIZE, new_size, length = 0;
	int bytes_read, input_finished = 0;

	line = malloc(sizeof(char) * size);
	if (line == NULL)
		perror("Error: malloc\n");
	while (!input_finished)
	{
		bytes_read = read(STDIN_FILENO, &line[length], 1);
		if (bytes_read < 0)
			perror("Error: read\n"), exit(EXIT_FAILURE);
		if (bytes_read == 0)
			input_finished = 1, exit(EXIT_SUCCESS);
		else if (line[length] == '\n')
		{
			line[length] = '\0';
			break;
		}
		length++;
		if (length >= size)
		{
			new_size = size * 2;
			line = _realloc(line, size, new_size);
			if (line == NULL)
			{
				perror("Error: realloc\n");
				exit(EXIT_FAILURE);
			}
			size = new_size;
		}
	}
	if (line[length - 1] != '\0')
		line[length] = '\0';
	final_line = _handle_comments(line);
	return (final_line);
}
