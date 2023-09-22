#include "main.h"

/**
* print_nonPrintable - Non printable characters
* (0 < ASCII value < 32 or >= 127) are
* printed this way: \x, followed by the ASCII code
* value in hexadecimal (upper case - always 2 characters)
* @l: va_list arguments from _printf
* if a flag is passed to _printf
* Return: number of char printed
*/
int print_nonPrintable(va_list l)
{
	int i, count = 0;
	char *res;
	char *s = va_arg(l, char *);

	if (!s)
		return (_puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_puts("\\x");
			count += 2;
			res = convertBase(s[i], 16, 0);
			if (!res[1])
				count += _putchar('0');
			count += _puts(res);
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
}


/**
* convertBase - converts number and base into string
* @num: input number
* @base: input base
* @lowercase: flag if hexa values need to be lowercase
* Return: result string
*/
char *convertBase(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
