#include "main.h"

/**
 * print_octal - Prints an unsigned int in octal
 * @num: Unsigned int to print
 *
 * Return: Number of characters printed
 */
int print_octal(unsigned int num)
{
	int count = 0;

	if (num / 8)
		count += print_octal(num / 8);

	count += write(1, &"01234567"[num % 8], 1);

	return (count);
}
