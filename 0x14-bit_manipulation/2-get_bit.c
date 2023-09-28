#include "main.h"

/**
 * get_bit - returns value of a specific bit at an index in a decimal number
 * @n: look for a number
 * @index: index of the bit to retrieve.
 *
 * Return: value (0 or 1) of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_value;
/* out of range index must be checked */

	if (index > 63)
	return (-1);

	bit_value = (n >> index) & 1;

	return (bit_value);
}
