#include "main.h"

/**
 * append_text_to_file - This function appends txt at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If ever the function fails or filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int s, m, l = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}

	s = open(filename, O_WRONLY | O_APPEND);
	m = write(s, text_content, l);

	if (s == -1 || m == -1)
		return (-1);

	close(s);

	return (1);
}
