#include "main.h"
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MUST_FLUSH 1
/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	static char buf[BUFFER_SIZE];
	ssize_t bytes_written;
	static int n;

	if (n >= BUFFER_SIZE || (MUST_FLUSH == 1))
	{
		if (n > 0)
		{
			bytes_written = write(1, buf, n);
			if (bytes_written == -1)
			{
				/* Handle write error here and set errno if necessary */
				return (-1);
			}
		} else
		{
			return (write(1, &c, 1));
		}
		n = 0;
	}
	buf[n] = c;
	n++;
	return (1);
}

/**
* _puts - prints string
* @str: string
* Return: number of characters printed
*/
int _puts(char *str)
{
	int i = 0;

	#undef MUST_FLUSH
	#define MUST_FLUSH 0
	for (; str[i]; i++)
	{
		_putchar(str[i]);
	}

	#undef MUST_FLUSH
	#define MUST_FLUSH 1

	_putchar('\0');
	return (i);
}
