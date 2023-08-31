#include "main.h"

/**
 * print_binary - The binary equivalent of a decimal number is printed.
 * @n: binary-printable number
 */
void print_binary(unsigned long int n)
{
	int g, count = 0;
	unsigned long int current;

	for (g = 63; g >= 0; g--)
	{
		current = n >> g;

		if (current & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (count)
		_putchar('0');
}
