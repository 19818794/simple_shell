#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/*
 * Desc: header file containing all libraries, object-like macros,
 * structures and prototypes used by `0x16. C - Simple Shell` project.
 */

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/* Structures */
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

/**
 * struct built_in_functions - type struct builtin.
 * @cmd_name: the command's name.
 * @function: the function that executes the corresponding command.
 *
 * Description: maps a command name to a function.
 */
typedef struct built_in_functions
{
	char *cmd_name;
	void (*function)(char **parse);
} builtin;

/* Global variables */
char *shell_name;
extern char **environ;
int should_run;
int cmd_counter;

/* Object_like macros */
#define BUFFER_SIZE 1024
#define INVALID_CMD -1
#define EXTERNAL_CMD 1
#define PATH_CMD 2
#define INTERNAL_CMD 3

/* Prototypes */
/* Print a string */
int _putchar(char c);
void _print(char *str);
void _perror(char *cmd);
void _snprint(char *ptr, int size, char *s1, char *s2);

/* String functions*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *line);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, int n);

/* Assistance functions */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strcat(char *dest, char *src);
int _atoi(char *s);
void _ctrl_c_signal_handler(int signal __attribute__((unused)));
char *int_to_str(int num);

/* Handle errors*/
void _exit_error(char *status);
char *_env_error(char *ptr);
void _cd_error(char *arg);

/* Handle comments */
char *_handle_comments(char *line);

/* Handel environment*/
size_t _list_len(const list_t *h);
list_t *_get_node_at_index(list_t *head, unsigned int index);
list_t *_add_node_end(list_t **head, char *str);
char *_getenv(char *name);

/* Advanced functions */
ssize_t _getline_(char **line, size_t *size, FILE *stream);
void _update_env(char *path);
void _cd_(char **parse);

/* Handle the PATH */
char *_check_path(char *cmd);
int _cmd_type(char *cmd);

/* Built_in functions */
void _exit_(char **parse);
void (*_get_function(char *cmd))(char **);
void _env_(char **parse);
void _setenv_(char **parse);
void _unsetenv_(char **parse);

/* Main functions */
char *_read_line(void);
char **_split_line(char *line, char *delimiter);
void _execute(char **parse);

#endif
