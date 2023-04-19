#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - return the sum of 2 numbers
 * @a: the number 1.
 * @b: the number 2.
 *
 * Return: the sum of (a and b)
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub - return the difference between 2 numbers.
 * @a: the number 1.
 * @b: the number 2.
 *
 * Return: the difference of (a and b)
 */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - return the product of 2 numbers
 * @a: the number 1.
 * @b: the number 2.
 *
 * Return: the product of (a and b)
 */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
 * op_div - return the division of 2 numbers
 * @a: the number 1.
 * @b: the number 2.
 *
 * Return: the quotient of (a and b).
 */
int op_div(int a, int b)
{
	return (a / b);
}
/**
 * op_mod - return the remainder of the division of 2 numbers.
 * @a: the number 1.
 * @b: the number 2.
 *
 * Return: the remainder of the division (a by b).
 */
int op_mod(int a, int b)
{
	return (a % b);
}
