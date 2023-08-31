#include "main.h"

/**
 * clear_bit - sets a particular bit's value to 0.
 * @n: pointer to the desired number
 * @index: index of the to-clear bit
 *
 * Return: One for success and one for failure.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
