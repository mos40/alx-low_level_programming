#include "lists.h"

/**
 * print_listint - prints every component of a linked list
 * @h: to print a linked list of listint_t type
 *
 * Return: nodes present
 */

size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
	printf("%d\n", h->n);
	num++;
	h = h->next;
	}
	return (num);
}
