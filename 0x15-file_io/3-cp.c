#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocates 1024 bytes memory for a buf.
 * @file: The name of the file for buffer is being allocated for.
 *
 * Return: A pointer to the newly-allocated buf.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
		"Error: Unable to allocate memory for %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 always on success.
 *
 * Description: If the argument count is incorrect - exit with code 97.
 * If file_from does not exist or cannot be read - exit with code 98.
 * If file_to cannot be created or written to - exit with code 99.
 * If either the src or file_from cannot be closed - exit with code 100.
 */
int main(int argc, char *argv[])
{
	int f, u, a, h;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp src_file destination_file\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	f = open(argv[1], O_RDONLY);
	a = read(f, buffer, 1024);
	u = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (f == -1 || a == -1)
		{
			dprintf(STDERR_FILENO,
			"Error: Unable to read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		h = write(u, buffer, a);
		if (u == -1 || h == -1)
		{
			dprintf(STDERR_FILENO,
			"Error: Error: Unable to write to file %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		a = read(f, buffer, 1024);
		u = open(argv[2], O_WRONLY | O_APPEND);

	} while (a > 0);

	free(buffer);
	close_file(f);
	close_file(u);

	return (0);
}
