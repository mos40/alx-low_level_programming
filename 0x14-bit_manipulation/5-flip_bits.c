#include "main.h"

/**
 * flip_bits - the amount of bits to be changed
 * to transition from one number to another
 * @n: the first number
 * @m: the second number
 *
 * Return: the amount of bits to be changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int q, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (q = 63; q >= 0; q--)
	{
		current = exclusive >> q;
		if (current & 1)
			count++;
	}

	return (count);
}
