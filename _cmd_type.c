#include "main.h"

/**
 * _cmd_type - determines the type of command.
 * @cmd: the command to be checked.
 *
 * Return: an integer value representing the type of command (EXTERNAL_CMD = 1,
 * PATH_CMD = 2, INTERNAL_CMD = 3), otherwise the value of (INVALID_CMD = -1).
 */
int _cmd_type(char *cmd)
{
	char *path = NULL;
	int i;
	char *internal_cmd[] = {"exit", "env", "setenv", "unsetenv", NULL};

	/* Check if the cmd is an internal command */
	for (i = 0; internal_cmd[i] != NULL; i++)
	{
		if (_strcmp(cmd, internal_cmd[i]) == 0)
			return (INTERNAL_CMD);
	}
	/* Check if the cmd is an extaernal command */
	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == '/')
			return (EXTERNAL_CMD);
	}
	/* Check if the cmd is a path command */
	path = _check_path(cmd);
	if (path != NULL)
	{
		free(path);
		return (PATH_CMD);
	}

	return (INVALID_CMD);
}
