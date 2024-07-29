#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0;
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			printed_chars++;
		}
		else
		{
			++format;
			switch (*format)
			{
				case 'c': 
				{
					char c = va_arg(list, int);
					write(1, &c, 1);
					++printed_chars;
					break;
				}
				case 's':
                                {
					const char *str = va_arg(list, const char *);
					while (*str)
					{
						write(1, str++, 1);
						++printed_chars;
					}
					break;
                                }
				case '%':
                                {
					write(1, "%", 1);
					++printed_chars;
					break;
                                }
			}
		}
	}


	va_end(list);

	return (printed_chars);
}
