#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct format - associate conversion specifiers with corresponding functions
 * @specifier: type char pointer to identify which conversion specifier
 * @conversion_func: func pointer to a function that takes a va_list of args
 */
typedef struct format
{
	char *specifier;
	int (*conversion_func)(va_list);
} specifier_handler;
int _printf(const char *format, ...);
int _printf_supporter(const char *format, va_list args);

int (*find_case(const char *format))(va_list);

int print_char(va_list args);
int print_str(va_list list);
int print_percent(va_list list);
int print_int(va_list list);
int (*find_case(const char *format))(va_list);
int print_unsigned(va_list list);

unsigned int _strlen(char *s);
void rev_string(char s[]);
void _itoa_unsigne(unsigned int n, char *s);
int print_octal(va_list list);
void _itoa_octal(unsigned int n, char *s);
void _itoa_hex(unsigned int n, char *s, int is_uppercase);
int print_int_hex_upper(va_list list);
int print_int_hex(va_list list);
void _itoa(long n, char s[]);
int print_pointer(va_list list);
void number_to_binary(unsigned int n, char *s);
int print_binary(va_list list);
int print_nonprintable(va_list list);
int print_nonPrintable(va_list l);
char *convertBase(unsigned long int num, int base, int lowercase);

int _putchar(char c);
int _puts(char *str);

#endif
