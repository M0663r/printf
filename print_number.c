#include "main.h"

/**
 * print_number - Prints an integer
 * @args: va_list containing the integer to print
 * Return: Number of characters printed
 */
int print_number(va_list args)
{
	int num = va_arg(args, int);
	char buffer[12];
	int i = 0, neg = 0, count = 0;

	if (num < 0)
	{
		neg = 1;
		num = -num;
	}

	do {
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	if (neg)
		buffer[i++] = '-';

	while (i--)
		count += write(1, &buffer[i], 1);

	return (count);
}
