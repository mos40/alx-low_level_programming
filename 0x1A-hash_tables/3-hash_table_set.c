#include "hash_tables.h"

/**
 * hash_table_set - Inserts or updates an element in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to insert, which cannot be an empty string.
 * @value: The value associated with the key.
 * Return: On failure - 0.
 *         On success - 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node;
	char *new_value;
	unsigned long int hash_index, h;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	new_value = strdup(value);
	if (new_value == NULL)
		return (0);

	hash_index = key_hash_index((const unsigned char *)key, ht->size);
	for (h = hash_index; ht->array[h]; h++)
	{
		if (strcmp(ht->array[h]->key, key) == 0)
		{
			free(ht->array[h]->value);
			ht->array[h]->value = new_value;
			return (1);
		}
	}

	*new_node = malloc(sizeof(hash_node_t));
	if (*new_node == NULL)
	{
		free(new_value);
		return (0);
	}
	*new_node->key = strdup(key);
	if (*new_node->key == NULL)
	{
		free(*new_node);
		return (0);
	}
	*new_node->value = new_value;
	*new_node->next = ht->array[hash_index];
	ht->array[hash_index] = *new_node;

	return (1);
}
