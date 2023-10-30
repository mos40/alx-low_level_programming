#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocates 1024 bytes for a buf.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buf
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The fd to be closed.
 */
void close_file(int fd)
{
	int copy;

	copy = close(fd);

	if (copy == -1)
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
	int f, too, red, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	f = open(argv[1], O_RDONLY);
	red = read(f, buffer, 1024);
	too = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (f == -1 || red == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(too, buffer, red);
		if (too == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		red = read(f, buffer, 1024);
		too = open(argv[2], O_WRONLY | O_APPEND);

	} while (red > 0);

	free(buffer);
	close_file(f);
	close_file(too);

	return (0);
}
