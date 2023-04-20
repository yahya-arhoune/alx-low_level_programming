#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

void print_all(const char * const format, ...)
{
	int i = 0;
	char *str, *sp = "";
	va_list lst;

	va_start(lst, format);

	if (format)
	{
		while (format[i])
		{
			switch (format[i])
			{
				case 'c':
					printf("%s%c", sp, va_arg(lst, int));
					break;
				case 'i':
					printf("%s%d", sp, va_arg(lst, int));
					break;
				case 'f':
					printf("%s%f", sp, va_arg(lst, double));
					break;
				case 's':
					str = va_arg(lst, char *);
					if (!str)
						str = "(nil)";
					printf("%s%s", sp, str);
					break;
				default:
					i++;
					continue;
			}
		sp = ",";
		i++;
		}
	}
	printf("\n");
	va_end(lst);
}
