#include "main.h"

/**
 * flag_on - activates flags if _printf finds flag modifiers 
 * @s: holds flag specifier
 * @f: pointer 
 *
 * Return: 1 if a flag active, otherwise 0
 */
int flag_on(char s, tr_flag *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->add = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->pound = 1;
			i = 1;
			break;
	}

	return (i);
}
