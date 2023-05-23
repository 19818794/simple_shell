#include "main.h"

/**
 * _cd_ - changes the current directory of the process.
 * @parse: the command to be checked.
 *
 * Return: void.
 */
void _cd_(char **parse)
{
	char **ptr = parse, *path;
	int len_parse = 0, res;

	/* Changes the current directory of the process */
	while (ptr[len_parse] != NULL)
		len_parse++;
	if (len_parse == 1)
		path = _getenv("HOME"); /* cd $HOME */
	else if (len_parse == 2)
	{
		if (_strcmp(parse[1], "-") == 0)
			path = _getenv("OLDPWD"); /* cd - */
		else
			path = parse[1]; /* cd [DIRECTORY] */
	}
	else
	{
		logical_counter = 1; /* Command fails */
		exit_status = 2;
		_cd_error(parse[1]);
	}
	if (len_parse <= 2)
	{
		res = chdir(path);
		if (res != 0)
		{
			logical_counter = 1; /* Command fails */
			exit_status = 2;
			_cd_error(parse[1]);
		}
		logical_counter = 0; /* Command succeeds */
		/*Update the environment variables when directory was changed*/
		_update_env(path);
	}
}

/**
 * _update_env - updates the environment variables when directory was changed.
 * @path: the directory to be added.
 *
 * return: void.
 */
void _update_env(char *path)
{
	char *oldpwd_value, *pwd_value, *pwd_path, **env = environ;
	int oldpwd_pos = 0, pwd_pos = 0, pwd_path_size;
	struct stat st;

	oldpwd_value = _getenv("OLDPWD");
	if (oldpwd_value == NULL)
		_print("Error: OLDPWD value not found\n");
	pwd_value = _getenv("PWD");
	if (pwd_value == NULL)
		_print("Error: PWD value not found\n");
	while (_strncmp(env[oldpwd_pos], "OLDPWD", 6) != 0)
		oldpwd_pos++;
	while (_strncmp(env[pwd_pos], "PWD", 3) != 0)
		pwd_pos++;
	/* -- Updates OLDPWD -- */
	env[oldpwd_pos] = _realloc(env[oldpwd_pos],
		_strlen(oldpwd_value) + 8, _strlen(pwd_value) + 8);
	if (env[oldpwd_pos] == NULL)
		perror("Error: realloc\n");
	_snprint(env[oldpwd_pos], _strlen(pwd_value) + 8, "OLDPWD",
			pwd_value);
	/* -- Updates PWD -- */
	pwd_path_size = _strlen(pwd_value) + _strlen(path) + 2;
	pwd_path = malloc(sizeof(pwd_path) * pwd_path_size);
	if (pwd_path == NULL)
		perror("Error: malloc\n");
	if (getcwd(pwd_path, sizeof(pwd_path) * pwd_path_size) == NULL)
		perror("Error: getcwd()");
	if (stat(pwd_path, &st) == 0)
	{
		env[pwd_pos] = _realloc(env[pwd_pos],
			_strlen(pwd_value) + 5, _strlen(pwd_path) + 5);
		if (env[pwd_pos] == NULL)
			perror("Error: realloc\n");
		_snprint(env[pwd_pos], _strlen(pwd_path) + 5, "PWD",
				pwd_path);
	}
	else
		perror("Error: stat");
}
