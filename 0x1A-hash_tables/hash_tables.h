#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct hash_node_s - Defination of the Node of a hash table
 * @key: The key, string representing the unique key in the hash table
 * The key is unique in the HashTable
 * @value: The value associated  with the key
 * @next: Pointer to the next node in the linked list
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - description of the Hash table data structure
 * @size: The size of the array
 * @array: array of size @size, wiht each element serving as point to the node
 * of a linked list. This arrangement is chosen to implement
 * Chaining as the collision resolution strategy for our HashTable.
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);

/**
 * struct shash_node_s - defination Node of a sorted hash table
 * @key: The key, string representin the unique key within the hash table
 * The key is guaranteed to be unique in the HashTable
 * @value: The value associated within to a key
 * @next: A pointer to the next node of the List
 * @sprev: A pointer to the preceding element of the sorted linked list
 * @snext: A pointer to the succeeding element of the sorted linked list
 */
typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *next;
	struct shash_node_s *sprev;
	struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table data structure
 * @size: The size of the array
 * @array: An array of size @size, where each element is a pointer to the node
 * of a linked list, chosen for Chaining as the collision handling method.
 * @shead: A pointer to the initial element of the sorted linked list
 * @stail: A pointer to the conluding element of the sorted linked list
 */
typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
} shash_table_t;

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

#endif /* HASH_TABLES_H */
