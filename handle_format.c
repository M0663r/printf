#include "main.h"

/**
 * handle_format - Parses and handles the format string
 * @format: Format string containing the directives
 * @args: List of arguments to print
 *
 * Return: Number of characters printed
 */
int handle_format(const char *format, va_list args)
{
	int i, printed_chars = 0;

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == 'c')
				printed_chars += print_char(va_arg(args, int));
			else if (format[i] == 's')
				printed_chars += print_string(va_arg(args, char *));
			else if (format[i] == 'd' || format[i] == 'i')
				printed_chars += print_number(va_arg(args, int));
			else if (format[i] == 'u')
				printed_chars += print_unsigned(va_arg(args, unsigned int));
			else if (format[i] == 'o')
				printed_chars += print_octal(va_arg(args, unsigned int));
			else if (format[i] == 'x')
				printed_chars += print_hex(va_arg(args, unsigned int), 0);
			else if (format[i] == 'X')
				printed_chars += print_hex(va_arg(args, unsigned int), 1);
			else if (format[i] == 'b')
				printed_chars += print_binary(va_arg(args, unsigned int));
			else if (format[i] == '%')
				printed_chars += write(1, &format[i], 1);
		}
		else
		{
			printed_chars += write(1, &format[i], 1);
		}
	}

	return (printed_chars);
}
