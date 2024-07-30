#include "main.h"

/**
 * my_printr - picks proper print function
 * @s: specifies conversions
 * func_arr[] matchmaker between the specifier, first struct_element & print_funct
 * Return: pointer 
 */
int (*my_printr(char s))(va_list, tr_flag *)
{
	ph func_arr[] = {
		{'s', _str},
		{'c', _char},
		{'%', _percent},
		{'d', _int},
		{'i', _int},
		{'b', _binary},	
		{'u', _unsigned},
		{'o', _octal},
		{'x', _hex},
		{'X', big_hex},
		{'r', _reverse},
		{'R', _rot13},
		{'S', upcase_S},
		{'p', _address}
		};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}
