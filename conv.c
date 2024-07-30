#include "main.h"

/**
 * convert - converts bases  numbers to str
 * @num: input num
 * @base: input base
 * @lowercase: flag if hexadecimal values need to be in small letters
 * Return: result str
 */
char *conv(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
