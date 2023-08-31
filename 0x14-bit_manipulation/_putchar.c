#include "main.h"
#include <unistd.h>
/**
 * _putchar - stdout receives the character c
 * @c: The printed character
 *
 * Return: On the subject of success 1.
 * When an error occurs, -1 is returned and errno is set properly.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
