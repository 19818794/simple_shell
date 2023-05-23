#include "main.h"

/**
 * _execute_ext_path_cmds - executes external or path cmds in the shell.
 * @parse: the command and its arguments as input.
 * @cmd_type: typed of cmd to be executed.
 *
 * Return: void.
 */
void _execute_ext_path_cmds(char **parse, int cmd_type)
{
	int res;

	_handle_var_replacement(parse);
	if (cmd_type == EXTERNAL_CMD)
		res = execve(parse[0], parse, NULL);
	else if (cmd_type == PATH_CMD)
		res = execve(_check_path(parse[0]), parse, NULL);
	if (res == -1) /*Error handling failed execve*/
	{
		if (_strcmp(parse[0], "\n") == 0)
			_print("\n");
		else
			_perror(parse[0]);
		exit(EXIT_FAILURE);
	}
}
