#include "main.h"

/**
 * print_string - Prints a string
 * @args: va_list containing the string to print
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (str == NULL)
		str = "(null)";

	while (str[len])
		len++;

	return (write(1, str, len));
}
