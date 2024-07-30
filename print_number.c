#include "main.h"

/**
 * print_number - Prints an integer
 * @num: Integer to print
 *
 * Return: Number of characters printed
 */
int print_number(int num)
{
	int count = 0;
	unsigned int n = (num < 0) ? -num : num;

	if (num < 0)
	{
		count += write(1, "-", 1);
	}

	if (n / 10)
	{
		count += print_number(n / 10);
	}

	count += write(1, &"0123456789"[n % 10], 1);

	return (count);
}
