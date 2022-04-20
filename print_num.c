#include "main.h"

/**
 * num_digits - get nunber of digits
 * @n: number
 *
 * Return: number of digits
 */
int num_digits(int n)
{
	int count;

	count = 1;
	while (n / 10 != 0)
	{
		count++;
		n = n / 10;
	}

	return (count);
}
/**
 * print_num - prints number
 * @n: number to be printed
 *
 */
void print_num(int n)
{
	if (n / 10 == 0)
	{
		if (n < 0)
		{
			_putchar((-1) * (n % 10) + '0');
		}
		else
		{
			_putchar((n % 10) + '0');
		}
	}
	else
	{
		print_num(n / 10);
		if (n < 0)
		{
			_putchar((-1) * (n % 10) + '0');
		}
		else
		{
			_putchar((n % 10) + '0');
		}
	}
}

/**
 * print_n - print and return number char printed
 * @ls: number printed
 *
 * Return: number of digits printed
 */
int print_n(const va_list ls)
{
	int n;
	int count;

	count = 0;
	n = va_arg(ls, int);
	if (n < 0)
	{
		_putchar('-');
		count++;
	}
	print_num(n);

	return (count + num_digits(n));
}
