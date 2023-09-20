#include "main.h"

/**
* print_int_hex - prints integers as lowercase hexadecimal from va_list
* @list: list of integers to be printed
* Return: number of characters printed
*/
int print_int_hex(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	char buffer[50];

	_itoa_hex(num, buffer, 0);
	return (_puts(buffer));
}

/**
* print_int_hex_upper - prints integers as uppercase hexadecimal from va_list
* @list: list of integers to be printed
* Return: number of characters printed
*/
int print_int_hex_upper(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	char buffer[50];

	_itoa_hex(num, buffer, 1);
	return (_puts(buffer));
}

/**
* _itoa_hex - Converts an unsigned integer to a hexadecimal string
* @n: The unsigned integer
* @s: Pointer to the destination character array
* @is_uppercase: Flag to indicate uppercase (1) or lowercase (0) hex
*/

void _itoa_hex(unsigned int n, char *s, int is_uppercase)
{
	int i = 0;

	if (n == 0)
	{
		s[i++] = '0';
		s[i] = '\0';
		return;
	}

	while (n > 0)
	{
		int digit = n % 16;

		s[i++] = (digit < 10) ?
		digit + '0' :
		(is_uppercase ? digit - 10 + 'A' : digit - 10 + 'a');

		n /= 16;
	}

	s[i] = '\0';
	rev_string(s);
}

/**
* print_octal - prints unsigned octal integers from va_list
* @list: list of unsigned octal integers to be printed
* Return: number of characters printed
*/
int print_octal(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	char buffer[50];

	_itoa_octal(num, buffer);
	return (_puts(buffer));
}

/**
* _itoa_octal - Converts an unsigned integer to an octal string
* @n: The unsigned integer
* @s: Pointer to the destination character array
*/
void _itoa_octal(unsigned int n, char *s)
{
	int i = 0;

	if (n == 0)
	{
		s[i++] = '0';
		s[i] = '\0';
		return;
	}

	while (n > 0)
	{
		int digit = n % 8;

		s[i++] = digit + '0';
		n /= 8;
	}

	s[i] = '\0';
	rev_string(s);
}
