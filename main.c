#include "main.h"

/**
 * main - Entry point
 * @ac: number of the arguments supplied to the program.
 * @av: array of pointers to the arguments.
 *
 * Description: Checks whether our shell has been invoked.
 *
 * Return: Always 0 (Success), -1 otherwise.
 */
int main(int ac __attribute__((unused)), char **av)
{
	int output;

	/* Collect the name of the shell */
	shell_name = av[0];
	/* Identifies the terminal associated with the file descriptor */
	if (isatty(STDIN_FILENO) == 1)
		output = interactive_mode();
	else
		output = no_interactive_mode();

	return (output);
}
