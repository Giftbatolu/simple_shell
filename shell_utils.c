#include "shell.h"

/**
 *_strtok - function that tokenizes a string
 *@string: string to be tokenized
 *@delim: delimiter to be used to tokenize the string
 *@token_ptr: pointer to be used to keep track of the next token
 *
 *Return: The next available token
 */
char *_strtok(char *string, char *delim, char **token_ptr)
{
	char *end;

	if (string == NULL)
		string = *token_ptr;

	if (*string == '\0')
	{
		*token_ptr = string;
		return (NULL);
	}
	string += _strspn(string, delim);
	if (*string == '\0')
	{
		*token_ptr = string;
		return (NULL);
	}
	end = string + _strcspn(string, delim);
	if (*end == '\0')
	{
		*token_ptr = end;
		return (string);
	}

	*end = '\0';
	*token_ptr = end + 1;
	return (string);
}

/**
 * _realloc - function that reallocates a memory block
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size of ptr
 * @new_size: size of the new memory to be allocated
 *
 * Return: pointer to the address of the new memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *temp_holder;
	unsigned int b;

	if (ptr == NULL)
	{
		temp_holder = malloc(new_size);
		return (temp_holder);
	}
	else if (new_size == old_size)
		return (ptr);
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		temp_holder = malloc(new_size);
		if (temp_holder != NULL)
		{
			for (b = 0; b < realsize(old_size, new_size); b++)
				*((char *)temp_holder + b) = *((char *)ptr + b);
			free(ptr);
			return (temp_holder);
		}
		else
			return (NULL);
	}
}
