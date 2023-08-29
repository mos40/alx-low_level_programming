#include "lists.h"

/**
 * listint_len - brings back the size of a linked list's items
 * @h: traverse a linked list of the type listint_t
 *
 * Return: amount of nodes
 */

size_t listint_len(const listint_t *h)
{
size_t num = 0;

	while (h)
{
	num++;
	h = h->next;
}
	return (num);
}
