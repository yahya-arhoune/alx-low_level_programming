#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - retuen sum of all its parameters
 * @n: number of parameters passe to the function
 * @...: a variable number of the parameters to calculate the sum
 *
 * Return: n == 0 - 0
 * otherwisz - sum of all the parameters
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ya;
	unsigned int i, sum = 0;

	va_start(ya, n);

	for (i = 0; i < n; i++)
		sum += va_arg(ya, int);

	va_end(ya);

	return (sum);
}
