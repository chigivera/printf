#include "main.h"

/**
 * _str - loops through an str printing chars until break
 * @l: va_list arguments from _printf
 * @f: pointer to _printf determinant/dependent struct flags
 * Return: number of chars printed
 */
int _str(va_list l, tr_flag *f)
{
	char *s = va_arg(l, char *);

	(void)f;

	if (!s)
		s = "(null)";
	return (_puts(s));
}

/**
 * _char - prints a char
 * @l: va_list arguments from _printf
 * @f: pointer to _printf determinant/dependent struct flags
 * Return: number of chars printed
 */
int _char(va_list l, tr_flag *f)
{
	(void)f;
	_putchar(va_arg(l, int));
	return (1);
}
