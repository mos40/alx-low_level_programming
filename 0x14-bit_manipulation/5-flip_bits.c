#include "main.h"

/**
 * flip_bits - counts the number of bits to be flipped
 * to trnasform from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x, count = 0;
	unsigned long int current;
	unsigned long int exclusive_or_result = n ^ m;

	for (x = 63; x >= 0; x--)
	{
		current = exclusive_or_result >> x;
	if (current & 1)
		count++;
	}

	return (count);
}
