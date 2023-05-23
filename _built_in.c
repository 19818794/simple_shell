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
		logical_counter = 0, should_run = 0, exit(status);
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
			logical_counter = 1, exit_status = 2,
			_exit_error(ptr[1]);
		else
		{
			status = _atoi(ptr[1]);
			if (status < 0)
				logical_counter = 1, exit_status = 2,
				_exit_error(ptr[1]);
			else
			{
				logical_counter = 0, should_run = 0;
				exit(status);
			}
		}
	}
	else
		logical_counter = 1, exit_status = 2, _exit_error(ptr[1]);
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
		{"env", _env_},
		{"setenv", _setenv_},
		{"unsetenv", _unsetenv_},
		{"cd", _cd_}
	};
	int i = 0;

	/* Iterate through the array of built-in functions */
	while (i < 5)
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
	char **ptr = parse, **ptr_env = environ, *msg;

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
		logical_counter = 0; /* Command succeeds */
	}
	else
	{
		logical_counter = 1; /* Command fails */
		exit_status = 127;
		msg = _env_error(ptr[1]);
		if (access(msg, F_OK) == -1)
			perror(msg);
	}
}

/**
 * _setenv_ - initialize a new environment variable, or modify an existing one.
 * @parse: the command to be checked.
 *
 * Return void.
 */
void _setenv_(char **parse)
{
	int len_parse = 0, i = 0, j = 0, len_new_line, len_name;
	char *env_value, **new_env = environ;

	while (parse[len_parse] != NULL)
		len_parse++;
	if (len_parse != 3)
	{
		logical_counter = 1; /* Command fails */
		_print("Command syntax: setenv VARIABLE VALUE\n");
		exit_status = 127;
	}
	else
	{
		len_name = _strlen(parse[1]);
		len_new_line = len_name + _strlen(parse[2]) + 2;
		env_value = _getenv(parse[1]);
		if (env_value != NULL)
		{
			while (new_env[j] != NULL && _strncmp(parse[1],
						new_env[j], len_name) != 0)
				j++;
			new_env[j] = _realloc(new_env[j],
			len_name + _strlen(env_value) + 2, len_new_line);
			if (new_env[j] == NULL)
				perror("Error: realloc\n");
			_snprint(new_env[j], len_new_line, parse[1], parse[2]);
		}
		else
		{
			while (new_env[i] != NULL)
				i++;
			new_env[i] = malloc(len_new_line);
			if (new_env[i] == NULL)
				perror("Error: malloc\n");
			_snprint(new_env[i], len_new_line, parse[1], parse[2]);
			new_env[i + 1] = NULL;
		}
		logical_counter = 0; /* Command succeeds */
	}
}

/**
 * _unsetenv_ - removes an environment variable.
 * @parse: the command to be checked.
 *
 * Return: void.
 */
void _unsetenv_(char **parse)
{
	char **ptr = parse, **env = environ;
	int len_parse, len_var, i, j, count = 0, k, l, m;

	len_parse = _ptrlen(ptr);
	if (len_parse != 2)
		logical_counter = 1,
		_print("Command syntax: unsetenv VARIABLE\n"),
		exit_status = 127;
	else
	{
		len_var = _strlen(parse[1]);
		for (i = 0; env[i] != NULL; i++, count = 0)
		{
			for (j = 0; parse[1][j] != '\0' && j < len_var; j++)
				if (parse[1][j] == env[i][j])
					count++;
			if (len_var == count)
				break;
		}
		if (len_var == count)
		{
			for (k = i; env[k] != NULL && env[k + 1] != NULL; k++)
			{
				for (l = 0; env[k][l] != '\0'; l++)
					env[k][l] = 0;
				for (m = 0; env[k + 1][m] != '\0'; m++)
					;
				if (l < m)
					env[k] = _realloc(env[k], l, m);
				for (l = 0; env[k + 1][l] != '\0'; l++)
					env[k][l] = env[k + 1][l];
			}
			free(env[k]), env[k] = NULL, free(env[k + 1]),
			logical_counter = 0; /* Command succeeds */
		}
		else
			logical_counter = 1,
			_print("Error: VARIABLE not found\n"),
			exit_status = 127;
	}
}
