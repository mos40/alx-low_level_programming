#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new_node node at
 * a specified position
 *
 * @h: Ptr to the h_head of the doubly linked list
 * @idx: index of the new_node node be inserted
 * @n: Value of the new_node node
 * Return: Address of the new_node node, or NULL if insertion fails
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *h_head;
	unsigned int i;

	new_node = NULL;
	if (idx == 0)
		new_node = add_dnodeint(h, n);
	else
	{
		h_head = *h;
		i = 1;
		if (h_head != NULL)
			while (h_head->prev != NULL)
				h_head = h_head->prev;
		while (h_head != NULL)
		{
			if (i == idx)
			{
				if (h_head->next == NULL)
					new_node = add_dnodeint_end(h, n);
				else
				{
					new_node = malloc(sizeof(dlistint_t));
					if (new_node != NULL)
					{
						new_node->n = n;
						new_node->next = h_head->next;
						new_node->prev = h_head;
						h_head->next->prev = new_node;
						h_head->next = new_node;
					}
				}
				break;
			}
			h_head = h_head->next;
			i++;
		}
	}

	return (new_node);
}
