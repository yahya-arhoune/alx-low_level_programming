#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define BUFSIZE 1024

/**
 * error_exit - print an error message and exit with the given status.
 * @status: the exit status.
 * @format: the format string to print.
 */

void error_exit(int status, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	dprintf(STDERR_FILENO, "Error: ");
	vdprintf(STDERR_FILENO, format, args);
	va_end(args);

	exit(status);
}

/**
 * main - copy the content of a file to another file.
 * @argc: the number of argument.
 * @argv: the arguments.
 *
 * Return: always 0.
 */

int main(int argc, char **argv)
{
	int fd_from, fd_to;
	ssize_t nread;
	char buf[BUFSIZE];
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to\n");

	fd_from = open(argv[1], O_RDONLY);

	if (fd_from == -1)
		error_exit(98, "Can't read from file %s\n", argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);

	if (fd_to == -1)
		error_exit(99, "Can't write to %s\n", argv[2]);

	while ((nread = read(fd_from, buf, BUFSIZE)) > 0)
	{
		if (write(fd_to, buf, nread) != nread)
			error_exit(99, "Can't write to %s\n", argv[2]);
	}

	if (nread == -1)
		error_exit(98, "Can't read from file %s\n", argv[1]);

	if (close(fd_from) == -1)
		error_exit(100, "Can't close fd %d\n", fd_from);

	if (close(fd_to) == -1)
		error_exit(100, "Can't close fd %d\n", fd_to);

	return (0);
}
