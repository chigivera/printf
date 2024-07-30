#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - structure containing turn on flags
 * when a flag specifier is passed to _printf()
 * @add: flag for the '+' character
 * @space: flag for the ' ' character
 * @pound: flag for the '#' character
 */
typedef struct flags
{
	int add;
	int space;
	int pound;
} tr_flag;

/**
 * struct printer - structure to choose correct function
 * @c: format specifier
 * @f: pointer to the correct printing funct
 */
typedef struct printer
{
	char c;
	int (*f)(va_list ap, tr_flag *f);
} ph;

int _printf(const char *format, ...);
int (*my_printr(char s))(va_list, tr_flag *);

int flag_on(char s, tr_flag *f);

int _int(va_list l, tr_flag *f);
void _number(int n);
int _unsigned(va_list l, tr_flag *f);
int count_digit(int i);
int _hex(va_list l, tr_flag *f);
int big_hex(va_list l, tr_flag *f);
int _binary(va_list l, tr_flag *f);
int _octal(va_list l, tr_flag *f);

char *conv(unsigned long int num, int base, int lowercase);

int _str(va_list l, tr_flag *f);
int _char(va_list l, tr_flag *f);
int _putchar(char c);
int _puts(char *str);

int _address(va_list l, tr_flag *f);
int _percent(va_list l, tr_flag *f);
int _rot13(va_list l, tr_flag *f);
int _reverse(va_list l, tr_flag *f);
int upcase_S(va_list l, tr_flag *f);

#endif
