#include "lists.h"

/**
 * add_dnodeint_end - Appends a new_node node at the end
 * of a dlistint_t list
 *
 * @head: Pointer to the head of the list
 * @n: Value of the new element
 * Return: the address of the new_node element
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *active_head;
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	active_head = *head;

	if (active_head != NULL)
	{
		while (active_head->next != NULL)
			active_head = active_head->next;
		active_head->next = new_node;
	}
	else
	{
		*head = new_node;
	}

	new_node->prev = active_head;

	return (new_node);
}
