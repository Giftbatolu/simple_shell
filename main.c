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
		if (isatty(STDIN_FILENO))
			display_prompt();
		if (getline(&line, &b, stdin) == -1)
		{
			perror("Error (getline)");
			free(line);
			exit(0);
		}
		line[_strcspn(line, "\n")] = '\0';
		/*handle_comment(line);*/
		av = split_string(line, " ");
		if (av[0] != NULL)
			execute_command(av);
	}
	free(av);
	free(line);
	return (0);
}


/**
 * display_prompt - function that display prompt
 */
void display_prompt(void)
{
	char *prompt = "$ ";

	write(STDOUT_FILENO, prompt, 2);
	fflush(stdout);
}
