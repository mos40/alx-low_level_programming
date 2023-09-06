#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - 1024 bytes are set aside for a buffer.
 * @file: The name of the file buffer where the characters are stored.
 *
 * Return: a pointer to the recently allocated buffer.
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
 * close_file - file descriptors are closed.
 * @fd: The closing of the file descriptor.
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
 * main - copies a file's content from one file to another.
 * @argc: how many arguments were given to the program.
 * @argv: an array of parameters' pointers.
 *
 * Return: Zero for success.
 *
 * Description: Exit code 97 should be used if the argument count is wrong.
 * 98 is the exit code if file_from either doesn't exist or can't be read.
 * Exit code 99 is generated if file_to cannot be created or written to.
 * Exit code 100 is used if file_to or file_from cannot be closed.
 */

int main(int argc, char *argv[])
{
	int from, to, row, white;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	row = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || row == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		white = write(to, buffer, row);
		if (to == -1 || white == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		row = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (row > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
