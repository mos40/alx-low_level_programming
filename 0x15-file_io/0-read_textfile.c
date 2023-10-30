#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- function reads a text file and prints its contents to STDOUT
 * @filename: The name of the text file being read
 * @letters: number of letters to be read from the file
 * Return: the actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fileDescriptor;
	ssize_t ritten;
	ssize_t p;

	fileDescriptor = open(filename, O_RDONLY);
	if (fileDescriptor == -1)
	return (0);

	buffer = malloc(sizeof(char) * letters);
	p = read(fileDescriptor, buffer, letters);
	ritten = write(STDOUT_FILENO, buffer, p);

	free(buffer);
	close(fileDescriptor);
	return (ritten);
}
