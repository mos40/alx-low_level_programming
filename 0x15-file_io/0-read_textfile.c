#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read a text file and print it to STDOUT.
 * @filename: reading from a text file
 * @letters: how many letters must be read
 * Return: w- the number of bytes actually read and printed
 *        When the function fails or the filename is NULL, the value is 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t right;
	ssize_t tight;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	tight = read(fd, buf, letters);
	right = write(STDOUT_FILENO, buf, tight);

	free(buf);
	close(fd);
	return (right);
}
