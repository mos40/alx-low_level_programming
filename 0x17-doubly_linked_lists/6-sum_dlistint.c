#include "lists.h"

/**
 * sum_dlistint - calculates the total_sum of all the data (n)
 * in a doubly linked list
 *
 * @head: Head of the list
 * Return: Total_sum of the data
 */
int sum_dlistint(dlistint_t *head)
{
	int total_sum;

	total_sum = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;

		while (head != NULL)
		{
			total_sum += head->n;
			head = head->next;
		}
	}

	return (total_sum);
}
