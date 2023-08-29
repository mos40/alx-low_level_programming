#include "lists.h"

/**
 * get_nodeint_at_index - returns the linked list node at a specific index
 * @head: The linked list's primary node
 * @index: node index to return
 *
 * Return: pointer to the desired node, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp = head;

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}

	return (temp ? temp : NULL);
}
