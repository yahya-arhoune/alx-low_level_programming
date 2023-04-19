#include "3-calc.h"
#include <stdlib.h>
/**
 * get_op_func - select to perform the correct function
 * the operation asked by the user.
 * @s: the operator passed as an argument
 *
 * Return: the pointer to the function corresponding to the operator given as parameter
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL},
	};

	int i = 0;

	while (ops[i].op != NULL && *(ops[i].op) != *s)
		i++;

	return (ops[i].f);
}
