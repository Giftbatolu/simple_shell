#include "shell.h"

/**
 * print_environment - print the env.
 */
void print_environment(void)
{
	size_t len;
	int b = 0;

	while (environ[b])
	{
		len = strlen(environ[b]);
		write(STDOUT_FILENO, environ[b], len);
		write(STDOUT_FILENO, "\n", 1);
		b++;
	}
}
