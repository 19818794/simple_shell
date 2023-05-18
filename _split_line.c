#include "main.h"

/**
 * _split_line - splits line to array of words.
 * @line: the line to be splitted.
 * @delimiter: delimiter.
 *
 * Return: the array of tokens.
 */
char **_split_line(char *line, char *delimiter)
{
	char *line_copy, *token, **ptr_token;
	int size = BUFFER_SIZE, i = 0;

	/* Create a copy of the line and assigns it to a new memory location */
	line_copy = _strdup(line);
	/* Split the input line into individual tokens using delimiter arg */
	token = strtok(line_copy, delimiter);
	/* Allocate memory for an array to store the tokens */
	ptr_token = malloc(sizeof(char *) * size);
	if (ptr_token == NULL)
	{
		free(ptr_token);
		free(token);
		return (NULL);
	}
	/* Loop through the tokens and store them in the array */
	while (token != NULL)
	{
		ptr_token[i] = token;
		i++;
		/* If we've filled up the array, resize it */
		if (i >= size)
		{
			size += size;
			ptr_token = _realloc(ptr_token, size,
					(sizeof(char *) * size));
		}
		/* Get the next token */
		token = strtok(NULL, delimiter);
	}
	/*
	 * Add a null terminator to the end of the array
	 * to be able to execute execve function later.
	 */
	ptr_token[i] = NULL;
	/* Free allocated memory*/
	free(token);

	return (ptr_token);
}
