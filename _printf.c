#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 *
 * Return: number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					printed_chars += _putchar(va_arg(args, int));
				break;
				case 's':
					printed_chars += print_string(va_arg(args, char *));
				break;
				case '%':
					printed_chars += write(1, "%", 1);
				break;
				default:
					printed_chars += write(1, &format[i], 1);
				break;
			}
		}
		else
		{
			printed_chars += write(1, &format[i], 1);
		}
	}

	va_end(args);
	return (printed_chars);
}
