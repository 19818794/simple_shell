#include "main.h"

/**
 * _handle_comments - removes any comments from the line.
 * @line: the line to be checked.
 *
 * Return: modified line, with any comments removed.
 */
char *_handle_comments(char *line)
{
	char hash = '#';
	int i;

	/* Check if the input line is empty, return NULL */
	if (line != NULL)
	{
		/* Iterate through the characters in the line */
		for (i = 0; line[i] != '\0'; i++)
		{
			/*
			 * If a comment character is found, replace it,
			 * and all subsequent characters with null terminators.
			 */
			if (line[i] == hash)
			{
				if (i != 0)
				{
					if (line[i - 1] == ' ')
					{
						line[i] = '\0';
						break;
					}
				}
				else
				{
					line[i] = '\0';
					break;
				}
			}
		}
	}

	return (line);
}
