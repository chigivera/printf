#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes char c to standard output
 * @c: char to be printed
 * Return: Succeful, 1. Oe -1 if not, with errno set appropriately.
 * Description: _putchar useslocal buffer of 1024 
 */
int _putchar(char c)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
	return (1);
}

/**
 * _puts - prints an str to standard output
 * @str: pointer to the str to be printed
 * Return: number of chars written
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
