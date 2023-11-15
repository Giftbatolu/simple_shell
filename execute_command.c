/**
 * execute_command - function that execute command
 * @av: The command to be executed
 *
 * Return: Always 0.
 */
void execute_command(char **av)
{
	/*pid_t child_process;*/
	/*int status;*/
	char *command = NULL;
	/*char *actual_cmd = NULL;*/

	if (av)
	{
		command = av[0];
		if (execve(command, av, environ) == -1)
		{
			perror("Error (execve)");
		}
	}
}
