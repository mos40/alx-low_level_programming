#include "hash_tables.h"
/**
 * hash_table_print - Displays the contents of a hash table.
 * @ht: A pointer to the hash table to be printed.
 * Description: Key/value pairs are printed in the order
 * they appear in the array of the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *h_node;
	unsigned long int t;
	unsigned char print_comma = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (t = 0; t < ht->size; t++)
	{
		if (ht->array[t] != NULL)
		{
			if (print_comma == 1)
				printf(", ");

			h_node = ht->array[t];
			while (h_node != NULL)
			{
			printf("'%s': '%s'", h_node->key, h_node->value);
				h_node = h_node->next;
				if (h_node != NULL)
					printf(", ");
			}
			print_comma = 1;
		}
	}
	printf("}\n");
}
