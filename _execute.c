#include "main.h"

/**
 * _execute - executes a command entered by the user in the shell.
 * @parse: the command and its arguments as input.
 *
 * Return: void.
 */
void _execute(char **parse)
{
	pid_t child_pid;
	int res, status;

	/* Create a new process */
	child_pid = fork();
	/* Error handling for failed fork */
	if (child_pid == -1)
	{
		perror("Error: fork()\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		/* Child process */
		res = execve(parse[0], parse, NULL);
		/* Error handling for failed execve */
		if (res == -1)
		{
			if (_strcmp(parse[0], "\n") == 0)
				_print("\n");
			else
				_print_err(parse[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		/* Wait for child process to exit */
		wait(&status);
	}
}
