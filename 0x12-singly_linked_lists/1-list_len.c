#include <stdio.h>
#include "lists.h"

/**
 * list_len --  function that returns the number
 * of elements in a linked list_t list
 * @h: pointer
 * Return: number of elements int the pointer h
 */

size_t list_len(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}

	return (n);
}