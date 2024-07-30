#include "main.h"

/**
 * print_binary - Prints an unsigned int in binary
 * @num: Unsigned int to print
 *
 * Return: Number of characters printed
 */
int print_binary(unsigned int num)
{
	int count = 0;
	char buffer[32];
	int i;

	if (num == 0)
		return (write(1, "0", 1));

	for (i = 31; i >= 0; i--)
	{
		buffer[i] = (num & 1) ? '1' : '0';
		num >>= 1;
	}

	for (i = 0; i < 32; i++)
	{
		if (buffer[i] == '1')
			break;
	}

	for (; i < 32; i++)
		count += write(1, &buffer[i], 1);

	return (count);
}
