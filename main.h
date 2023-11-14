#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct type - a structure that equate different specifiers
 * @f_s: the string to determine the specifier
 * @func: the function pointer to a function that accepts a va arguemnt
 */

typedef struct type
{
	char *f_s;
	char* (*func)(va_list);
} type_format;
char *print_char(va_list ptr);
char *print_string(va_list ptr);
char *print_integer(va_list ptr);
int string_length(char *tmp);
char *print_unsigned_integer(va_list ptr);
char *print_binary(va_list ptr);
char *reverse_string(va_list ptr);
int _printf(const char *format, ...);
#endif
