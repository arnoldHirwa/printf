#include "main.h"
/**
 * find_case - Prints an argument based on its type
 * @format: Formatted string in which to print the arguments
 * @list: List of arguments to be printed
 * @ind: ind.
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int find_case(const char *format, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	specifier_handler format_types[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_perc},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigne}, {'o', print_octal}, {'x', print_hex},
		{'X', print_hex_upper}, {'p', print_pointer}, {'S', print_nonPrintable},
		{'r', reverse}, {'R', print_rot13}, {'\0', NULL}
	};
	for (i = 0; format_types[i].format != '\0'; i++)
		if (format[*ind] == format_types[i].format)
			return (format_types[i].fn(list, buffer, flags, width, precision, size));

	if (format_types[i].format == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (format[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (format[*ind] != ' ' && format[*ind] != '%')
				--(*ind);
			if (format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &format[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
