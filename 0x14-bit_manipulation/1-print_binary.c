#include "main.h"

/**
 * print_binary - prints the binary representation of a decimal number
 * @n: The number to be converted & printted in binary
 */
void print_binary(unsigned long int n)
{
	int index, count = 0;
	unsigned long int current;

		for (index = 63; index >= 0; index--)
	{
		current = n >> index;

		if (current & 1)
		{
		_putchar('1');
		count++;
		}
/* print, If leading zeros have been encountered. */

		else if (count)
		_putchar('0');
	}
/* Print a single '0', If the number was zero, */
		if (!count)
		_putchar('0');
}
