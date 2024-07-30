#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Character string containing the format directives
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	printed_chars = handle_format(format, args);
	va_end(args);

	return (printed_chars);
}
