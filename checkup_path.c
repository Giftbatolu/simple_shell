#include "shell.h"

/**
 * checkup_path - function that check the path.
 * @command: The command
 *
 * Return: The path if availible or otherwise 0.
 */
char *checkup_path(char *command)
{
	char *path, *path_cpy, *file_path, *path_token;
	int command_len, directory_len;
	struct stat h;

	path = _getenv("PATH");
	if (path)
	{
		path_cpy = strdup(path);
		command_len = _strlen(command);
		path_token = strtok(path_cpy, ":");
		while (path_token != NULL)
		{
			directory_len = _strlen(path_token);
			file_path = malloc(command_len + directory_len + 2);
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");
			if (stat(file_path, &h) == 0)
			{
				free(path_cpy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_cpy);
		if (stat(command, &h) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}
