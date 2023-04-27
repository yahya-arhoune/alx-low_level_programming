#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_node -- function that adds a new node at the beginning of a list_t list.
 * @head: double pointer
 * @str: new string
 * Return: the address
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int len = 0;

	while (str[len])
		len++;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	new->len = len;
	new->next = (*head);
	(*head) = new;

	return (*head);
}
