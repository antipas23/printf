#include "main.h"

/**
 * printfPointer - prints an hexgecimal number.
 * @args: arguments.
 * Return: counter.
 */
int printfPointer(va_list args)
{
	void *p;
	char *s = "(nil)";
	long int a;
	int b;
	int i;

	p = va_arg(args, void*);
	if (p == NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			_putchar(s[i]);
		}
		return (i);
	}

	a = (unsigned long int)p;
	_putchar('0');
	_putchar('x');
	b = printfHexAux(a);
	return (b + 2);
}
