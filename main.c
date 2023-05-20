#include "main.h"

/**
 * main - Entry point
 * @ac: number of the arguments supplied to the program.
 * @av: array of pointers to the arguments.
 *
 * Description: creates a simple UNIX command interpreter.
 *
 * Return: Always 0 (Success).
 */
int main(int ac __attribute__((unused)), char **av)
{
	char *prompt = "$ ", *line, **parse, *delimiter = " \t\r\n\a",
	     *operator = ";", **parsed_line;
	int i;

	/*When Ctrl+C is pressed, C program doesn't terminate, return newline*/
	signal(SIGINT, _ctrl_c_signal_handler);
	/* Counts the number of commands, starting from one */
	cmd_counter = 1;
	/* Collect the name of the shell */
	shell_name = av[0];
	/* Global variable to handel exit of shell */
	should_run = 1;
	/* It displayed prompt again eachtime a command has been executed*/
	while (should_run != 0)
	{
		/* Display a prompt to wait for the user to type a command */
		if (isatty(STDIN_FILENO))
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
			/* Split input line into individual cmds and args */
			parse = _split_line(parsed_line[i], delimiter);
			/* Execute the parsed command */
			_execute(parse);
			free(parse); /* Free the memory allocated */
			i++, cmd_counter++; /* Next command */
		}
		free(line), free(parsed_line); /* Free the memory allocated */
	}
	/* Free the memory allocated */
	free(prompt), free(delimiter), free(operator);
	return (0);
}
