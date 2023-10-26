#include "main.h"

/**
 * clear_bit - change the value of a given bit to 0 in number
 * @n: pointer to the number whose bit to be change
 * @index: index of the bit to cleared
 *
 * Return: 1 for success, -1 for the failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
/* the index is within valid bounds (0-63) to be checked */

	if (index > 63)
	return (-1);

/* indicate success to return 1 */

	*n = (~(1UL << index) & *n);
	return (1);
}
