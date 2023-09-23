#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int j, current;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {V_MINUS, V_PLUS, V_ZERO, V_HASH, V_SPACE, 0};

	for (current = *i + 1; format[current] != '\0'; current++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[current] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = current - 1;

	return (flags);
}
