#include "lists.h"

/**
 * free_dlistint - Releases the memory occupied dlistint_t list.
 * @head: Ptr to head of the list
 * Return: nothing
 */
void free_dlistint(dlistint_t *head)
{
	if (head == NULL)
	return;

	while (head->next)
	{
	head = head->next;
	free(head->prev);
	}
	free(head);
}
