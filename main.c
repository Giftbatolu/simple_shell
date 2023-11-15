#include "shell.h"

/**
 * main - The main function of the shell
 * @argv:The argument vector
 * @argc: The argument count.
 *
 * Return: Always 0 on sucess.
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char **av = NULL;
	size_t b = 0;

	(void) argc;
	(void) argv;
	while (1)
	{
		display_prompt();
		if (getline(&line, &b, stdin) == -1)
		{
			perror("Error (getline)");
			free(line);
			if (isatty(STDIN_FILENO) != 0)
				write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		line[_strcspn(line, "\n")] = '\0';
		/*handle_comment(line);*/
		av = split_string(line, " ");
		if (strcmp(av[0], "exit") == 0)
			exit(0);
		if (av[0] != NULL)
			execute_command(av);
	}
	free(av);
	free(line);
	return (0);
}


/**
 * display_prompt - function that display prompt
 *
 * Return: Always success.
 */
int display_prompt(void)
{
	char *prompt = "$ ";
	ssize_t write_count = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		write_count = write(STDOUT_FILENO, prompt, 2);
		fflush(stdout);
		if (write_count == -1)
			exit(0);
	}
	return (0);
}
