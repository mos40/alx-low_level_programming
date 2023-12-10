#include "lists.h"

/**
 * add_dnodeint - inserts a new_node node at the starting
 * of a dlistint_t list
 *
 * @head: Head of the list
 * @n: Value of the element
 * Return: The address of the new element
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *active_head;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	active_head = *head;

	if (active_head != NULL)
	{
		while (active_head->prev != NULL)
			active_head = active_head->prev;
	}

	new_node->next = active_head;

	if (active_head != NULL)
		active_head->prev = new_node;

	*head = new_node;

	return (new_node);
}
