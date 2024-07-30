#include "main.h"

/**
 * print_int - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_int(int n)
{
	char buffer[12];
	int len = 0;
	int temp = n;
	int i;

	if (n == 0)
	{
		return (write(1, "0", 1));
	}

	if (n < 0)
	{
		len += write(1, "-", 1);
		temp = -temp;
	}

	for (i = 10; temp && i; --i, temp /= 10)
	{
		buffer[i] = "0123456789"[temp % 10];
	}

	return (len + write(1, &buffer[i + 1], 11 - i));
}
