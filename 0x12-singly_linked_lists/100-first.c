#include <stdio.h>
#include <stdlib.h>

void first(void) _attribute_ ((constructor));
/**
 * first -- function that prints You're beat! and yet, you must allow,
 * \nI bore my house upon my back!\n
 * before the main function is executed.
 *
 * executed function
 */

void first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
