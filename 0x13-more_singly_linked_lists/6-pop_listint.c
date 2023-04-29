#include "lists.h"

/**
 * pop_listint - function that deletes the head node
 * of a listint_t linked list,
 * and returns the head node’s data (n).
 * @head: pointer to the first element int the linked list.
 *
 * Return: if the liked list is empty 0.
 */

int pop_listint(listint_t **head)
{
	int n;
	listint_t *current;

	if (*head == NULL)
	{
		return (0);
	}

	n = (*head)->n;
	current = *head;
	*head = (*head)->next;
	free(current);

	return (n);
}
