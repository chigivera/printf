#include "main.h"

/**
 * _hex - prints a number in base sixteen (lowercase)
 * @l: va_list args from _printf
 * @f: pointer to _printf determinant/dependent struct flags
 * Description: brings up conv() 
 * Return: Number of chars printed
 */
int _hex(va_list l, tr_flag *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = conv(num, 16, 1);
	int count = 0;

	if (f->pound == 1 && str[0] != '0')
		count += _puts("0x");
	count += _puts(str);
	return (count);
}

/**
 * big_hex - prints a number in base sixteen in uppercase
 * @l: va_list arguments from _printf
 * @f: pointer to_printf determinant/dependent struct
 * Description: the function calls conv()
 * Return: the number of chars printed
 */
int big_hex(va_list l, tr_flag *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = conv(num, 16, 0);
	int count = 0;

	if (f->pound == 1 && str[0] != '0')
		count += _puts("0X");
	count += _puts(str);
	return (count);
}

/**
 * print_binary - prints number in binary
 * @l: va_list args from _printf
 * @f: pointer to _printf determinant/deperndent struct
 * Description: calls conv() 
 * Return: the number of char printed
 */
int _binary(va_list l, tr_flag *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = conv(num, 2, 0);

	(void)f;
	return (_puts(str));
}

/**
 * _octal - prints number in base 8
 * @l: va_list args from _printf
 * @f: pointer to _printf determinant/deperndent struct
 * Description: this function calls conv()
 * Return: the number of char printed
 */
int _octal(va_list l, tr_flag *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = conv(num, 8, 0);
	int count = 0;

	if (f->pound == 1 && str[0] != '0')
		count += _putchar('0');
	count += _puts(str);
	return (count);
}
