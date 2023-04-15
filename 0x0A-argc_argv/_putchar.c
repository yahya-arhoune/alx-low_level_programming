#include <stdio.h>
#include "main.h"

/**
 * _putchar - write the character c to stdout
 * @c:Ther character to print
 *
 * return: On success 1.
 * on error, -1 is returned and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
