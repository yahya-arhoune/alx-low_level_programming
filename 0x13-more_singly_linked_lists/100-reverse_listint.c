#include "lists.h"

/**
 * reverse_listint - function that reverses a listint_t linked list.
 * @head: pointer to the head of the list;
 *
 * Returns: a pointer to the first node of the reversed list.
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *perv = NULL, *current = *head, *next;

	while (current != NULL)
	{
		next = current->next;
		current->next = perv;
		perv = current;
		current = next;
	}

	*head = perv;

	return (*head);
}
