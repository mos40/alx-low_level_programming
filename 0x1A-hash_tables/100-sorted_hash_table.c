#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The new_node size ofthe sorted hash table.
 * Return: If an error occurs - NULL.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *h_t;
	unsigned long int i;

	h_t = malloc(sizeof(shash_table_t));
	if (h_t == NULL)
		return (NULL);

	h_t->size = size;
	h_t->array = malloc(sizeof(shash_node_t *) * size);
	if (h_t->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		h_t->array[i] = NULL;
	h_t->shead = NULL;
	h_t->stail = NULL;

	return (h_t);
}

/**
 * shash_table_set - Add more an element to sorted hash table.
 * @ht: the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 * Return: Upon failure - 0. zero
 *         Otherwise - 1. one
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *tmp_node;
	char *value_cp;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_cp = strdup(value);
	if (value_cp == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp_node = ht->shead;
	while (tmp_node)
	{
		if (strcmp(tmp_node->key, key) == 0)
		{
			free(tmp_node->value);
			tmp_node->value = value_cp;
			return (1);
		}
		tmp_node = tmp_node->snext;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
	{
		free(value_cp);
		return (0);
	}
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(value_cp);
		free(new_node);
		return (0);
	}
	new_node->value = value_cp;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	if (ht->shead == NULL)
	{
		new_node->sprev = NULL;
		new_node->snext = NULL;
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new_node->sprev = NULL;
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		tmp_node = ht->shead;
		while (tmp_node->snext != NULL && strcmp(tmp_node->snext->key, key) < 0)
			tmp_node = tmp_node->snext;
		new_node->sprev = tmp_node;
		new_node->snext = tmp_node->snext;
		if (tmp_node->snext == NULL)
			ht->stail = new_node;
		else
			tmp_node->snext->sprev = new_node;
		tmp_node->snext = new_node;
	}

	return (1);
}

/**
 * shash_table_get - Retrieve the value associated
 * @ht: the sorted hash table.
 * @key: The key to get the val
 * Return: If the key cannot be matched - NULL.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;

	return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - show a sorted hash table in order.
 * @ht: the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - shows a sorted hash table in reverse order.
 * @ht: the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - take a sorted hash table.
 * @ht: the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *tmp_node;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node)
	{
		tmp_node = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp_node;
	}

	free(head->array);
	free(head);
}
