#include "main.h"

/**
 * get_endianness - confirms if a machine is using little or big endian
 * Return: 0 for big endian, 1 for little endian
 */
int get_endianness(void)
{
	unsigned int val = 1;
	char *byte = (char *) &val;

	return (*byte);
}
