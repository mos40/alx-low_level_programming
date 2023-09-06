#include "main.h"

/**
 * append_text_to_file - text that is added at the conclusion of a file.
 * @filename: the name of the file, as a pointer.
 * @text_content: The final string to include in the file
 *
 * Return: If the function is unsuccessful or the filename is NULL, -1.
 *         -1 if the user doesn't have write access and the file doesn't exist.
 *         Without it, 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int b, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	b = open(filename, O_WRONLY | O_APPEND);
	w = write(b, text_content, len);

	if (b == -1 || w == -1)
		return (-1);

	close(b);

	return (1);
}
