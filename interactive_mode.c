#include "main.h"

/**
 * interactive_mode - Creates a simple UNIX command interpreter
 * for interactive mode.
 *
 * Return: Always 0 (Success), -1 otherwise.
 */
int interactive_mode(void)
{
	char *prompt = "$ ", *line, *operator = ";", **parsed_line;
	int i, valid;

	/*When Ctrl+C is pressed, C program doesn't terminate, return newline*/
	signal(SIGINT, _ctrl_c_signal_handler);
	/* Counts the number of commands, starting from one */
	cmd_counter = 1;
	/* Global variable to handel exit of shell */
	should_run = 1;
	/* It displayed prompt again eachtime a command has been executed*/
	while (should_run != 0)
	{
		/* Display a prompt to wait for the user to type a command */
		_print(prompt);
		/* Read text prompt from the stdin */
		line = _read_line();
		if (line == NULL)
			return (-1);
		/* Split input line into individual commands */
		parsed_line = _split_line(line, operator);
		/*Counts num of commands in a single line, starting from zero*/
		i = 0;
		while (parsed_line[i] != NULL)
		{
			valid = _handle_logical_operators(parsed_line[i]);
			if (valid == -1)
			{
				_print("Invalid command: Cannot have both");
			       _print("	'&&' and '||' operators\n");
				break;
			}
			i++;
		}
		free(line), free(parsed_line); /* Free the memory allocated */
	}
	return (0);
}
