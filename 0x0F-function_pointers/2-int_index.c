#include "function_pointers.h"
/**
 * int_index - return index place if the comparison is true else -1
 * @array: array
 * @size: size of elems in array
 * @cmp: pointer to function of 1 in the 3 in the main
 * Return: 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
