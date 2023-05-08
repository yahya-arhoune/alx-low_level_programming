#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * append_text_to_file - function that appends text at the end of a file.
 * @filename: pointer to the string containing
 * the name of the file to append to.
 * @text_content: pointer to the string containing the
 * text to append to the file.
 *
 * Return: 1 on success and -1 on failure.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	if (filename == NULL)
	{
		return (-1);
	}

	int fd = open(filename, O_WRONLY | O_APPEND);

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
			clode(fd);
			return (-1);
		}
	}

	close(fd);

	return (1);
}
