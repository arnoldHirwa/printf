#include "main.h"

/**
* _itoa_unsigne - Converts an unsigned integer to a string
* @n: The unsigned integer
* @s: Pointer to the destination character array
*/
void _itoa_unsigne(unsigned int n, char *s)
{
	unsigned int i = 0;

	if (n == 0)

	{
		s[i++] = '0';
		s[i] = '\0';
		return;
	}
	while (n > 0)
	{
		int digit = n % 10;

		s[i++] = digit + '0';
		n /= 10;
	}
	s[i] = '\0';
	rev_string(s);
}

/**
* print_int - prints integers from va_list
* @list: list of integers to be printed
* Return: number of characters printed
*/
int print_int(va_list list)
{
	int num = va_arg(list, long);

	char buffer[50];

	_itoa(num, buffer);
	return (_puts(buffer));
}

/**
* print_char - prints a character from va_list
* @list: list of args
* Return: number of characters printed
*/

int print_char(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}

/**
* print_str - prints a string from va_list
* @list: containins string to be printed
* Return: number of characters printed
*/

int print_str(va_list list)
{
	int i = 0;

	char *str;

	str = va_arg(list, char *);
	if (!str)
		str = "(null)";

	for (; str[i]; i++)
		_putchar(str[i]);

	return (i);
}

/**
* print_unsigned - prints unsigned integers from va_list
* @list: list of unsigned integers to be printed
* Return: number of characters printed
*/
int print_unsigned(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);

	char buffer[50];

	_itoa_unsigne(num, buffer);
	return (_puts(buffer));
}
