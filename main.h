#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>



/**
 * struct format - match the conversion specifiers for printf
 * @id: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @f: type pointer to function for the conversion specifier
 *
 */

typedef struct format
{
	char *id;
	int (*f)();
} match;

int _pointer(va_list val);
int _aux(unsigned long int num);
int _AUX(unsigned int num);
int _exclusive(va_list val);
int _HEX(va_list val);
int _hex(va_list val);
int _oct(va_list val);
int _unsigned(va_list args);
int _bin(va_list val);
int _srev(va_list args);
int _rot13(va_list args);
int _int(va_list args);
int _dec(va_list args);
int _strlen(char *s);
int *_strcpy(char *dest, char *src);
int _strlenc(const char *s);
int rev_string(char *s);
int _strlenc(const char *s);
int _37(void);
int _char(va_list val);
int _string(va_list val);
int _putchar(char c);
int _printf(const char *format, ...);

#endif
