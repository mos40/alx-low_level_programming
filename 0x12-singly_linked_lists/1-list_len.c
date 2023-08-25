#include <stdlib.h>
#include "lists.h"

/**
 * list_len - brings back the size of a linked list's elements.
 * @h: address of the list_t list
 *
 * Return: elements in h, number
 */
size_t list_len(const list_t *h)
{
size_t n = 0;

while (h)
{
n++;
h = h->next;
}
return (n);
}
