#include "main.h"

/**
 * get_bit - the bit value at an index in a decimal number is returned.
 * @n: the number to look for
 * @index: code for the bit
 *
 * Return: value of the bit at the specified index, -1 if the code is invalid.
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
