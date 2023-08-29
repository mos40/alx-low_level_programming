#include "lists.h"

/**
 * free_listint - sets a linked list free
 * @head: to free the listint_t list
 */

void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
{
	temp = head->next;
	free(head);
	head = temp;
}
}
