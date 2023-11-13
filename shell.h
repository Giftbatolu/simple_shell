#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

extern char **environ;

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

#endif
