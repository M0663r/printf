#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer
 * @args: va_list containing the unsigned integer to print
 * Return: Number of characters printed
 */
int print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[12];
	int i = 0, count = 0;

	do {
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	while (i--)
		count += write(1, &buffer[i], 1);

	return (count);
}
