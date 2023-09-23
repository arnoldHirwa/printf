#include "main.h"

/**
 * find_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed
 * @list: list of arguments
 *
 * Return: width.
 */
int find_width(const char *format, int *i, va_list list)
{
	int current;
	int width = 0;

	for (current = *i + 1; format[current] != '\0'; current++)
	{
		if (find_digit(format[current]))
		{
			width *= 10;
			width += format[current] - '0';
		}
		else if (format[current] == '*')
		{
			current++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = current - 1;

	return (width);
}
