#include "lists.h"

/**
 * free_listint2 - frees a connected list.
 * @head: listint_t list pointer that needs to be released
 */

void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
	return;

	while (*head)
{
	temp = (*head)->next;
	free(*head);
	*head = temp;
}

	*head = NULL;
}
