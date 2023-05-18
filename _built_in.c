#include "main.h"

/**
 * _exit_ - exits the shell terminal.
 * @parse: the command to be checked.
 *
 * Return: void
 */
void _exit_(char **parse)
{
	int length = 0, status = 0, i, check = 0;
	char **ptr = parse;

	while (ptr[length] != NULL)
		length++;
	if (length == 1)
	{
		should_run = 0;
		exit(status);
	}
	else if (length == 2)
	{
		for (i = 0; ptr[1][i]; i++)
		{
			if (ptr[1][i] < 48 || ptr[1][i] > 57)
			{
				if (i > 0 || ptr[1][i] != 45)
				{
					check = 1;
					break;
				}
			}
		}
		if (check == 1 || (_strlen(ptr[1]) == 1 && ptr[1][0] == 45))
			_print("Error: exit function expected integer argument\n");
		else
		{
			status = _atoi(ptr[1]);
			if (status < 0)
				_print("Error: Illegal number\n");
			else
			{
				should_run = 0;
				exit(status);
			}
		}
	}
	else
		_print("Command syntax: exit [argument]\n");
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
		{"exit", _exit_},
		{"env", _env_}
	};
	int i = 0;

	/* Iterate through the array of built-in functions */
	while (i < 2)
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

/**
 * _env_ - prints the current environment.
 * @parse: the command to be checked, not used here.
 *
 * Return: void.
 */
void _env_(char **parse)
{
	int length = 0, i = 0;
	char **ptr = parse, **ptr_env = environ;

	while (ptr[length] != NULL)
		length++;
	if (length == 1)
	{
		while (ptr_env[i] != NULL)
		{
			_print(ptr_env[i]);
			_print("\n");
			i++;
		}
	}
	else
		_print("Command syntax: env\n");
}
