#include "lists.h"

/**
 * get_dnodeint_at_index - retrieves the nth node of a dlistint_t linked list.
 * @head: ptr to head of the list
 * @index: index of the node to retrieve for, starting from 0
 * Return: Ptr to the nth node or null if not found
 **/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int node_count;
	dlistint_t *current_node;

	node_count = 0;
	if (head == NULL)
	return (NULL);

	current_node = head;
	while (current_node)
	{
	if (index == node_count)
	return (current_node);
	node_count++;
	current_node = current_node->next;
	}
	return (NULL);
}
