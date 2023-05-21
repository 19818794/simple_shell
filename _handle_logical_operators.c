#include "main.h"

/**
 * _handle_logical_operators - handles the && and || shell logical operators.
 * @line: the line to be handled.
 *
 * Return: Always 0 (Success), otherwise -1.
 */
int _handle_logical_operators(char *line)
{
	char **parsed_line2, **parse, *delimiter = " \t\r\n\a";
	int is_logical_and = 0, is_logical_or = 0, i;

	logical_counter = 0;
	if (_strstr(line, "&&") != NULL)
		is_logical_and = 1;
	if (_strstr(line, "||") != NULL)
		is_logical_or = 1;
	if (is_logical_and && is_logical_or)
		return (-1);
	if (is_logical_and) /* EXECUTE CMDS */
	{
		parsed_line2 = _split_line(line, "&&"), i = 0;
		while (parsed_line2[i] != NULL)
		{
			parse = _split_line(parsed_line2[i], delimiter);
			_execute(parse), free(parse), i++, cmd_counter++;
			if (logical_counter != 0)
				break; /*Stop executing cmds if first cmd fails*/
		}
		free(parsed_line2);
	}
	else if (is_logical_or)
	{
		parsed_line2 = _split_line(line, "||"), i = 0;
		while (parsed_line2[i] != NULL)
		{
			parse = _split_line(parsed_line2[i], delimiter);
			_execute(parse), free(parse), i++, cmd_counter++;
			if (logical_counter == 0)
				break; /*Stop executing cmds if first cmd succeeds*/
		}
		free(parsed_line2);
	}
	else
	{
		parse = _split_line(line, delimiter);
		_execute(parse), free(parse), cmd_counter++; /* Next command */
	}
	return (0);
}
