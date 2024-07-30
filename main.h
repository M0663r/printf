#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *str);
int print_number(int num);
int handle_format(const char *format, va_list args);

#endif /* MAIN_H */
