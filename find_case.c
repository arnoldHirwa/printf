#include "main.h"

/**
* find_case - func to return a pointer to the appropriate print func
* @format: format of the argument to be printed
* Return: pointer to the appropriate print func, OR NULL if no match is found
*/
int (*find_case(const char *format))(va_list)
{
	int i = 0;

	specifier_handler format_types[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_int_hex},
		{"X", print_int_hex_upper},
		{"p", print_pointer},
		{"b", print_binary},
		{NULL, NULL}};

	for (; format_types[i].specifier; i++)
	{
		if (*format == *(format_types[i].specifier))
		{
			return (format_types[i].conversion_func);
		}
	}
	return (NULL);
}
