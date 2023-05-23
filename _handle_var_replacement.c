#include "main.h"

/**
 * _handle_var_replacement - handles variables replacement.
 * @parse: the command and its arguments as input.
 *
 * Return: void.
 */
void _handle_var_replacement(char **parse)
{
	int i, m, pos;
	char *before, *after;

	if (_strcmp(parse[0], "echo") == 0 ||
			_strcmp(parse[0], "/bin/echo") == 0)
	{
		for (i = 1; parse[i] != NULL; i++)
		{
			if (_strstr(parse[i], "$") != NULL)
			{
				before = malloc(sizeof(char) *
						_strlen(parse[i]));
				after = malloc(sizeof(char) *
						_strlen(parse[i]));
				if (before == NULL || after == NULL)
					perror("Error: malloc");
				m = 0;
				while (parse[i][m] != '$')
					before[m] = parse[i][m], m++;
				before[m] = '\0';
				if (before != NULL)
					_print(before);
				m++, pos = m;
				if (parse[i][pos] == '$' ||
						parse[i][pos] == '?')
					_handle_dollar_qst_mark_var_rep(
							parse[i], after, pos);
				else
					_handle_env_var_replacement(parse[i],
							pos, after);
				_print(" "), free(before), free(after);
			}
			else
				_print(parse[i]), _print(" ");
		}
		_print("\n"), exit(EXIT_SUCCESS);
	}
}
