#include "main.h"

/**
 * upcase_S - Non printable chars printed as \x followed
 * by ASCII value in hexa (upper case - always 2 characters)
 * @l: va_list arguments from _printf
 * @f: pointer to _printf determinant/dependent struct flags
 * Return: number of chars printed
 */
int upcase_S(va_list l, tr_flag *f)
{
	int i, count = 0;
	char *res;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		return (_puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_puts("\\x");
			count += 2;
			res = conv(s[i], 16, 0);
			if (!res[1])
				count += _putchar('0');
			count += _puts(res);
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
}

/**
 * _reverse - prints an str in reverse
 * @l: arg from _printf
 * @f: pointer to _printf determinant/dependent struct flags
 * Return: len of the printed str
 */
int _reverse(va_list l, tr_flag *f)
{
	int i = 0, j;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		s = "(null)";

	while (s[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		_putchar(s[j]);

	return (i);
}

/**
 * print_percent - prints percentage
 * @l: va_list args from _printf
 * @f: pointer to _printf determinant/dependent struct flags
 * Return: number of chars printed
 */
int _percent(va_list l, tr_flag *f)
{
	(void)l;
	(void)f;
	return (_putchar('%'));
}

/**
 * _rot13 - prints a string using rot13
 * @l: list of args from _printf
 * @f: pointer to _printf determinant/dependent struct flags
 * Return: len of the printed str
 */
int _rot13(va_list l, tr_flag *f)
{
        int i, j;
        char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
        char *s = va_arg(l, char *);

        (void)f;
        for (j = 0; s[j]; j++)
        {
                if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
                        _putchar(s[j]);
                else
                {
                        for (i = 0; i <= 52; i++)
                        {
                                if (s[j] == rot13[i])
                                        _putchar(ROT13[i]);
                        }
                }
        }

        return (j);
}
