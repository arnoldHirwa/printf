#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints string
 * @str: string
 * Return: number of characters printed
 */
int _puts(char *str)
{
	int i = 0;

	for (; str[i]; i++)
		_putchar(str[i]);

	return (i);
}
