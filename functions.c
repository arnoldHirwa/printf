#include "main.h"

/**
 * rev_string - reverses string
 * @s: string
 */

void rev_string(char s[])
{
	unsigned int i = 0, len = 0;
	char temp;

	len = _strlen(s);

	for (; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}

/**
 * _itoa - Converts long int to a string
 *  @n: The long int
 *  @s: array to store the string in after conversion
 */

void _itoa(long n, char s[])
{
	long sign = n;
	unsigned int i = 0;

	if (sign < 0)
		n = -n;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	rev_string(s);
}

/**
* print_percent - prints percent sign
* @list: list of args
* Return: number of characters printed
*/

int print_percent(va_list list)
{
	(void)(list);
	_putchar('%');
	return (1);
}

/**
 * _strlen - length of string
 * @s: string
 * Return: the length the string
 */

unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (s[len])
		len++;

	return (len);
}
