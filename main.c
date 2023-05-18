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
	char *prompt = "$ ", *line, **parse, *delimiter = " \t\r\n\a";

	/* Collect the name of the shell */
	shell_name = av[0];
	/* It displayed prompt again eachtime a command has been executed*/
	while (1)
	{
		/* Display a prompt to wait for the user to type a command */
		if (isatty(STDIN_FILENO))
			_print(prompt);
		/* Read text prompt from the stdin */
		line = _read_line();
		if (line == NULL)
			return (-1);
		/* Prints text prompt on the next line */
		/*printf("%s\n", line);*/
		/* Split input line into individual commands and arguments */
		parse = _split_line(line, delimiter);
		/* Prints splited line */
		/*printf("%s, %s\n", parse[0], parse[1]);*/
		/* Execute the parsed command */
		_execute(parse);
		/* Free the memory allocated */
		free(line);
		free(parse);
	}
	/* Free the memory allocated */
	free(prompt);
	free(delimiter);

	return (0);
}
