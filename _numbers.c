#include "main.h"

/**
 * _int - prints an int...duh
 * @l: va_list of args from _printf
 * @f: pointer to _printf determinant/dependent struct flags
 * Return: number of chars printed
 */
int _int(va_list l, tr_flag *f)
{
	int n = va_arg(l, int);
	int res = count_digit(n);

	if (f->space == 1 && f->add == 0 && n >= 0)
		res += _putchar(' ');
	if (f->add == 1 && n >= 0)
		res += _putchar('+');
	if (n <= 0)
		res++;
	_number(n);
	return (res);
}

/**
 * _unsigned - prints an unsigned int
 * @l: va_list of arguments from _printf
 * @f: pointer to _printf determinant/dependent struct flags
 * Return: number of char printed
 */
int _unsigned(va_list l, tr_flag *f)
{
	unsigned int u = va_arg(l, unsigned int);
	char *str = conv(u, 10, 0);

	(void)f;
	return (_puts(str));
}

/**
 * _number - loops through an int, printing as it goes
 * @n: int to be printed
 */
void _number(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		_number(n1 / 10);
	_putchar((n1 % 10) + '0');
}

/**
 * _digit - returns len of digits in an int for _printf
 * @i: int 
 * Return: number of digits
 */
int count_digit(int i)
{
	unsigned int d = 0;
	unsigned int u;

	if (i < 0)
		u = i * -1;
	else
		u = i;
	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}
