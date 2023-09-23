#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024


#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 * struct format - Struct op
 *
 * @format: The format
 * @fn: The function associated
 */
struct format
{
	char format;
	int (*fn)(va_list, char[], int, int, int, int);
};

#define V_MINUS 1
#define V_PLUS 2
#define V_ZERO 4
#define V_HASH 8
#define V_SPACE 16


/**
 * typedef struct format specifier_handler - Struct op
 *
 * @format: The format
 * @fm_t: The function associated
 */
typedef struct format specifier_handler;

int _printf(const char *format, ...);
int find_case(const char *format, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);


int handle_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int handle_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int handle_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int handle_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int handle_unSign(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);
int print_it(char);
int hexa_code(char, char[], int);
int find_digit(char);
long int convert_num(long int num, int size);
long int convert_int(unsigned long int num, int size);

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_str(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_perc(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigne(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hex(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hex_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

int print_nonPrintable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int get_flags(const char *format, int *i);
int find_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int find_size(const char *format, int *i);

int reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int size);

#endif /* MAIN.H */
