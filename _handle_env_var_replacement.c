#include "main.h"

/**
 * _handle_env_var_replacement - handles environment variable replacement.
 * @parse: arguments as input.
 * @pos: position of the string after the $ dollar sign.
 * @after: string after $ dollar sign.
 *
 * Return: void
 */
void _handle_env_var_replacement(char *parse, int pos, char *after)
{
	int n = 0;
	char *env_info;

	if (parse[pos] == '\0')
		_print("$");
	else
	{
		while (parse[pos] != '\0' && parse[pos] != ' ')
		{
			after[n] = parse[pos];
			pos++;
			n++;
		}
		after[n] = '\0';

		env_info = _getenv(after);
		if (env_info != NULL)
			_print(env_info);
	}
}
