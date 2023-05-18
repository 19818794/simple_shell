#include "main.h"
/**
 * _getline_ - reads an entire line from a stream.
 * @line: the line to be read.
 * @size: the expected size to be read.
 * @stream: the stream to be read from.
 * Return: the number of characters read,
 * otherwise -1 if it fails.
 */
ssize_t _getline_(char **line, size_t *size, FILE *stream)
{
	size_t new_size, length = 0;
	char *new_line = NULL;
	int c;

	/* Check for invalid arguments */
	if (line == NULL || size == NULL || stream == NULL)
		return (-1);
	/*Allocate memory for initial line if it hasn't been allocated yet*/
	if (*line == NULL)
	{
		*line = malloc(*size);
		if (*line == NULL)
			return (-1);
	}
	/*Loop reading characters until a newline or EOF is encountered*/
	while ((c = read(fileno(stream), &(*line)[length], 1)) > 0)
	{
		/* If the line buffer is full, resize it to be twice as large*/
		if (length >= (*size - 1))
		{
			new_size = (*size) * 2;
			new_line = _realloc(*line, *size,  new_size);
			if (new_line == NULL)
				return (-1);
			*line = new_line, *size = new_size;
		}
		/* Add the current character to the line buffer */
		length++;
		/* If a newline is encountered, stop reading characters */
		if ((*line)[length - 1] == '\n')
			break;
	}
	/*If no characters were read & EOF was encountered,-1 to indicate EOF*/
	if (length == 0 && c == 0)
		return (-1);
	/* Add a null terminator to the end of the line buffer */
	(*line)[length] = '\0';
	return (length);
}
