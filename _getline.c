#include "shell.h"

/**
 * _getline - gets line from STDIN and places it in the buffer
 * @fd: int assigned to the read of STDIN
 * Return: pointer to buffer with formatted input from STDIN
 */
char *_getline(int fd)
{
	unsigned int b, d;
	char *buf;
	static unsigned int buf_size = BUFSIZE;

	buf = malloc(sizeof(char) * buf_size);
	if (buf == NULL)
	{
		perror("malloc for buffer failed\n");
		return (NULL);
	}
	d = 0;
	_memset(buf, '\0', buf_size);
	while ((b = read(fd, buf + d, buf_size - d)) > 0)
	{
		if (b < (buf_size - d))
			return (buf);
		buf_size *= 2;
		_realloc(buf, buf_size, buf_size / 2);
		if (buf == NULL)
		{
			perror("realloc failed\n");
			return (NULL);
		}
		d += b;
	}
	if (b == 0)
		_memcpy(buf, "exit", 5);
	return (buf);
}
