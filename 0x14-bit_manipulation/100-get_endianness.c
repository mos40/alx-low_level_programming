#include "main.h"

/**
 * get_endianness - determines if a computer is small or large endian
 * Return: 1 for small, 0 for large
 */
int get_endianness(void)
{
	unsigned int Bb = 1;
	char *byteMos = (char *) &Bb;

	return (*byteMos);
}
