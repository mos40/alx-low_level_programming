#include "hash_tables.h"

/**
 * hash_table_delete - Frees the memory occupied by a hash table.
 * @ht: A pointer to the hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *has_head = ht;
	hash_node_t *h_node, *tmp;
	unsigned long int h;

	for (h = 0; h < ht->size; h++)
	{
		if (ht->array[h] != NULL)
		{
			h_node = ht->array[h];
			while (h_node != NULL)
			{
				tmp = h_node->next;
				free(h_node->key);
				free(h_node->value);
				free(h_node);
				h_node = tmp;
			}
		}
	}
	free(has_head->array);
	free(has_head);
}
