#include "main.h"

/**
 * _handle_dollar_qst_mark_var_rep - handles dollar and question mark variables
 * replacement.
 * @parse: arguments as input.
 * @after: string after $ dollar sign.
 * @pos: position of the $ dollar or ? question mark signs.
 *
 * Return: void
 */
void _handle_dollar_qst_mark_var_rep(char *parse, char *after, int pos)
{
	int n = 0, m = pos + 1;
	pid_t my_ppid;

	while (parse[m] != '\0')
	{
		after[n] = parse[m];
		m++;
		n++;
	}
	after[n] = '\0';
	if (parse[pos] == '$')
	{
		my_ppid = getppid();
		_print(int_to_str(my_ppid));
	}
	else
		_print(int_to_str(exit_status));
	if (after != NULL)
		_print(after);
}
