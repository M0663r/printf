#include "main.h"

/**
 * print_hex - Prints an unsigned int in hexadecimal
 * @num: Unsigned int to print
 * @uppercase: Flag indicating if the hex should be uppercase
 *
 * Return: Number of characters printed
 */
int print_hex(unsigned int num, int uppercase)
{
	int count = 0;
	char offset = uppercase ? 'A' - 10 : 'a' - 10;

	if (num / 16)
		count += print_hex(num / 16, uppercase);

	if ((num % 16) < 10)
		count += write(1, &"0123456789"[num % 16], 1);
	else
		count += write(1, &(char){offset + (num % 16)}, 1);

	return (count);
}
