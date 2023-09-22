#include "main.h"

/**
* print_pointer - prints a pointer address from va_list
* @list: list of args
* Return: number of characters printed
*/
int print_pointer(va_list list)
{
	void *ptr = va_arg(list, void *);
	char buffer[50];

	if (!ptr)
		return (_puts("(nil)"));

	sprintf(buffer, "0x%lx", (unsigned long)ptr);
	return (_puts(buffer));
}

/**
* print_binary - prints unsigned int into binary format
* @list: list of args
* Return: number of characters printed
*/

int print_binary(va_list list)
{
	int n = va_arg(list, unsigned int);
	char buffer[50];

	number_to_binary(n, buffer);
	return (_puts(buffer));
}

/**
* number_to_binary - converts an unsigned int into binary format
* @n: number to be converted
* @s: string to be filled with converted number
* Return: nothing
*/

void number_to_binary(unsigned int n, char *s)
{
	unsigned int i = 0, m = 0;

	if (n == 1 || n == 0)
	{
		s[m++] = n + '0';
		s[m] = '\0';
		return;
	}

	while (n != 1)
	{
		i = n % 2;
		s[m++] = i + '0';
		n /= 2;
	}
	s[m] = 1 + '0';
	s[m + 1] = '\0';
	rev_string(s);
}

/**
* print_nonprintable - prints non printable characters from va_list
* @list: list of args
* Return: number of characters printed
*/
int print_nonprintable(va_list list)
{
	unsigned int i = 0, count = 0;
	unsigned int m;
	char buffer[50];

	char *str;

	str = va_arg(list, char *);
	if (!str)
		str = "(null)";

	for (; str[i]; i++)
	{
		m = str[i];
		if ((m < 32 && m != '\n') || m >= 127)
		{
			_puts("\\x");
			count += 2;
			_itoa_hex(m, buffer, 1);
			count += _puts(buffer);
		}
		else if (m == '\n') /* Handle newline character separately */
		{
			_puts("\\x0A");
			count += 3;
		}
		else
		{
			_putchar(str[i]);
			count += 1;
		}
	}

	return (count);
}
