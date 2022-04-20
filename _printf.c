#include "main.h"

/**
 * print_char - character
 * @a: agrument
 *
 * Return: 1
 */

int print_char(const va_list a)
{
	char c;

	c = va_arg(a, int);
	return (_putchar(c));
}
/**
 * print_string - string
 * @b: agrument
 * Return: length of char
 */

int print_string(const va_list b)
{
	char *r;
	int count = 0;

	r = va_arg(b, char*);
	if (r == NULL)
		return (0);
	while (*r != '\0')
	{
		_putchar(*r);
		r++;
		count++;
	}
	return (count);
}
/**
 * len - length of char
 * @s: char
 *
 * Return: length
 */
int len(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}

	return (i);
}

/**
 * print_modulo - print %
 * @list: int
 *
 * Return: 1
 */

int print_modulo(const va_list __attribute__((unused)) list)
{
	_putchar('%');
	return (1);
}
/**
 * _printf - function cahr and string
 * @format: format specifier
 * Description: function that print cahr and string
 * Return: char and string
 */
int _printf(const char *format, ...)
{
	char fmt[] = {'c', 's', '%', 'd', 'i', 'b'};
	va_list args;
	int i, j, count, flag;

	int (*fp[])(const va_list) = {print_char, print_string,
		print_modulo, print_n, print_n, print_b};

	va_start(args, format);
	i = j = count = flag = 0;
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			count++;
			_putchar(format[i]);
		}
		else
		{
			while (format[i + 1] != fmt[j] && j < 6)
				j++;
			if (j < 6)
			{
				flag = fp[j](args);
				if (flag == -1)
					return (-1);
				count = count + flag;
				i++;
			}
			else
				count = count + _putchar('%');
		}
		i++;
		j = 0;
	}
	va_end(args);
	return (count);
}
