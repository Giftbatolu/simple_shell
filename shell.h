#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stddef.h>

extern char **environ;
void handle_comment(char *input);
char **split_string(char *input_string, char *delimiter);
void execute_command(char **av);
void display_prompt(void);

#define realsize(a, b) (((a) < (b)) ? (a) : (b))
#define BUFSIZE 1024

/*shell_helper.c fuctions*/
int _strncmp(char *s1, char *s2, size_t len);
char *_strchr(char *str, char c);
char *_getenv(char *name);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

/*shell_helper-1.c functions*/
int _strcspn(char *str, char *str_sub);
int _strspn(char *str, char *str_sub);
int _strlen(char *s);
void _memset(char *str, int fill, int n);
void _memcpy(char *dest, char *src, unsigned int bytes);

/*shell_utils.c functions*/
char *_strtok(char *string, char *delim, char **token_ptr);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
