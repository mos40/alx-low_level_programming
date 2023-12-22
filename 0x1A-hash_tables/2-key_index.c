#include "hash_tables.h"

/**
 * key_index - computes the index for storing a key/value pair
 * in the array of a a hash table
 * @key: The key to which to calcuate the index of.
 * @size: The size of the of the hash table. array
 * Return: The computed index of the key.
 * Description: Utilises the djb2 algorithm.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
