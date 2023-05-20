#include "main.h"

/**
 * _exit_error - gets the status of exit command.
 * @status: The wrong status that was submitted.
 *
 * Return: error message.
 */
void _exit_error(char *status)
{
	char *ptr = int_to_str(cmd_counter);

	_print(shell_name);
	_print(": ");
	_print(ptr);
	_print(": exit: Illegal number: ");
	_print(status);
	_print("\n");
}

/**
 * _env_error - generates error message for environment-related issues.
 * @ptr: the argument to be checked.
 *
 * Return: error message.
 */
char *_env_error(char *ptr)
{
	char *error_msg;
	int i, j = 0;

	/* Allocate memory for error_msg */
	error_msg = malloc(sizeof(char) * (_strlen(ptr) + 8));
	if (error_msg == NULL)
		perror("Error: malloc\n");
	/* Copy "env: '" to error_msg */
	_strcpy(error_msg, "env: '");
	i = 6;
	/* Copy the argument string to error_msg */
	while (i < (_strlen(ptr) + 7) && ptr[j] != '\0')
	{
		error_msg[i] = ptr[j];
		i++;
		j++;
	}
	/* Concatenate "'" to error_msg */
	error_msg[i] = '\'';
	error_msg[++i] = '\0';

	return (error_msg);
}

/**
 * _cd_error - prints an error message for the cd command.
 * @arg: the argument that caused the error.
 *
 * Return: error message.
 */
void _cd_error(char *arg)
{
	char *ptr = int_to_str(cmd_counter);

	_print(shell_name);
	_print(": ");
	_print(ptr);
	_print(": cd: can't cd to ");
	_print(arg);
	_print("\n");
}
