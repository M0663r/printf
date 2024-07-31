#include "main.h"

/**
 * print_hex - Converts an unsigned int to hexadecimal
 * @args: va_list containing the unsigned int to convert
 * @uppercase: Flag indicating if the hexadecimal should be uppercase
 * Return: Number of characters printed
 */
int print_hex(va_list args, int uppercase)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[9];
	char *hex_digits;
	int i = 0, count = 0;

	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";

	if (num == 0)
		return (write(1, "0", 1));

	while (num > 0)
	{
		buffer[i++] = hex_digits[num % 16];
		num /= 16;
	}

	while (i--)
		count += write(1, &buffer[i], 1);

	return (count);
}

int print_x(va_list args)
{
	return (print_hex(args, 0));
}

int print_X(va_list args)
{
	return (print_hex(args, 1));
}
