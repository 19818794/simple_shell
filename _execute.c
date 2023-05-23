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
	int status, cmd_type;
	void (*function)(char **cmd);

	if (parse[0] != NULL)
	{
		cmd_type = _cmd_type(parse[0]);
		if (cmd_type == INTERNAL_CMD)
			function = _get_function(parse[0]), function(parse);
		else if (cmd_type == EXTERNAL_CMD || cmd_type == PATH_CMD)
		{
			child_pid = fork(); /* Create a new process */
			if (child_pid == -1) /*Error handling for failed fork*/
				perror("Error: fork()\n"), exit(EXIT_FAILURE);
			else if (child_pid == 0) /* Child process */
				_execute_ext_path_cmds(parse, cmd_type);
			else /* Parent process */
			{
				wait(&status); /*Waitfor childprocess to exit*/
				if (WIFEXITED(status))
				{
					exit_status = WEXITSTATUS(status);
					if (exit_status != 0)
						logical_counter = 1;
					else
						logical_counter = 0;
				}
				else
					logical_counter = 1, _perror(parse[0]);
			}
		}
		else
			logical_counter = 1, _perror(parse[0]),
			exit_status = 127;
		cmd_counter++; /* Next command */
	}
	else
		logical_counter = 1; /* Command fails */
}
