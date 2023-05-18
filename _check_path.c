#include "main.h"

/**
 * _check_path - checks if a command exists in one of the directories
 * in the PATH environment variable.
 * @cmd: the command to check.
 *
 * Return: pointer to the full path of the command if found,
 * otherwise NULL.
 */
char *_check_path(char *cmd)
{
	char *path, **path_directories, *full_path;
	unsigned int i;
	list_t *head = NULL;
	struct stat st;

	/* Get value of the PATH environment variable */
	path = _getenv("PATH");
	if (path != NULL)
	{
		path_directories = _split_line(path, ":");
		for (i = 0; path_directories[i] != NULL; i++)
			_add_node_end(&head, path_directories[i]);
	}
	for (i = 0; _get_node_at_index(head, i) != NULL; i++)
	{
		full_path = malloc(sizeof(char) * (_strlen(cmd) +
			_strlen(_get_node_at_index(head, i)->str + 2)));
		if (full_path == NULL)
			return (NULL);
		full_path = _strcat(_get_node_at_index(head, i)->str, "/");
		full_path = _strcat(full_path, &cmd[0]);
		full_path = _strcat(full_path, "\0");
		if (stat(full_path, &st) == 0)
		{
			if (access(full_path, F_OK) == 0)
			{
				free(path_directories);
				return (full_path);
			}
		}
		free(full_path);
	}
	free(path_directories);
	return (NULL);
}
