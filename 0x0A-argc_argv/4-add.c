#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/**
 * check_num - check - string there are digit.
 * @str: array str.
 *
 * Return: Always 0 (Success).
 */
int check_num(char *str)
{
	/*declaration of variables*/
	unsigned int count;

	count = 0;
	while (count < strlen(str))
	{
		if (!isdigit(str[count]))
		{
			return (0);
		}

		count++;
	}
	return (1);
}

/**
 * main - print program name.
 * @argc: count arguments.
 * @argv: arguments.
 *
 * return: always zero (success)
 */

int main(int argc, char *argv[])

{

	/*Declaration of variables*/
	int count;
	int str_to_int;
	int sum = 0;

	count = 1;
	while (count < argc)
	{
		if (check_num(argv[count]))

		{
			str_to_int = atoi(argv[count]);
			sum += str_to_int;
		}

		/*condition if one of the numbers contain symbols that aren't digits*/
		else
		{
			printf("Error\n");
			return (1);
		}

		count++;
	}

	printf("%d\n", sum); /*print sum*/

	return (0);
}