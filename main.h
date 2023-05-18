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

/* Global variables */
char *shell_name;

/* Object_like macros */
#define BUFFER_SIZE 1024

/* Prototypes */
/* Print a string */
int _putchar(char c);
void _print(char *str);
void _print_err(char *cmd);

/* String functions*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *line);
int _strcmp(char *s1, char *s2);

/* Assistance functions */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* Advanced functions */
ssize_t _getline_(char **line, size_t *size, FILE *stream);

/* Main functions */
char *_read_line(void);
char **_split_line(char *line, char *delimiter);
void _execute(char **parse);

#endif
