#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - function that reads a text file and prints
 * it to the POSIX standard output.
 * @filename: text file to read
 * @letters: number of letters to read.
 *
 * Return: the actual number of letters it could read and print,
 * if filename is NULL return 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}
