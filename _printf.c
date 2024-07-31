#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Format string containing the desired format specifiers
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count;

    if (format == NULL)
        return (-1);

    va_start(args, format);
    count = handle_format(format, args);
    va_end(args);

    return (count);
}
