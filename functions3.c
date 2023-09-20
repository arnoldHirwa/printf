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
