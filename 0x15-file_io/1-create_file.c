#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * create_file - function that creates a file.
 * @filename: pointer to a string containing the name of the file to create.
 * @text_content: pointer to a string containing the text to write to the file.
 *
 * Return: 1 on success, -1 on failure (file can not be created,
 * file can not be written, write “fails”, etc…).
 */

int create_file(const char *filename, char *text_content)
{
	int fd;

	if (filename == NULL)
	{
		return (-1);
	}

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (fd == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		ssize_t len = strlen(text_content);
		ssize_t w = write(fd, text_content, len);

		if (w != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);

	return (1);
}
