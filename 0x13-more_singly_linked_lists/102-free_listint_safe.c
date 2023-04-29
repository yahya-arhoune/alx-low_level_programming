#include "lists.h"

/**
 * free_listint_safe - function that frees a listint_t list.
 * @h: A pointer to the fist node of the list.
 *
 * Return: the size of the list that was free’d.
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *perv;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	while (current != NULL)
	{
		count++;
		perv = current;
		current = current->next;

		if (perv <= current)
		{
			*h = NULL;
			return (count);
		}

		free(perv);
	}

	*h = NULL;
	return (count);
}
