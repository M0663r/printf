#include "main.h"

/**
 * print_octal - Converts an unsigned int to octal
 * @args: va_list containing the unsigned int to convert
 * Return: Number of characters printed
 */
int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[12];
	int i = 0, count = 0;

	if (num == 0)
		return (write(1, "0", 1));

	while (num > 0)
	{
		buffer[i++] = (num % 8) + '0';
		num /= 8;
	}

	while (i--)
		count += write(1, &buffer[i], 1);

	return (count);
}
