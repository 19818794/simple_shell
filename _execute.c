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
	int res, status, cmd_type;
	void (*function)(char **cmd);

	if (parse[0] != NULL)
	{
		cmd_type = _cmd_type(parse[0]);
		if (cmd_type == INTERNAL_CMD)
		{
			function = _get_function(parse[0]), function(parse);
		}
		else if (cmd_type == EXTERNAL_CMD || cmd_type == PATH_CMD)
		{
			child_pid = fork(); /* Create a new process */
			if (child_pid == -1) /*Error handling for failed fork*/
			{
				perror("Error: fork()\n"), exit(EXIT_FAILURE);
			}
			else if (child_pid == 0) /* Child process */
			{
				if (cmd_type == EXTERNAL_CMD)
					res = execve(parse[0], parse, NULL);
				else if (cmd_type == PATH_CMD)
					res = execve(_check_path(parse[0]),
							parse, NULL);
				if (res == -1) /*Error handling failed execve*/
				{
					if (_strcmp(parse[0], "\n") == 0)
						_print("\n");
					else
						_print_err(parse[0]);
					exit(EXIT_FAILURE);
				}
			}
			else /* Parent process */
				wait(&status); /*Waitfor childprocess to exit*/
		}
		else
			_print_err(parse[0]);
	}
}
