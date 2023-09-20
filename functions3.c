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
