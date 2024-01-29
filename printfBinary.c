#include "main.h"

/**
 * printfBin - prints a binary number.
 * @args: arguments.
 * Return: 1.
 */
int printfBin(va_list args)
{
	int flag = 0;
	int cont = 0;
	int i, a = 1, b;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int p;

	for (i = 0; i < 32; i++)
	{
		p = ((a << (31 - i)) & num);
		if (p >> (31 - i))
			flag = 1;
		if (flag)
		{
			b = p >> (31 - i);
			_putchar(b + 48);
			cont++;
		}
	}
	if (cont == 0)
	{
		cont++;
		_putchar('0');
	}
	return (cont);
}

/**
 * printfOct - prints an octal number.
 * @args: arguments.
 * Return: count.
 */
int printfOct(va_list args)
{
	int i;
	int *array;
	int count = 0;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = num;

	while (num / 8 != 0)
	{
		num /= 8;
		count++;
	}
	count++;
	array = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		array[i] = temp % 8;
		temp /= 8;
	}
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(array[i] + '0');
	}
	free(array);
	return (count);
}
