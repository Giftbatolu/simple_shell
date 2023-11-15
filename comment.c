#include "shell.h"

/**
 * handle_comment - function that handle comment.
 * @input: The input to handle
 *
 * Return: Always 0.
 */
void handle_comment(char *input)
{
	int b = 0;

	if (input[b] == '#')
		input[b] = '\0';
	while (input[b] != '\0')
	{
		if (input[b] == '#' && input[b - 1] == ' ')
			break;
		b++;
	}
	input[b] = '\0';
}
