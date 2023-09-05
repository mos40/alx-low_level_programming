#include "main.h"

/**
 * create_file - Make a file.
 * @filename: A pointer to the name of the file to be created.
 * @text_content: A string pointer to write to the file.
 *
 * Return: If the function fails, the result is -1.
 *         Alternatively, 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, h, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	h = write(fd, text_content, length);

	if (fd == -1 || h == -1)
		return (-1);

	close(fd);

	return (1);
}
