#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer
 * @num: Unsigned integer to print
 *
 * Return: Number of characters printed
 */
int print_unsigned(unsigned int num)
{
	int count = 0;

	if (num / 10)
		count += print_unsigned(num / 10);

	count += write(1, &"0123456789"[num % 10], 1);

	return (count);
}
