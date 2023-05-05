#include "main.h"
#include <stdio.h>

/**
 * flip_bits - returns the number of bits you would need to
 * flip to get from one number to another.
 * @n: first number
 * @m: second number
 *
 * Return: number of thr bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;
	unsigned long int diff = n ^ m;

	while (diff > 0)
	{
		if (diff & 1)
		{
			count++;
		}
		diff >>= 1;
	}
	return (count);
}
