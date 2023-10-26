#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: Converted number and the resulting unsigned integer
 */
unsigned int binary_to_uint(const char *b)
{
	int indicator;
	unsigned int dec_val = 0;

	if (!b)
		return (0);

	for (indicator = 0; b[indicator]; indicator++)
	{
		if (b[indicator] < '0' || b[indicator] > '1')
		return (0);

/* Count the decimal value by doubling current value + adding the new bit*/

		dec_val = 2 * dec_val + (b[indicator] - '0');

	}
/* converted final decimal value in return*/

	return (dec_val);
}

