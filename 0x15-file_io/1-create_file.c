#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to be created.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int file_Descriptor, x, length = 0;

	if (filename == NULL)
	return (-1);

	if (text_content != NULL)
	{
	for (length = 0; text_content[length];)
	length++;
	}

	file_Descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	x = write(file_Descriptor, text_content, length);

	if (file_Descriptor == -1 || x == -1)
	return (-1);

	close(file_Descriptor);

	return (1);
}
