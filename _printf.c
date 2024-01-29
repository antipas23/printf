#include "main.h"
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	int i = 0, j, len = 0;
	va_list args;
	convert_match m[] = {
		{"%s", printfString}, {"%c", printfChar},
		{"%%", printfpercent},
		{"%i", printfInt}, {"%d", printfDec}, {"%r", printfRev},
		{"%R", printfRot13}, {"%b", printfBin}, {"%u", printfUnsigned},
		{"%o", printfOct}, {"%x", printfHex}, {"%X", printfHEX},
		{"%S", printfExclusiveString}, {"%p", printfPointer}
	};

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
