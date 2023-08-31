#include "main.h"

/**
 * set_bit - a bit at a specific index is set to 1
 * @n: pointer to the number to be changed
 * @index: the bit index to set to 1
 *
 * Return: -1 for failure, 1 for accomplishment
 */


int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
