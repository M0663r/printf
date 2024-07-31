#include "main.h"

/**
 * handle_format - Selects the correct function to perform the operation
 * @format: Format string containing the desired format specifiers
 * @args: va_list containing the arguments to format
 * Return: Number of characters printed
 */
int handle_format(const char *format, va_list args)
{
	int i, j, count = 0;
	fmt_t fmt[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_number},
		{'i', print_number},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_x},
		{'X', print_X},
		{'\0', NULL}
	};

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			return (-1);
			if (format[i] == '%')
			{
				count += write(1, "%", 1);
				continue;
			}
			for (j = 0; fmt[j].spec != '\0'; j++)
			{
				if (format[i] == fmt[j].spec)
				{
					count += fmt[j].f(args);
					break;
				}
			}
			if (fmt[j].spec == '\0')
				count += write(1, &format[i], 1);
		}
		else
		    count += write(1, &format[i], 1);
	}

	return (count);
}
