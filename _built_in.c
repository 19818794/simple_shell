#include "main.h"

/**
 * _exit_ - exits the shell terminal.
 * @parse: the command to be checked.
 *
 * Return: void
 */
void _exit_(char **parse)
{
	int length = 0;
	char **ptr = parse;

	while (ptr[length] != NULL)
		length++;

	if (length == 1)
	{
		should_run = 0;
		exit(0);
	}
	else
		_print("Command syntax: exit\n");
}

/**
 * _get_function - gets a corresponding function based on the command given.
 * @cmd: the command name to be checked.
 *
 * Return: a pointer to the corresponding function,
 * otherwise NULL if it fails.
 */
void (*_get_function(char *cmd))(char **)
{
	builtin	bif[] = {
		{"exit", _exit_}
	};
	int i = 0;

	/* Iterate through the array of built-in functions */
	while (i < 1)
	{
		/*
		 * Check the given command it it matches the name of
		 * the current built-in function.
		 */
		if (_strcmp(cmd, bif[i].cmd_name) == 0)
			return (bif[i].function);
		i++;
	}

	return (NULL);
}