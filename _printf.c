#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: format str containign chars and specifiers
 * Description: this will call my_printr()
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, tr_flag *);
	const char *p;
	va_list arguments;
	tr_flag flags = {0, 0, 0};

	register int count = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (flag_on(*p, &flags))
				p++;
			pfunc = my_printr(*p);
			count += (pfunc)
				? pfunc(arguments, &flags)
				: _printf("%%%c", *p);
		} else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(arguments);
	return (count);

}
