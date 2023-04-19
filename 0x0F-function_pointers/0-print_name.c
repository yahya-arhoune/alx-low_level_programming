#include "function_pointers.h"
#include <stdio.h>
/**
 * print_name - print name using the pointer to function
 * @name: a string to be added
 * @f: the pointer to function
 * Return: nothing
 **/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
