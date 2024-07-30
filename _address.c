#include "main.h"

/**
 * _address - address of input in base sixteen
 * @l: va_list args from _printf
 * @f: pointer to the _printf dependent/determinant struct flags 
 * Return: number of chars printed
 */
int _address(va_list l, tr_flag *f)
{
	char *str;
	unsigned long int p = va_arg(l, unsigned long int);

	register int count = 0;

	(void)f;

	if (!p)
		return (_puts("(nil)"));
	str = conv(p, 16, 1);
	count += _puts("0x");
	count += _puts(str);
	return (count);
}
