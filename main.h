#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int handle_format(const char *format, va_list args);
int print_char(va_list args);
int print_string(va_list args);
int print_number(va_list args);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args, int uppercase);
int print_x(va_list args);
int print_X(va_list args);

typedef struct fmt
{
	char spec;
	int (*f)(va_list);
} fmt_t;

#endif /* MAIN_H */
