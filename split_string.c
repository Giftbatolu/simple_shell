#include "shell.h"
#include <stdio.h>

/**
 * split_string - tokenizes input and stores it into an array
 *@input_str: input to be parsed
 *@delimiter: delimiter to be used, needs to be one character string
 *
 *Return: array of tokens
 */

char **split_string(char *input_str, char *delimiter)
{
	int num_deli = 0;
	char **arg = NULL;
	char *token = NULL;
	char *token_ptr = NULL;

	token = _strtok(input_str, delimiter, &token_ptr);
	while (token != NULL)
	{
		arg = _realloc(arg, sizeof(*arg) * num_deli, sizeof(*arg) * (num_deli + 1));
		arg[num_deli] = token;
		token = _strtok(NULL, delimiter, &token_ptr);
		num_deli++;
	}
	arg = _realloc(arg, sizeof(*arg) * num_deli, sizeof(*arg) * (num_deli + 1));
	arg[num_deli] = NULL;
	return (arg);
}
